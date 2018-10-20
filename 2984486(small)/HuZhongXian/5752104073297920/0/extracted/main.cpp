#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;
int num[1001];
int main(int argc, char* argv[])
{
	string inputFileName = "C-small-attempt1.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	srand(time(0));
	int T, N;
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> N;
		int cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			input >> num[i];
			cnt += (num[i] == i);
		}
		output << "Case #" << i << ": ";
		if ((rand() % rand() + cnt) % 2) output << "GOOD";
		else output << "BAD";
		output << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
