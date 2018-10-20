#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

#define HP 13331
#define INF 1000000000
#define maxn 410

int splug[maxn][maxn], sdev[maxn][maxn];

int n,m;

ULL calc(int *a, int len)
{
	ULL ret=0;
	rep(i,1,len) ret=ret*HP+a[i];
	return ret;
}

int final;

void solve(int curans, int k)
{
	if (k>m) { final=min(final,curans); return; }
	map<ULL,int> cnt;
	rep(i,1,n) cnt[calc(splug[i],k)]++;
	rep(i,1,n) cnt[calc(sdev[i],k)]--;
	
	int flag=1;
	rept(it,cnt) if (it->second!=0) { flag=0; break; }
	if (flag) solve(curans,k+1);
	
	cnt.clear();
	rep(i,1,n) splug[i][k]=1-splug[i][k];
	rep(i,1,n) cnt[calc(splug[i],k)]++;
	rep(i,1,n) cnt[calc(sdev[i],k)]--;
	
	flag=1;
	rept(it,cnt) if (it->second!=0) { flag=0; break; }
	if (flag) solve(curans+1,k+1);
	
	rep(i,1,n) splug[i][k]=1-splug[i][k];
}

char buf[maxn];

void lemon()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n) 
	{
		scanf("%s",buf+1);
		rep(k,1,m) splug[i][k]=buf[k]-'0';
	}
	rep(i,1,n)
	{
		scanf("%s",buf+1);
		rep(k,1,m) sdev[i][k]=buf[k]-'0';
	}
	
	final=INF;
	solve(0,1);
	if (final==INF) printf("NOT POSSIBLE\n"); else printf("%d\n",final);
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

