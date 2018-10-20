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
int n;
int a[1024][1024];

void precalc(int n)
{
	int cnt = 10000000;
	int a[n];
	int c[n][n];
	clr(c);

	forn(l, cnt)
	{
		forn(i, n)
		{
			a[i] = i;
		}
		forn(i, n)
		{
			swap(a[i], a[rand() % n]);
		}
		forn(i, n)
		{
			c[i][a[i]]++;
		}
	}
	forn(i, n)
	{
		forn(j, n)
		{
			printf("%d ", c[i][j]);
		}
		puts("");
	}
}

ld f(int *a)
{
	ld sum = 0.0;
	ld n2 = (n - 1) * 0.5;
	forn(i, n - 1)
	{
		ld z = fmod(i + 1 + n2, n);
//		ld z = 12.5;
		ld tmp = a[i] - z;
		if (tmp < -n2) tmp += n;
		if (tmp > n2) tmp -= n;
		sum += tmp;
	}
	return sum;
}

void gen()
{
	srand(457247);
	qq = 120;
	n = 1000;
	printf("%d\n", qq);
	forn(ii, qq)
	{
		printf("%d\n", n);
		forn(i, n)
		{
			a[ii][i] = i;
		}
		forn(i, n)
		{
			int y = (ii & 1) ? (i + rand() % (n - i)) : rand() % n;
			swap(a[ii][i], a[ii][y]);
		}
		forn(i, n)
		{
			printf("%d%c", a[ii][i], " \n"[i == n - 1]);
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

//	precalc(10);

//	gen();

	scanf("%d", &qq);
	ld avg = 0.0;
//	ld avg = 251869263.408333331;
	forn(ii, qq)
	{
		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%d", &a[ii][i]);
		}
		ld sum = f(a[ii]);

//		printf("%lld\n", sum);
		avg += sum;
	}
	avg /= qq;
//	printf("avg = %0.9lf\n", (double)avg);
//	fprintf(stderr, "avg = %0.9lf\n", (double)avg);

	int cnt = 0;
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		ld sum = f(a[ii]);
//		printf("%0.9lf\n", (double)fabs(avg - sum));
//		printf("%0.9lf\n", (double)sum);
		bool good = sum > avg;
		puts(good ? "GOOD" : "BAD");
		cnt += good == (ii % 2 == 1);
		fflush(stdout);
	}
//	cerr << "cnt = " << cnt << endl;

	return 0;
}
