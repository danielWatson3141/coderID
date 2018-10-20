#include <bits/stdc++.h>
using namespace std;
#define TR(i,v) 		for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x) 		cout << #x << " = "; cout << x << endl;
#define SIZE(p) 		(int)(p).size()
#define MP(a, b)		make_pair((a), (b))
#define ALL(p)			(p).begin(), (p).end()
#define rep(i, n)		for(int (i)=0; (i)<(int)(n); ++(i))
#define REP(i, a, n)	for(int (i)=(a); (i)<(int)(n); ++(i))
#define FOR(i, a, b)   	for(int (i)=(int)(a); (i)<=(int)(b); ++(i))
#define FORD(i, b, a)  	for(int (i)=(int)(b); (i)>=(int)(a); --(i)) 
typedef long long LL;
typedef pair<int, int> pii;
int s[1005];
inline int getsum(int x)
{
	int r=0;
	for(; x; x-=x&-x)	r+=s[x];
	return r; 
}
int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);	
    freopen("out", "w", stdout);
    #endif
	// ios::sync_with_stdio(false);    cin.tie(0);
	int T;		scanf("%d", &T);
	FOR(cs, 1, T)
	{
		printf("Case #%d: ", cs);
		int n;	scanf("%d", &n);
		memset(s, 0, sizeof(s));
		int r=0;
		FOR(i, 1, n) {
			int t;		scanf("%d", &t);	++t;
			r += getsum(n)-getsum(t);
			for(int x=t; x<=n; x+=x&-x)
				++s[x];
		}
		double R = n*(n-1)/4.0;
		double eps = 0.01*(n*(n-1)/2);
		if(abs(R-r) <= eps)
			puts("GOOD");
		else
			puts("BAD");
	}
	return 0;
}