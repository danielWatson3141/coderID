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

char a[155][155],b[155][155],c[155][155],p[155],q[155];

bool cmp1(int x,int y)
{
   return strcmp(b[x]+1,b[y]+1)<0;
}

bool cmp2(int x,int y)
{
   return strcmp(c[x]+1,c[y]+1)<0;
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int qq;
   cin>>qq;
   for (int t=1;t<=qq;t++)
   {
      int n,l,ans=oo;
      printf("Case #%d: ",t);
      scanf("%d%d",&n,&l);
      for (int i=1;i<=n;i++)
         scanf("%s",a[i]+1);
      for (int i=1;i<=n;i++)
         scanf("%s",b[i]+1);
      for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
         {
            for (int k=1;k<=n;k++)
               strcpy(c[k]+1,a[k]+1);
            int s=0;
            for (int k=1;k<=l;k++)
               if (a[i][k]!=b[j][k])
                  s++;
            if (s>=ans)
               goto end;
            for (int k=1;k<=l;k++)
               if (a[i][k]!=b[j][k])
                  for (int x=1;x<=n;x++)
                     c[x][k]^='0'^'1';
            for (int k=1;k<=n;k++)
               p[k]=q[k]=k;
            sort(p+1,p+n+1,cmp1);
            sort(q+1,q+n+1,cmp2);
            for (int k=1;k<=n;k++)
               if (strcmp(b[p[k]]+1,c[q[k]]+1))
                  goto end;
            ans=s;
            end:;
         }
      if (ans==oo)
         printf("NOT POSSIBLE\n");
      else
         printf("%d\n",ans);
   }
   return 0;
}
