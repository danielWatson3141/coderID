#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=1010;

int n;
vector<int> v[MaxN];
int F[MaxN];

int solve(int x,int p)
{
	F[x]=1;
	vector<int> d;
	for (auto y : v[x])
	{
		if (y==p) continue;
		solve(y,x);
		d.push_back(F[y]);
	}
	if (d.size()>=2)
	{
		sort(d.begin(),d.end());
		reverse(d.begin(),d.end());
		F[x]+=d[0]+d[1];
	}
	return F[x];
}

int main()
{
	freopen("try.in","r",stdin);
	freopen("try.out","w",stdout);
	int T;
	cin>>T;
	for (int TT=1;TT<=T;++TT)
	{
		printf("Case #%d: ",TT);
		cin>>n;
		for (int i=1;i<=n;++i)
			v[i].clear();
		for (int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int ans=0;
		for (int i=1;i<=n;++i)
			ans=max(ans,solve(i,0));
		cout<<n-ans<<endl;
	}
	return 0;
}
