# include <iostream>
# include <cmath>
# include <algorithm>
# include <queue>
# include <stack>
# include <algorithm>
# include <iomanip>
# include <string>
# include <cstring>
# include <cstdio>
# include <stdio.h>
using namespace std;
int ans=10100;
int now;
vector<int> adj[1000];
bool visited[1000];
int depth[1000];
int an[1000];
struct vertex
{
	int an;
	int i;
};
bool comp(vertex a,vertex b)
{
	return a.an<b.an;
}
void dfs(int v)
{
	vertex p[1000]={0};
	visited[v]=1;
	int n=adj[v].size();
	int son=0;
	for (int i=0;i<n;i++)
	{
		int u=adj[v][i];
		if (!visited[u])
		{
			visited[u]=1;
			dfs(u);
			p[son++].an=an[u];
			p[son-1].i=u;
			depth[v]+=depth[u];
		}
	}
	depth[v]++;
	if (son==1)
	{
		an[v]=depth[p[0].i];
	}
	else if (son>=2)
	{
		sort(p,p+son,comp);
		for (int i=0;i<son;i++)
			an[v]+=p[i].an;
	}
}
void init(int n)
{
	for (int i=0;i<n;i++)
	{
		depth[i]=0;
		visited[i]=0;
		an[i]=0;
	}
}
void init2(int n)
{
	ans=100000;
	for (int i=0;i<n;i++)
	{
		adj[i].clear();
	}
}
int main()
{
	freopen("1A.txt","w",stdout);
	int t;
	cin>>t;
	int h=1;
	while(t--)
	{
		int n;
		cin>>n;
		for (int i=0;i<n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x-1].push_back(y-1);
			adj[y-1].push_back(x-1);
		}
		for (int i=0;i<n;i++)
		{
			dfs(i);
			if (an[i]<ans)
				ans=an[i];
			init(n);
		}
		cout<<"Case #"<<h<<": ";
		cout<<ans<<endl;
		
			init2(n);
		h++;
	}
}
