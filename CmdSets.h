#include <vector>
#include <string>

using namespace std;

vector<string> testSet_01 = { "EOF" };
vector<string> testSet_02 = { "cmd_1", "cmd_2", "EOF"};
vector<string> testSet_03 = { "cmd_1", "cmd_2","cmd_3", "EOF" };
vector<string> testSet_04 = { "cmd_1", "cmd_2","cmd_3", "cmd_4","cmd_5", "EOF" };

vector<string> testSet_05 = { "cmd_1", "cmd_2", "{", "cmd_3", "cmd_4", "}"};
vector<string> demoSet = { "cmd_1", "cmd_2", "{", "cmd_3", "cmd_4", "}", "{", "cmd_5", "cmd_6", "{", "cmd_7", "cmd_8", "}", "cmd_9", "}", "{", "cmd_10", "cmd_11", "EOF" };
