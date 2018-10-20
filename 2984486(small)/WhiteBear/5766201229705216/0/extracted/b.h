#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>
using namespace std;
#pragma comment(linker, "/STACK:255000000")

typedef long long ll;

#define rep(i, a, b) for(i = (a); i < (b); ++i)
#define repb(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define repd(i, a, b, d) for(i = (a); i < (b); i += (d))
#define repbd(i, a, b, d) for(i = (a) - 1; i >= (b); i -= (d))
#define reps(i, s) for(i = 0; (s)[i]; ++i)
#define repl(i, l) for(i = l.begin(); i != l.end(); ++i)

#define in(f, a) scanf("%"#f, &(a))

bool firstout = 1;

#define out(f, a) printf("%"#f, (a))
#define outf(f, a) printf((firstout) ? "%"#f : " %"#f, (a)), firstout = 0
#define nl printf("\n"), firstout = 1

#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x) * (x))
#define mp make_pair

template<class T>
T &minn(T &a, T b)
{
	if(b < a) a = b;
	return a;
}

template<class T>
T &maxx(T &a, T b)
{
	if(a < b) a = b;
	return a;
}

#define inf 1012345678
#define eps 1e-9


#ifdef XDEBUG
#define mod 23
#else
#define mod 1000000007
#endif

int &madd(int &a, int b)
{
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int &msub(int &a, int b)
{
	a -= b;
	if(a < 0) a += mod;
	return a;
}

int &mmult(int &a, int b)
{
	return a = (ll)a * b % mod;
}

int mdiv(ll a, ll b, ll m)
{
	a = (a % m + m) % m;
	b = (b % m + m) % m;
	if(a % b == 0) return a / b;
	return (a + m * mdiv(-a, m, b)) / b;
}

#define N 1012
#define M 1012

int n, m, q;
vector<int> A[N];

int dfs(int i, int p = -1)
{
	int r, rr;
	r = rr = -1;
	int j, k;
	rep(k, 0, A[i].size())
	{
		j = A[i][k];
		if(j == p) continue;
		int a = dfs(j, i);
		if(a > r) rr = r, r = a;
		else if(a > rr) rr = a;
	}
	if(rr >= 0) return 1 + r + rr;
	else return 1;
}

int main()
{
#ifdef XDEBUG
	freopen("in.txt", "rt", stdin);
#else
	freopen("b.in", "rt", stdin);
	freopen("b.out", "wt", stdout);
#endif

	int i, j, k;
	char c;
	int a, d;
	
	int ts;	
#if 1
	int tss;
	in(d, tss);
	rep(ts, 1, tss + 1)
#else
	for(ts = 1; in(d, n) > 0; ++ts)
#endif
	{
		printf("Case #%d: ", ts);
#ifndef XDEBUG
		cerr << ts << endl;		
#endif
		in(d, n);
		rep(i, 0, n) A[i].clear();
		rep(k, 0, n - 1)
		{
			in(d, i); in(d, j);
			--i; --j;
			A[i].push_back(j);
			A[j].push_back(i);
		}
		int res = 0;
		rep(i, 0, n) maxx(res, dfs(i));
		out(d, n - res); nl;
	}

	return 0;
}
