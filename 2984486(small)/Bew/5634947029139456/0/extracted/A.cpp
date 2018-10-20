#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
int T,n,m;
char c[222];
int a[222][222];
int b[20111];
int re[20111];
int x[111];
int out[111];
int countt;
int ANS;
int LIM=999999999;
int rec(int h)
{
  if(h==m+1)
   {
     countt=0;
     for(int i=0;i<=2050;i++)re[i]=0;
     for(int i=1;i<=m;i++)
      {
        if(x[i]==1)countt++;
      }
     for(int i=1;i<=n;i++)
      {
        for(int j=1;j<=m;j++)
         {
           if(x[j]==0)
            {
              out[j]=a[i][j];
            }
           else if(x[j]==1)
            {
              if(a[i][j]==1)out[j]=0;
              else if(a[i][j]==0)out[j]=1;
            }
         }
        int t=0;
        int p=1;
        for(int j=1;j<=m;j++)
         {
           t+=(out[j]*p);
           p*=2;
         }
        re[t]=1;
      }
     int i;
     for(i=0;i<2050;i++)
      {
        if(b[i]!=re[i])break;
      }
     if(i==2050)
      {
        if(countt<ANS)ANS=countt;
      }
     return 0;
   }
  x[h]=0;
  rec(h+1);
  x[h]=1;
  rec(h+1);
}
int main()
{
freopen("A-small-attempt1.in","r",stdin);
freopen("A-small-attempt1.out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
 {
   ANS=LIM;
   for(i=0;i<222;i++)for(j=0;j<222;j++){a[i][j]=0;}
   for(i=0;i<20200;i++)b[i]=0;
   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++)
    {
      scanf("%s",c);
      for(j=1;j<=m;j++)
       {
         if(c[j-1]=='0')a[i][j]=0;
         else if(c[j-1]=='1')a[i][j]=1;
       }
    }
   for(i=1;i<=n;i++)
    {
      scanf("%s",c);
      t=0;p=1;
      for(j=1;j<=m;j++)
       {
         if(c[j-1]=='0')tt=0;
         else if(c[j-1]=='1')tt=1;
         t+=(tt*p);
         p*=2;
       }
      b[t]++;
    }
  // for(i=0;i<=2050;i++)if(b[i]!=0)printf("%d %d\n",i,b[i]);
   rec(1);
   printf("Case #%d: ",ii);
   if(ANS==LIM)printf("NOT POSSIBLE");
   else printf("%d",ANS);
   if(ii<=T-1)printf("\n");
 }
    
    scanf(" ");
    return 0;
}
