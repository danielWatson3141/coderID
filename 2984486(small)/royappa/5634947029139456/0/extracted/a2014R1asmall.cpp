#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N, L;

		cin >> N >> L;
		vector<string> vout, vdev;
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			vout.push_back(s);
		}
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			vdev.push_back(s);
		}
		sort(vdev.begin(), vdev.end());
		// try flipping every subset
		int best = MAXVAL;
		for (int m = 0; m < (1<<L); m++)
		{
			vector<string> vout2 = vout;
			for (int i = 0; i < N; i++)
			{
				for (int b = 0; b < L; b++)
				{
					if ((m&(1<<b)) == 0) continue;
					vout2[i][b] = '0'+(1-(vout2[i][b]-'0'));
				}
			}
			sort(vout2.begin(), vout2.end());
			if (vout2 == vdev)
			{
				best = min(best, __builtin_popcount(m));
			}
		}
		if (best == MAXVAL)
		{
			printf("Case #%d: NOT POSSIBLE\n", testCase);
		}
		else
		{
			printf("Case #%d: %d\n", testCase, best);
		}
	}
	return 0;
}
