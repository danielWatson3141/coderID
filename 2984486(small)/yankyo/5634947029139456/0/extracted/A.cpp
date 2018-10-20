
#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

const int MAX = 150;

struct conf
{
	int flipc;
	int64_t flips;
};

bool operator < (const conf& a, const conf &b)
{
	return a.flipc < b.flipc;
}

bool operator == (const conf &a, const conf &b)
{
	return (a.flipc == b.flipc) && (a.flips == b.flipc);
}

conf devconf[MAX * MAX];

conf getconf(string &dev, string &out)
{
	conf res;
	res.flipc = 0;
	res.flips = 0;
	
	int i = 0;
	while (dev[i])
	{
		if (dev[i] != out[i])
		{
			res.flipc++;
			res.flips = res.flips * 2 + 1;
		} else
		{
			res.flips = res.flips * 2;
		}

		i++;
	}

	return res;
}

bool allhave(conf* c, int N, int64_t s)
{
	for (int i = 1; i < N; i++)
	{
		bool have = false;
		for (int j = 0; j < N; j++)
		{
			if (c[i*MAX + j].flips == s)
			{
				have = true;
				break;
			}
		}

		if (!have)
		{
			//cout << "NOT have: " << i << endl;
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	cin >> T;

	int N, L;
	conf devconf[MAX * MAX];
	string devs[MAX];
	string outs[MAX];

	for (int t = 0; t < T; t++)
	{
		int N, L;
		cin >> N >> L;

		for (int i = 0; i < N; i++) cin >> devs[i];
		for (int i = 0; i < N; i++) cin >> outs[i];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				devconf[i * MAX + j] = getconf(devs[i], outs[j]);
				//cout << devs[i] << " -> " << outs[j] << ": " << devconf[i * MAX + j].flipc << " (" << devconf[i * MAX + j].flips << ")" << endl;
			}
			sort(devconf + i * MAX, devconf + (i*MAX) + N);
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//cout << devconf[i * MAX + j].flipc << " (" << devconf[i * MAX + j].flips << ")" << endl;
			}
		}

		cout << "Case #" << (t + 1) << ": ";

		bool done = false;
		for (int f = 0; f <= L; f++)
		{
			for (int i = 0; i < N; i++)
			{
				if (devconf[i].flipc == f)
				{
					//cout << endl << "testing for " << f << " and " << devconf[i].flips << " ";
					if (allhave(devconf, N, devconf[i].flips))
					{
						done = true;
						cout << f << endl;
						break;
					}
				}
			}

			if (done) break;
		}

		if (!done) cout << "NOT POSSIBLE" << endl;

	}

	return 0;
}

