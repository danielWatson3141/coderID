#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1010,INF = MAXN * 10;
vector< int > e[MAXN];

int dp[MAXN],size[MAXN];
void dfs(int u,int fath)
{
  for(int &v : e[u])
    if (v != fath)
      dfs(v,u);

  int min1 = INF,min2 = INF;
  size[u] = 1;

  for(int &v : e[u])
    if (v != fath)
      {
	size[u] += size[v];
	int res = dp[v] - size[v];
	if (res < min1)
	  {
	    min2 = min1;
	    min1 = res;
	  }
	else if (res < min2)
	  min2 = res;
      }

  dp[u] = size[u] - 1 + min(0,min1 + min2);
}

int main()
{
  int t;
  scanf("%d",&t);

  for(int case_num = 1; case_num <= t; case_num++)
    { 
      int n;
      scanf("%d",&n);
      
      for(int i = 1; i <= n; i++) e[i].clear();

      for(int i = 0; i < n-1; i++)
	{
	  int u,v;
	  scanf("%d%d",&u,&v);
	  e[u].push_back(v);
	  e[v].push_back(u);
	}

      int ans = INF;
      for(int r = 1; r <= n; r++)
	{
	  dfs(r,0);
	  //printf("%d %d\n",r,dp[r]);
	  ans = min(ans,dp[r]);
	}

      printf("Case #%d: ",case_num);
      printf("%d\n",ans);
    }
  return 0;
}
