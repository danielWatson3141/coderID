//Coder: Saurabh Arora

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
int vis[1001];

struct tr
{
    int num;
    int ans;
};

bool info_sorter(const tr&lhs,const tr& rhs)
{
    return lhs.ans>rhs.ans;
}
int nodes(int root,vector<int>Mv[1001])
{
    int i;
    vis[root]=1;
    int ctr=1,tctr=0;
    for(i=0;i<Mv[root].size();i++)
    {
        if(vis[Mv[root][i]]==0)
            tctr++;
    }
    tr tmp;
    vector<tr>My;
    if(tctr<2)
        return 1;
    else
    {
        for(i=0;i<Mv[root].size();i++)
        {
             if(vis[Mv[root][i]]==0)
             {
                 tmp.num=Mv[root][i];
                 tmp.ans=nodes(Mv[root][i],Mv);
                 My.push_back(tmp);
             }
        }
        sort(My.begin(),My.end(),&info_sorter);
        return 1+My[0].ans +My[1].ans;
    }
}

int main() {

  freopen("B-large.in", "r", stdin);
  freopen("result.txt", "w", stdout);

      int i,j,T,N,a,b;
      scanf("%d",&T);
      for(i=1;i<T+1;i++)
      {
          scanf("%d",&N);
          vector<int>Mv[1001];
          for(j=0;j<N-1;j++)
          {
              scanf("%d %d",&a,&b);
              Mv[a].push_back(b);
              Mv[b].push_back(a);
          }
          int as,mx=0;
          for(j=1;j<N+1;j++)
          {   for(as=0;as<N+1;as++)
              vis[as]=0;
              as=nodes(j,Mv);
              mx=max(mx,as);
          }
          int ans;
          ans=N-mx;
          printf("Case #%d: %d\n",i,ans);
      }
}
