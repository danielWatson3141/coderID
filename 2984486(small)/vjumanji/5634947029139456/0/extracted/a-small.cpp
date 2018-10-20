// directives 
	#include <stdio.h>
	#include <vector>
	#include <map>
	#include <set>
	#include <deque>
	#include <queue>
	#include <algorithm>
	#include <iostream>
	#include <cmath>
	#include <cstring>
	#include <typeinfo>
// 
using namespace std;
// macros 
	#define FOR(i,a,b)      for(int i(a);i<b;++i)
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define REP(i,n)        FOR(i,0,n)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
// 

typedef long long LL;
typedef vector<int> vi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }

int out[10], req[10], po[1<<10];
bool possible (int mask, int n)
{
	REP(i,n) out[i] ^= mask;
	sort(out, out+n);
	bool p = true;
	REP(i,n) if (out[i] != req[i]) {
		p = false;
		break;
	}
	REP(i,n) out[i] ^= mask;
	return p;
}

int toInt(string s)
{
	int c = 0, n = sz(s);
	FORD(i,n,0) c += (1<<(n-i-1))*(s[i]-'0');
	return c;
}
int bitcount(int n)
{
	int i=0;
	while (n) n = n&(n-1), ++i;
	return i;
}

int main()
{
	int t = rint();
	REP(T,t)
	{
		int n = rint();
		int l = rint();
		CL(out, 0);
		CL(req, 0);
		REP(i,n) {
			string s = rstring();
			out[i] = toInt(s);
		}
		REP(i,n) {
			string s = rstring();
			req[i] = toInt(s);
		}
		sort(req, req+n);
		printf("Case #%d: ", T+1);
		int c = 0;
		REP(i,1<<l) if (possible(i,n)) {
			po[c++] = bitcount(i);
		}
		if (c) {
			int mini = po[0];
			FOR(k,1,c) mini = min(mini, po[k]);
			printf("%d\n", mini);
		}
		else printf("NOT POSSIBLE\n");
	}
	return 0;
}
