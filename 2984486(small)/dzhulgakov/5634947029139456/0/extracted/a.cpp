#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>
#include <cstring>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 256
int n,len;
vector<LL> a,b;

LL read() {
	char c;
	LL res = 0;
	REP(i,len)
	{
		do c = getc(stdin);
		while (c!='0'&&c!='1');
		if (c=='1') res|=1LL<<i;
	}
	return res;
}

/*int solve(int k, vector<LL> a, vector<LL> b)
{
	if (k == 0) return 0;
	vector<LL> a1,a2;
	vector<LL> b1,b2;
	REP(i,SZ(a))
		if (a[i]&1)
			a1.pb(a[i]>>1);
		else
			a2.pb(a[i]>>1);
	REP(i,SZ(b))
		if (b[i]&1)
			b1.pb(b[i]>>1);
		else
			b2.pb(b[i]>>1);
	int res = INF;
	if (SZ(a1) == SZ(b1))
	{
		int r = min(solve(k-1, a1));
	}
}

bool check(LL mask)
{
	vector<LL> q,w;
	q = a;
	REP(i,n) w.pb(b[i]^mask);
	if ()
}*/

int main(int argc, char **argv)
{
	string FN = "A-small-attempt0";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%d",&n,&len);
		a.resize(n);
		b.resize(n);
		REP(i,n) a[i]=read();
		REP(i,n) b[i]=read();
		int r = INF;
		REP(i,n)
		{
			LL mask = a[0]^b[i];
			vector<LL> q = a, w;
			REP(j,n)
				w.pb(b[j]^mask);
			SORT(w);
			SORT(q);
			if (q==w)
			{
				int cnt = 0;
				for (; mask; mask&=mask-1)
					++cnt;
				r = min(r,cnt);
			}
		}
		if (r == INF)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", r);
		//int r = solve(len,a,b);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}