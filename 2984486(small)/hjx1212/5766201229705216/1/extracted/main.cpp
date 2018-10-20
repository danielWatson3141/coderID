#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[1005];
struct node{
	int s,c;
	node(int s=0,int c=0):s(s),c(c){}
};

node dfs(int x,int p)
{
	int i,j=v[x].size(),s1=0,s2=0,c=1,s=1;
	for(i=0;i<j;i++)
		if(v[x][i]!=p)
		{
			node t=dfs(v[x][i],x);
			c+=t.c;
			if(t.s>s1)
				s2=s1,s1=t.s;
			else if(t.s>s2)
				s2=t.s;
		}
	if(s2)
		s+=s1+s2;
	return node(s,c);
}

int main()
{
	freopen("E:/in.txt","r",stdin);
	freopen("E:/out.txt","w",stdout);
	int T,t,n,i,a,b,s;
	for(scanf("%d",&T),t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(i=1,s=1<<30;i<=n;i++)
			s=min(s,n-dfs(i,0).s);
		printf("Case #%d: %d\n",t,s);
		for(i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}
