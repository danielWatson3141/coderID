#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define MAXN 155
#define MYINF 1000000000

using namespace std;

static string s[MAXN];
static string f[MAXN];
static string t[MAXN];
int N, L;
int res;
static char b[MAXN];

int main ()
{
	std::ios_base::sync_with_stdio(false);
	int T, iT;
	cin >> T;
	for (iT = 0; iT < T; iT++)
	{
		cin >> N >> L;
		int i, j, q;
		for (i = 0; i < N; i++) cin >> s[i];
		for (i = 0; i < N; i++) cin >> f[i];
		sort(f, f+N);
		res = MYINF;
		for (q = 0; q < N; q++)
		{
			int cnt = 0;
			for (j = 0; j < L; j++)
			{
				if (s[0][j] == f[q][j]) b[j] = 0;
				else
				{
					b[j] = 1;
					cnt++;
				}
			}
			if (cnt < res)
			{
				for (i = 0; i < N; i++) t[i] = s[i];
				for (i = 0; i < N; i++)
				{
					for (j = 0; j < L; j++)
					{
						if (b[j])
						{
							if (t[i][j] == '0') t[i][j] = '1';
							else t[i][j] = '0';
						}
					}
				}
				sort(t, t+N);
				i = 0;
				while ((i < N) && (t[i] == f[i])) i++;
				if (i == N) res = cnt;
			}
		}
		cout << "Case #" << (iT+1) << ": ";
		if (res == MYINF) cout << "NOT POSSIBLE\n";
		else cout << res << "\n";
	}
	return 0;
}
