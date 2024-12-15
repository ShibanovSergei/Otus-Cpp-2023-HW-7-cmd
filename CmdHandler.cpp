#include <iostream>
#include <stdexcept>

#include "CmdHandler.h"


CmdHandler::CmdHandler(uint8_t blockSize, ostream& outStream): _outStream(outStream)
{
	_blockSize = blockSize;
}

CmdHandler::CmdHandler(uint8_t blockSize, CmdSaver saver, ostream& outStream): _saver(saver), _outStream(outStream)
{
	_blockSize = blockSize;
}

void CmdHandler::HandleCommand(string command)
{
	if (!command.length())
		return;

	if (command == EndMarker && dynamic_block_level == 0)
	{
		OutAccumulatedCommands();
		return;
	}

	switch (command[0])
	{
		case B: // Start of dynamic block.
			if (dynamic_block_level == 0)
			{
				_saver.MarkTime();
				if (!_commands.empty())
				{
					OutAccumulatedCommands();
				}
			}

			dynamic_block_level++;
			break;

		case E: // End for dynamic block.
			if (dynamic_block_level <= 0)
			{
				throw runtime_error("Error: closure without according opening.");
			}

			if (dynamic_block_level > 0)
			{
				dynamic_block_level--;
			}

			if (!_commands.empty() && dynamic_block_level == 0)
			{
				OutAccumulatedCommands();
			}
			break;

		default:
			if (_commands.empty())
			{
				_saver.MarkTime();
			}
			_commands.push_back(command);			
			break;
	}

	// Checking for completion of a command block.
	if ((_commands.size() % _blockSize == 0) && !_commands.empty() && dynamic_block_level == 0)
	{
		OutAccumulatedCommands();
	}
}

void CmdHandler::OutAccumulatedCommands()
{
	// We can reduce the connectivity using the observer pattern. 
	// But since this is not explicitly required in the task, it was done according to the KISS principle.
	OutputToStream(_commands);
	_saver.Save(_commands);

	_commands.clear();
}

void CmdHandler::OutputToStream(const vector<string>& commands)
{
	cout << "bulk: ";
	if (!commands.empty())
	{
		auto penultimate_it = std::prev(commands.end());
		for (auto it = commands.begin(); it != penultimate_it; ++it)
		{
			_outStream << *it << ", ";
		}
		_outStream << *penultimate_it << endl;
	}
	else
		_outStream << StrForEmpty << endl;
}
