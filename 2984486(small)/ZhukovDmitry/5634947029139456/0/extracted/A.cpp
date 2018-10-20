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

int qq;
int n, m;
char a[202][202];
char b[202][202];
int c[202];

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
		
		scanf("%d%d", &n, &m);
		forn(i, n)
		{
			scanf("%s", a[i]);
		}
		forn(i, n)
		{
			scanf("%s", b[i]);
		}
		int ans = m + 1;
		forn(i, n)
		{
			forn(j, n)
			{
				int cnt = 0;
				map < i64, int > am, bm;
				forn(k, m)
				{
					c[k] = a[i][k] != b[j][k];
					cnt += c[k];
				}
				if (cnt < ans)
				{
					forn(l, n)
					{
						i64 x = 0, y = 0;
						forn(k, m)
						{
							x |= ((i64)(a[l][k] - '0')) << k;
							y |= ((i64)((b[l][k] - '0') ^ c[k])) << k;
						}
						am[x]++;
						bm[y]++;
					}
					if (am == bm) ans = cnt;
				}
			}
		}
		if (ans > m)
		{
			puts("NOT POSSIBLE");
		}
		else
		{
			printf("%d\n", ans);
		}
		
		fflush(stdout);
	}

	return 0;
}
