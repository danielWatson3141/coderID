#include<cstdio>
#include<vector>

std::vector<int> graph[1001];

int dfs(int x,int p)
{
	int i,t,m1=0,m2=0,cnt=0;
	for(i=0;i<graph[x].size();i++)if(graph[x][i]!=p)
	{
		cnt++;
		t=dfs(graph[x][i],x);
		if(t>m1)
		{
			m2=m1;
			m1=t;
		}
		else if(t>m2)m2=t;
	}
	if(cnt<2)return 1;
	else return m1+m2+1;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int s,e;
		int i,n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)graph[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&s,&e);
			graph[s].push_back(e);
			graph[e].push_back(s);
		}
		e=n;
		for(i=1;i<=n;i++)
		{
			s=dfs(i,0);
			if(e>n-s)e=n-s;
		}
		printf("Case #%d: %d\n",tc,e);
	}
	return 0;
}