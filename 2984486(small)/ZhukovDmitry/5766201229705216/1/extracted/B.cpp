#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef long long i64;
typedef __int128 i128;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

#define x first
#define y second

int qq;
int n;
VI a[1024];
PII d[1024][1024];

bool cmp(PII p1, PII p2)
{
	return p1.y - p1.x < p2.y - p2.x;
}

PII go(int x, int y)
{
	PII &ans = d[x][y];
	if (ans.x >= 0) return ans;
	ans = mp(1, 0);

	PII c[a[y].sz];
	int k = 0;

	forn(i, a[y].sz)
	{
		int vn = a[y][i];
		if (vn == x) continue;
		c[k++] = go(y, vn);
	}
	forn(i, k)
	{
		ans.x += c[i].x;
	}
	if (k < 2)
	{
		forn(i, k)
		{
			ans.y += c[i].x;
		}
	}
	else
	{
		sort(c, c + k, cmp);
		forn(i, 2)
		{
			ans.y += c[i].y;
		}
		For(i, 2, k - 1)
		{
			ans.y += c[i].x;
		}
	}

	return ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d", &n);
		forn(i, n)
		{
			a[i].clear();
		}
		
		forn(i, n - 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--;
			y--;
			a[x].pb(y);
			a[y].pb(x);
		}

		int ans = n - 1;
		memset(d, 0xff, sizeof(d));

		forn(i, n)
		{
			PII c[a[i].sz];
			int k = 0;

			forn(j, a[i].sz)
			{
				c[k++] = go(i, a[i][j]);
//				cerr << i + 1 << " -> " << a[i][j] + 1 << " : " << c[k - 1].x << " " << c[k - 1].y << endl;
//				cerr << c[k - 1] << " ";
			}
//			cerr << endl;
			int tmp = 0;

			if (k < 2)
			{
				forn(i, k)
				{
					tmp += c[i].x;
				}
			}
			else
			{
				sort(c, c + k, cmp);
				forn(i, 2)
				{
					tmp += c[i].y;
				}
				For(i, 2, k - 1)
				{
					tmp += c[i].x;
				}
			}
//			cerr << "i = " << i + 1 << endl;
//			cerr << "tmp = " << tmp << endl;
			if (tmp < ans) ans = tmp;
		}
//		cerr << go(0, 1) << endl;

		printf("%d\n", ans);

		fflush(stdout);
	}

	return 0;
}
