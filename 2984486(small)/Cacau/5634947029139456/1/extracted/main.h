#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <hash_set>

using namespace std;

typedef struct {
	int numOutlets, flowLength;
	vector<string> outlets;
	vector<string> devices;
}input;

int main(int argc, char* argv[]);

string solve(input &inElem);

int checkForSolution(vector<string> &devs, vector<string> &outs);

int diffStr(string &str1, string &str2);

void readInputs(string inputfile, vector<input> &inputs);

void writeSolution(vector<input> &inputs);