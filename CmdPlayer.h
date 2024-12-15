#include <vector>
#include <string>

#include "CmdHandler.h"

class CmdPlayer
{
  public:
	  CmdPlayer(CmdHandler* cmdHandler);
	  void PlayCommands(std::vector<std::string> commands);

  private:
	  CmdHandler* _cmdHandler;
};