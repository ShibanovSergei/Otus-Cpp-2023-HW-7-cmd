#include <iostream>
#include <chrono>
#include <thread>

#include "CmdPlayer.h"

CmdPlayer::CmdPlayer(CmdHandler* cmdHandler)
{
	_cmdHandler = cmdHandler;
}

void CmdPlayer::PlayCommands(std::vector<std::string> commands)
{
	if (commands.empty())
	{
		return;
	}

	for (auto it = commands.begin(); it != commands.end(); ++it)
	{
		string command = *it;

		cout << ">>: " << command << endl;
		_cmdHandler->HandleCommand(command);

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}