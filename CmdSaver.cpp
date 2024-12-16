#include <fstream>
#include <iostream>

#include "CmdSaver.h"

void CmdSaver::Save(const vector<string>& commands)
{
    time_t first_cmd_time = chrono::system_clock::to_time_t(_markedTime);
    string filename = "bulk" + to_string(first_cmd_time) + ".log";

    ofstream outFile(filename, ios::binary);
    
    if (!outFile) 
    {
        cerr << "Error opening file for writing: " << filename << endl;
        cerr << "Error code: " << errno << endl;
        return;
    }

    size_t size = commands.size();
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));
    
    for (const string& str : commands)
    {
        size_t length = str.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));        
        outFile.write(str.c_str(), length);
    }
    
    outFile.close();
};

void CmdSaver::MarkTime()
{
	_markedTime = chrono::system_clock::now();
}
