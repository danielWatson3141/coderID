#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;
bool edge[32][32];
int main(int argc, char* argv[])
{
	string inputFileName = "B-small-attempt1.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, N, X, Y;
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		input >> N;
		memset(edge, false, sizeof(edge));
		int v1 = 0;
		for (int j = 0; j + 1 < N; ++j)
		{
			input >> X >> Y;
			edge[X - 1][Y - 1] = edge[Y - 1][X - 1] = true;
			v1 = (v1 | (1 << (X - 1)));
			v1 = (v1 | (1 << (Y - 1)));
		}
		int ret = N - 1;
		for (int j = (1 << N) - 1; j >= 0; --j)
		{
			bool search = true;
			for (int k = 0; search && k < N; ++k)
			{
				if (j & (1 << k)) continue;
				int v2 = 0;
				for (int l = 0; l < N; ++l)
				{
					if (j & (1 << l))
					{
						v2 = ((v2 | (1 << l)));
					}
				}
				bool valid = true;
				queue<int> q;
				q.push(k);
				while (valid && !q.empty())
				{
					int r = q.front();
					q.pop();
					if (!((v2 & (1 << r))))
					{
						v2 = (v2 | (1 << r));
						int ccnt = 0;
						for (int l = 0; l < N; ++l)
						{
							if (edge[r][l] && !((v2 & (1 << l))))
							{
								++ccnt;
								q.push(l);
							}
						}
						valid = (ccnt == 0 || ccnt == 2);
					}
				}
				if (valid && v1 == v2)
				{
					search = false;
				}
			}
			if (!search)
			{
				int cnt = 0, tmp = j;
				while (tmp)
				{
					tmp = tmp & (tmp - 1);
					++cnt;
				}
				ret = min(ret, cnt);
			}
		}

		output << "Case #" << i << ": " << ret << endl;
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
