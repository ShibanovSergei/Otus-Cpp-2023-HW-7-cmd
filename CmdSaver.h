#include <string>
#include <vector>
#include <chrono>

using namespace std;

class CmdSaver
{
  public:
	void MarkTime();
	void Save(const vector<string>& commands);

private:
	chrono::system_clock::time_point _markedTime;
};