#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1000+5;
int n;
bool mark[ N ];
vector< int > g[ N ], graph[ N ];

int p[N], d[ N ];
int hd[ N ];
int s[ N ], hs[ N ];
int top;
pair< int, int> r[ N ];
void dfs(int v)
{
   d[v] = 1;
   mark[v] = 1;
   s[v] = 1;
   for(int j = 0; j < (int)g[v].size(); ++ j)
   {
      int to = g[v][j];
      if(mark[to]==0)
      {
         p[to] = v;
         graph[v].push_back( to );
         dfs(to);
         s[v]+=s[to];
      }
   }
   top = 0;
   for(int j = 0; j < (int)graph[v].size(); ++ j)
   {
      int to = graph[v][j];
      ++ top;
      r[ top ].first = d[ to ];
      r[ top ].second = to;
   }
   sort(r+1, r+top+1);
   if(top >= 2)
   {
      d[ v ] = r[top].first+r[ top-1 ].first+1;
   }
}

void hdfs(int v)
{
   top = 0;
   if(hs[v])
   {
      ++ top;
      r[ top ].first = hd[ v ];
      r[ top ].second = p[ v ];
   }
   for(int j = 0; j < (int)graph[v].size(); ++ j)
   {
      int to = graph[v][j];

      ++ top;
      r[ top ].first = d[ to ];
      r[ top ].second = to;


      hs[to] = hs[v]+s[v]-s[to];
   }
   sort(r+1, r+top+1);
   for(int j = 0; j < (int)graph[v].size(); ++ j)
   {
      int to = graph[v][j];
      hd[ to ] = 1;
      int i1 = top;
      int res = 1;
      int q = 0;
      for(int u = 1; u <= 2; ++ u)
      {
x:;
         if(i1 <= 0)
            break;
         if(i1 > 0 && r[ i1 ].second!=to)
         {
            res+=r[ i1 ].first;
            -- i1;
            ++ q;
         }
         else
         {
            -- i1;
            goto x;
         }
      }
      if(q==2)
      {
         hd[to] = res;
      }
   }
   for(int j = 0; j < (int)graph[v].size(); ++ j)
   {
      int to = graph[v][j];
      hdfs(to);
   }
}

int res[ N ];
int main()
{
   freopen("B-small-attempt2.in", "r", stdin);
   freopen("B-small-attempt2.out", "w", stdout);
   int T = 0;
   scanf("%d", &T);
   for(int te = 1; te <= T; ++ te)
   {
      scanf("%d", &n);
      for(int i = 1; i <= n; ++ i)
      {
         mark[i] = 0;
         g[i].clear();
         graph[i].clear();
      }
      for(int i = 1; i < n; ++ i)
      {
         int s, f;
         scanf("%d%d", &s, &f);
         g[ s ].push_back( f );
         g[ f ].push_back( s );
      }
      dfs( 1 );
     // cout<<s[1]<<endl;
      hdfs( 1 );
      int ans = 0;
      /*for(int i = 1; i <= n; ++ i)
      {
         cout<<d[i]<<",";
      }
      cout<<endl;
     */ for(int v = 1; v <= n; ++ v)
      {
            top = 0;
            if(hs[v])
            {
               ++ top;
               r[ top ].first = hd[ v ];
               r[ top ].second = p[ v ];
            }
            for(int j = 0; j < (int)graph[v].size(); ++ j)
            {
               int to = graph[v][j];

               ++ top;
               r[ top ].first = d[ to ];
               r[ top ].second = to;


               hs[to] = hs[v]+s[v]-s[to];
            }
            sort(r+1, r+top+1);
            res[v] = 1;
            if(top >= 2)
            {
               res[v] = r[top].first+r[top-1].first+1;
            }
            //cout<<v<<"]"<<res[v]<<endl;
            if(ans < res[v])
            {
               ans = res[v];
            }
      }
      printf("Case #%d: %d\n", te, n-ans);
   }
   return 0;
}
