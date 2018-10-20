#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int T,n,x,y,f[1010],TT,ans,s[1010];
vector <int> ed[1010];
bool don[1010];

void dfs(int x)
{
	don[x]=true;
	s[x]=0;
	f[x]=(int)1e9;
	int min1=(int)1e9,min2=(int)1e9,cnt=0;
	for (int i=0;i<ed[x].size();i++)
	{
		int y=ed[x][i];
		if (!don[y])
		{
			dfs(y);
			if (f[y]-s[y]<min2)
			{
				min2=f[y]-s[y];
				if (min2<min1) swap(min1,min2);
			}
			s[x]+=s[y];
		}
	}
	f[x]=min(s[x],s[x]+min1+min2);
	s[x]++;
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) ed[i].clear();
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			ed[x].push_back(y);
			ed[y].push_back(x);
		}
		ans=(int)1e9;
		for (int i=1;i<=n;i++)
		{
			memset(don,false,sizeof(don));
			dfs(i);
			ans=min(ans,f[i]);
		}
		printf("Case #%d: %d\n",++TT,ans);
	}

	return 0;
}