#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;
int main(int argc, char* argv[])
{
	const long long INF = 98765432123456789LL;
	string inputFileName = "A-small-attempt1.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, N, L;
	long long outlet[2][150];
	char buf[64];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> N >> L;
		//cout << N << ' ' << L << endl;
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				input >> buf;
				//cout << buf << ' ';
				long long & val = outlet[j][k];
				val = 0;
				for (int l = 0; l < L; ++l)
				{
					val = (val << 1) + (buf[l] == '1');
				}
			}
			cout << endl;
		}
		sort(outlet[1], outlet[1] + N);
		long long ret = INF;
		for (long long bf = (1LL << L) - 1; ret && bf >= 0; --bf)
		{
			for (int j = 0; j < N; ++j)
			{
				outlet[0][j] ^= bf;
			}
			sort(outlet[0], outlet[0] + N);
			bool search = true;
			for (int j = 0; j < N && (search = (outlet[0][j] == outlet[1][j])); ++j);
			if (search)
			{
				long long cnt = 0, tmp = bf;
				while (tmp)
				{
					++cnt;
					tmp = tmp & (tmp - 1);
				}
				ret = min(ret, cnt);
			}
			for (int j = 0; j < N; ++j)
			{
				outlet[0][j] ^= bf;
			}
		}

		output << "Case #" << i << ": ";
		if (ret == INF) output << "NOT POSSIBLE";
		else output << ret;
		output << endl;
	}

	output.close();
	input.close();

	system("pause");
	return 0;
}
