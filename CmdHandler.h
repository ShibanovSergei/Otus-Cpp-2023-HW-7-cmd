#pragma once

#include <cstdint>
#include <string>

#include "CmdSaver.h"

using namespace std;

const string EndMarker = "EOF";
const char B = '{';
const char E = '}';
const string StrForEmpty = "--- empty ---";


class CmdHandler
{
public:
	explicit CmdHandler(uint8_t blockSize, ostream& outStream = std::cout);
	explicit CmdHandler(uint8_t blockSize, CmdSaver saver, ostream& outStream = std::cout);
	void HandleCommand(string command);	

private:
	uint8_t _blockSize;	// Number of commands mak ing up a block.
	uint8_t dynamic_block_level = 0;
	vector<string> _commands;
	CmdSaver _saver;
	ostream& _outStream;

	void OutAccumulatedCommands();
	void OutputToStream(const vector<string>& commands);
};