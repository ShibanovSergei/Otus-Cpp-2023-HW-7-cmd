#include "main.h"
#include "CmdHandler.h"
#include "CmdPlayer.h"
#include "CmdSets.h"


using namespace std;

int main(int argc, char* argv[])
{
	uint8_t n;
	if (argc > 1)
	{
		n = stoi(argv[1]); // to do: add check.		
	}
	else
	{
		cout << "There is no parameter specifying the size of the command block. The default value of 3 will be used." << endl;
		n = 3;
	}

	CmdHandler cmdHandler(n);
    CmdPlayer  cmdPlayer(&cmdHandler);

    cmdPlayer.PlayCommands(demoSet);
	
	return 0;
}
