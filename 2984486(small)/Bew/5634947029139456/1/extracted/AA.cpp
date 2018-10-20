#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
int T;
int a[200][50];
int b[200][50];
int d[50];
long long A[200];
long long B[200];
int n,m;
char c[50];
int ANS;
int LIM=999999999;
int main()
{
freopen("A-large.in","r",stdin);
freopen("A-large.out","w",stdout);
    int i,j,k;
    long long p,q,r;
    long long t,tt,ttt;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
  ANS=LIM;
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
        if(c[j-1]=='0')b[i][j]=0;
        else if(c[j-1]=='1')b[i][j]=1;
        r=(long long)b[i][j];
        t+=(p*r);
        p*=2;
      }
     B[i]=t;
   }
  sort(B+1,B+1+n);
  for(i=1;i<=n;i++)
   {
     for(j=1;j<=m;j++)
      {
        if(a[1][j]!=b[i][j])d[j]=1;
        else d[j]=0;
      }
     for(j=1;j<=n;j++)
      {
        t=0;p=1;
        for(k=1;k<=m;k++)
         {
           if(d[k]==1)
            {
              if(a[j][k]==1)r=0;
              else r=1;
            }
           else r=a[j][k];
           t+=(p*r);
           p*=2;
         }
        A[j]=t;
      }
     sort(A+1,A+1+n);
     for(j=1;j<=n;j++)
      {
        if(A[j]!=B[j])break;
      }
     if(j==n+1)
      {
        int Bew=0;
        for(k=1;k<=m;k++)
         {
           if(d[k]==1)Bew++;
         }
        if(Bew<ANS)ANS=Bew;
      }
   }
   printf("Case #%d: ",ii);
   if(ANS==LIM)printf("NOT POSSIBLE");
   else printf("%d",ANS);
   if(ii<=T-1)printf("\n");
}    
    
    
    
    scanf(" ");
    return 0;
}
