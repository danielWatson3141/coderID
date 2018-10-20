#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1 * 1000 + 10;

ll a[MAXN], b[MAXN];
char t[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int o = 1; o <= tc; o ++)
	{
		int n, l;
		cin >> n >> l;

		for (int i = 0; i < l; i ++) t[i] = ' ';
		CLR(a, 0); CLR(b, 0);

		for (int i = 0; i < n; i ++) 
		{
			cin >> t;
			for (int j = 0; j < l; j ++)
				if (t[j] == '1')
					a[i] += (1 << (l - j - 1));
		}
		for (int i = 0; i < n; i ++)
		{
			cin >> t;
			for (int j = 0; j < l; j ++)
				if (t[j] == '1')
					b[i] += (1 << (l - j - 1));
		}

		int ans = 100;
		for (int i = 0; i < n; i ++)
		{
			ll mask = b[0] ^ a[i], cnt = 0;

			for (int j = 0; j < n; j ++)
				for (int k = 0; k < n; k ++)
				{
					ll tmp = a[k] ^ mask;
					if (b[j] == tmp)
					{
						cnt ++;
						break;
					}
				}
			if (cnt == n) ans = min(ans, __builtin_popcount(mask));
		}

		cout << "Case #" << o << ": ";
		if (ans == 100) cout << "NOT POSSIBLE\n";
		else cout << ans << endl;
	}
	return 0;
}

