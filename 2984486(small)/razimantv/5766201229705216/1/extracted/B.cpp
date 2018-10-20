# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>

using namespace std;

vector<int> adjlist[1001];
char seen[1001];
int cnt[1001],best[1001];

void dfs(int u)
{
  seen[u]=1;
  cnt[u]=1;

  vector<int> bestchild;
  for(int i=0;i<adjlist[u].size();i++)
  {
    int v=adjlist[u][i];
    if(seen[v])continue;
    dfs(v);
    bestchild.push_back(best[v]);
    cnt[u]+=cnt[v];
  }

  sort(bestchild.begin(),bestchild.end(),greater<int>());
  if(bestchild.size()<2)best[u]=1;
  else best[u]=1+bestchild[0]+bestchild[1];
}

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int N;
    scanf("%d",&N);

    for(int i=0;i<N-1;i++)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      adjlist[a].push_back(b);
      adjlist[b].push_back(a);
    }

    int ret=N-1;
    for(int i=1;i<=N;i++)
    {
      memset(seen,0,sizeof seen);
      dfs(i);
      ret=min(ret,N-best[i]);
    }

    printf("Case #%d: %d\n",t,ret);
    
    for(int i=1;i<=N;i++)
    {
      adjlist[i].clear();
    }
  }
  return 0;
}

