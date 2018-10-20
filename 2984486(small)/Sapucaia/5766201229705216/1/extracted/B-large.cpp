#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define rep0(i,n) for(int i = 0;i < (int)n;i++)
#define rep1(i,n) for(int i = 1;i <= (int)n;i++)
#define per0(i,n) for(int i = (int)n-1;i >= 0;i--)
#define per1(i,n) for(int i = (int)n ;i >= 1;i--)

#define pb push_back
#define fill(d,v) memset(d,v,sizeof(d))

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;

#define MAX_N 1100
bool vis[MAX_N];
vector<int> adj[MAX_N];
int size[MAX_N];
int ans,N;
int dfs_size(int u)
{
  if(vis[u] == true)
    return 0;
  vis[u] = true;
  size[u] = 1;

  for(int i = 0; i < (int)adj[u].size();i++)
    size[u] += dfs_size(adj[u][i]);
  return size[u];
}
int root;
int dfs(int u)
{
  if(vis[u] == true)
    return 0;
  vis[u] = true;
  int ret = 0;
  int adjSize = (int)adj[u].size();
  if(root == u)
    adjSize++;
  if(adjSize == 3)
    {
      for(int i = 0; i < (int)adj[u].size();i++)
	ret+= dfs(adj[u][i]);
    }
  else if(adjSize == 2)
    {
      int child = 0;
      if(vis[adj[u][0]])
	child =1;
      ret = size[adj[u][child]];
    }
  else if(adjSize > 3)
    {
      int best[2];
      best[0] = best[1] = N;
      for(int i = 0; i < (int)adj[u].size();i++)
	{
	  int v = adj[u][i];
	  if(vis[v])
	    continue;
	  int vRem = size[v] - dfs(v);
	  if(vRem >= best[0])
	    {
	      best[1] = best[0];
	      best[0] = vRem;
	    }
	  else if(vRem >= best[1])
	    best[1] = vRem;
	  ret = size[u]-1-best[0]-best[1];
	}
    }
  return ret;
}
int main()
{
  int T,N;
  scanf(" %d",&T);
  for(int t = 1; t <= T;t++)
    {
      cin >> N;
      for(int i = 0; i < N;i++)
	adj[i].clear();
      for(int i = 0; i < N-1;i++)
	{
	  int u,v;
	  cin >> u >> v;
	  u--,v--;
	  adj[u].push_back(v);
	  adj[v].push_back(u);
	}
      ans = N;
      for(int i = 0; i < N;i++)
	{
	  for(int j = 0;  j< N;j++)
	    vis[j] = false;
	  dfs_size(i);

	  for(int j = 0;  j< N;j++)
	    vis[j] = false;
	  root = i;
	  int temp = dfs(i);
	  ans = min(ans,temp);
	}
      printf("Case #%d: %d\n",t,ans);
    }
  return 0;
}
