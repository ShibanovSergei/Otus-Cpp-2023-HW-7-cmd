#include <fstream>
#include <iostream>

#include "CmdSaver.h"

void CmdSaver::Save(const vector<string>& commands)
{
    std::time_t first_cmd_time = std::chrono::system_clock::to_time_t(_markedTime);
    std::string filename = std::to_string(first_cmd_time) + ".log";

    std::ofstream outFile(filename, std::ios::binary);
    
    if (!outFile) 
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    size_t size = commands.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const std::string& str : commands)
    {
        size_t length = str.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));        
        outFile.write(str.c_str(), length);
    }
    
    outFile.close();
};

void CmdSaver::MarkTime()
{
	_markedTime = std::chrono::system_clock::now();
}
