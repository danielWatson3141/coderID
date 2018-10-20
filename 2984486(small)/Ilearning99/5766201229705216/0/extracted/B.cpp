#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
vector<int> nodes[maxn];

int dp[maxn],num[maxn],rdp[maxn];

int childr[maxn][maxn],rt[maxn];

int N;

bool cmp(int a,int b)
{
    return a<b;
}

void dfs(int root,int fa)
{
    int i,u;
	num[root]=1;
	for(i=0;i<nodes[root].size();i++)
	{
	    u=nodes[root][i];
		if(u==fa)
		{
		    continue;
		}
		dfs(u,root);
		num[root]+=num[u];
	}
	dp[root]=0;
	rt[root]=0;
	for(i=0;i<nodes[root].size();i++)
	{
	    u=nodes[root][i];
		if(u==fa)
		{
		    continue;
		}
		childr[root][rt[root]++]=dp[u]-num[u];
	}
    sort(childr[root],childr[root]+rt[root],cmp);
	//cout<<root<<"  1    "<<num[root]<<" "<<dp[root]<<endl;
	if(rt[root]==0)
	{
	    return;
	}
	if(rt[root]==1)
	{
	    dp[root]=num[root]-1;
		//cout<<root<<"   2   "<<num[root]<<" "<<dp[root]<<endl;
		return;
	}
	dp[root]=childr[root][0]+childr[root][1]+num[root]-1;
	//cout<<root<<"   3   "<<num[root]<<" "<<dp[root]<<endl;
	return;
}

void rdfs(int root,int fa)
{
    int i,temp,u;
	if(fa!=0)
	{
	    if(rt[root]>=2)
		{
			if(rdp[fa]<childr[root][1])
			{
				dp[root]=rdp[fa]+childr[root][0]+N-1;
			}
			else
			{
			    dp[root]=childr[root][1]+childr[root][0]+N-1;
			}
		}
		if(rt[root]==1)
		{
			dp[root]=rdp[fa]+childr[root][0]+N-1; 
		}
		else if(rt[root]==0)
		{
		    dp[root]=N-1;
		}
		//cout<<rdp[fa]<<" "<<root<<" "<<dp[root]<<" "<<childr[root][0]<<" "<<childr[root][1]<<endl;
	}
	for(i=0;i<nodes[root].size();i++)
	{
	    u=nodes[root][i];
		if(u==fa)
		    continue;
		if(rt[root]<2||(rt[root]==2&&fa==0))
		{
		    rdp[root]=N-num[u]-1-(N-num[u]);
			rdfs(u,root);
		}
		else if(rt[root]==2)
		{
		    rdp[root]=N-1+childr[root][0]+childr[root][1]+rdp[fa];
			rdp[root]=rdp[root]-dp[u];
			rdp[root]=rdp[root]-(N-num[u]);
			rdfs(u,root);
		}
		else
		{
		    if(dp[u]-num[u]==childr[root][0])
			{
			    rdp[root]=childr[root][1]+childr[root][2]+N-num[u]-1;
				temp=rdp[fa]+childr[root][1]+N-num[u]-1;
				if(temp<rdp[root])
				{
				    rdp[root]=temp;
				}
			}
			else if(dp[u]-num[u]==childr[root][1])
			{
			    rdp[root]=childr[root][0]+childr[root][2]+N-num[u]-1;
			    temp=rdp[fa]+childr[root][0]+N-num[u]-1;
				if(temp<rdp[root])
				{
				    rdp[root]=temp;
				}
			}
			rdp[root]=rdp[root]-(N-num[u]);
		    rdfs(u,root);
		}
	}
}
int main()
{
    int T,casen,i,x,y,cmin;
	scanf("%d",&T);
	for(casen=0;casen<T;casen++)
	{
	    scanf("%d",&N);
        for(i=1;i<=N;i++)
		    nodes[i].clear();
		for(i=1;i<N;i++)
		{
		    scanf("%d %d", &x, &y);
			nodes[x].push_back(y);
			nodes[y].push_back(x);
		}
	    if(N==2)
		{
		    printf("Case #%d: %d\n",casen+1,1);
			continue;
		}
		if(N==1)
		{
		    printf("Case #%d: %d\n",casen+1,0);
			continue;
		}
		dfs(1,0);
		rdfs(1,0);
		cmin=maxn;
		for(i=1;i<=N;i++)
		{
		    if(dp[i]<cmin)
			    cmin=dp[i];
		}
		printf("Case #%d: %d\n",casen+1,cmin);
	}
    return 0;
}