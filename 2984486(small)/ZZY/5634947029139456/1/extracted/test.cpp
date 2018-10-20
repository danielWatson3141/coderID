#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map> 
#define MAXN 155
using namespace std;
char St[155][45];
int s[155][45],c[45],h[155],a[155][45];
bool used[155];
bool ok(int x,int l)
{
      int i;
      for (i=1;i<=l;i++)
         if (a[x][i]!=c[i]) return false;
      return true;
}
int count(int n,int l)
{
      int t,x,y,i,sum,ans=-1;
      for (t=1;t<=n;t++)
      {
             sum=0;
             for (x=1;x<=l;x++) 
             { 
                    h[x]=0;
                    if (a[t][x]!=s[1][x])
                       sum++,h[x]=1;
             }
             memset(used,false,sizeof(used));
             used[t]=true;
             for (y=2;y<=n;y++)
             {
                     for (x=1;x<=l;x++)
                       if (h[x]) c[x]=1-s[y][x];
                            else c[x]=s[y][x];
                     for (i=1;i<=n;i++)
                       if (!used[i] && ok(i,l)) goto A;
                     break;
                     A: ;
                     used[i]=true;
             }       
             if (y<=n) continue;      
             if (ans<0 || ans>sum) ans=sum;
      }
      return ans;
}
int main()
{
      int T,cases,N,L,i,j,ans;
      freopen("A-large.in","r",stdin);
      freopen("output.txt","w",stdout);
      scanf("%d",&T);
      for (cases=1;cases<=T;cases++)
      {
             scanf("%d%d",&N,&L);
             for (i=1;i<=N;i++) scanf("%s",St[i]+1);
             for (i=1;i<=N;i++)
                for (j=1;j<=L;j++)
                   s[i][j]=St[i][j]-'0';
             for (i=1;i<=N;i++) scanf("%s",St[i]+1);
             for (i=1;i<=N;i++)
                for (j=1;j<=L;j++)
                   a[i][j]=St[i][j]-'0';
             printf("Case #%d: ",cases);
             ans=count(N,L);
             if (ans<0) puts("NOT POSSIBLE");
                   else printf("%d\n",ans);
      }
      return 0;
}
