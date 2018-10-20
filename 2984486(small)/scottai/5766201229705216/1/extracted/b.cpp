#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dis(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;

int l[1001][1001],r1[1001][1001],r2[1001][1001],f[1001],s[1001];

void dfs(int now,int last)
{
   r1[now][0]=0;
   s[now]=1;
   for (int i=1;i<=l[now][0];i++)
      if (l[now][i]!=last)
      {
         dfs(l[now][i],now);
         s[now]+=s[l[now][i]];
         r1[now][++r1[now][0]]=f[l[now][i]];
         r2[now][r1[now][0]]=s[l[now][i]];
      }
   if (r1[now][0]==0)
      f[now]=0;
   else if (r1[now][0]==1)
      f[now]=r2[now][1];
   else
   {
      int m1=-oo,m2=-oo;
      f[now]=0;
      for (int i=1;i<=r1[now][0];i++)
      {
         f[now]+=r2[now][i];
         if (r2[now][i]-r1[now][i]>m1)
         {
            m2=m1;
            m1=r2[now][i]-r1[now][i];
         }
         else if (r2[now][i]-r1[now][i]>m2)
            m2=r2[now][i]-r1[now][i];
      }
      f[now]-=m1+m2;
   }
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      int n,ans=oo;
      printf("Case #%d: ",t);
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
         l[i][0]=0;
      for (int i=1;i<n;i++)
      {
         int a,b;
         scanf("%d%d",&a,&b);
         l[a][++l[a][0]]=b;
         l[b][++l[b][0]]=a;
      }
      for (int i=1;i<=n;i++)
      {
         dfs(i,0);
         ans=min(ans,f[i]);
      }
      printf("%d\n",ans);
   }
   return 0;
}
