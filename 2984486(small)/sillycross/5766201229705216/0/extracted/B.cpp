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

#define maxn 1010

vector<int> e[maxn];

int cmp(const int &a, const int &b)
{
	return a>b;
}

int solve(int cur, int pre)
{
	vector<int> s;
	rept(it,e[cur]) if (*it!=pre) s.push_back(solve(*it,cur));
	if (s.size()<2) return 1;
	sort(s.begin(),s.end(),cmp);
	return s[0]+s[1]+1;
}

void lemon()
{
	int n; scanf("%d",&n);
	rep(i,1,n) e[i].clear();
	rep(i,1,n-1)
	{
		int x,y; scanf("%d%d",&x,&y);
		e[x].push_back(y); e[y].push_back(x);
	}
	int final=0;
	rep(i,1,n) final=max(final,solve(i,0));
	printf("%d\n",n-final);
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("B.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}

