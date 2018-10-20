#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int t;
int n;
int l;
char A[151][41];
char B[151][41];
long long aa[151];
long long bb[151];
long long cc[151];
long long mul[151];
int ans;
int chan;
main()
{
 freopen("A-small-attempt0.in","r",stdin);
 freopen("A-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 mul[0]=1;
 for(int i=1;i<=45;i++)
 {
  mul[i]=(long long)mul[i-1]*2;
 }
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d%d",&n,&l);
  for(int i=1;i<=n;i++)
  {
   scanf("%s",A[i]);
  }
   for(int i=1;i<=n;i++)
  {
   scanf("%s",B[i]);
  }
  for(int i=1;i<=n;i++)
  {
   aa[i]=0;
   bb[i]=0;
   for(int j=0;j<l;j++)
   {
   if(A[i][j]=='1'){aa[i]=aa[i]+mul[j];}
   if(B[i][j]=='1'){bb[i]=bb[i]+mul[j];}
   }
   
  }
  ans=999;
  sort(&bb[1],&bb[n+1]);
  for(int i=1;i<=n;i++)
  {
   for(int j=1;j<=n;j++)
   {
    cc[j]=aa[j];
   }
   chan=0;
   for(int j=0;j<l;j++)
   {
    if(A[i][j]!=B[1][j])
    {
     chan++;
     for(int k=1;k<=n;k++)
     {
      if(A[k][j]=='1'){cc[k]=cc[k]-mul[j];}
      else{cc[k]=cc[k]+mul[j];}
     }
    }
   }
   sort(&cc[1],&cc[n+1]);
   /*for(int j=1;j<=n;j++)
   {
   printf("cc %d = %I64d\n",i,cc[i]);
   printf("bb %d = %I64d\n",i,bb[i]);
   }*/
   if(chan<ans)
   {
   for(int j=1;j<=n;j++)
   {
    if(cc[j]!=bb[j]){break;}
    else if(j==n){ans=chan;}
   }
   }
  }  
  printf("Case #%d: ",tests);
  if(ans==999){printf("NOT POSSIBLE\n");}
  else{printf("%d\n",ans);}
 }
 return 0;
}
