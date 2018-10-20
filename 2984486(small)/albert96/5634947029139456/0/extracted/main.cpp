#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int N = 150+5, M = 40+5;
string a[ N ];
string b[ N ];

string c[ N ];
bool ch[ M ];
int main()
{
   ios_base::sync_with_stdio(0);
   int T = 0;
   freopen("A-small-attempt0(1).in", "r", stdin);
   freopen("A-small-attempt0(1).out", "w", stdout);
   cin>>T;
   for(int te = 1; te <= T; ++ te)
   {
      int n, m;
      cin>>n>>m;
      for(int i = 1; i <= n; ++ i)
      {
         a[i][0] = '\0';
         cin>>a[i];
         c[i] = a[i];
      }
      for(int i = 1; i <= n; ++ i)
      {
         b[i][0] = '\0';
         cin>>b[i];
      }
      sort(b+1, b+n+1);
      int res = -1;
      for(int i = 1; i <= n; ++ i)
      {
         for(int j = 1; j <= n; ++ j)
         {
            //a[i]==b[j]
            int q = 0;
            for(int u = 0; u < m; ++ u)
            {
               ch[u] = 0;
               if(a[i][u]!=b[j][u])
               {
                  ch[u] = 1;
                  ++ q;
               }
            }
            for(int k = 1; k <= n; ++ k)
            {
               for(int u = 0; u < m; ++ u)
               {
                  if(ch[u]==0)
                  {
                     c[k][u] = a[k][u];
                  }
                  else
                  {
                     c[k][u] = '1'-a[k][u]+'0';
                  }
               }
            }
            sort(c+1, c+n+1);
            for(int i = 1; i <= n; ++ i)
            {
               if(c[i]!=b[i])
               {
                  goto x;
               }
            }
            if(res==-1 || q < res)
               res = q;
x:;
         }
      }
      cout<<"Case #"<<te<<": ";
      if(res==-1)
      {
         cout<<"NOT POSSIBLE\n";
      }
      else
      {
         cout<<res<<endl;
      }
   }
   return 0;
}
