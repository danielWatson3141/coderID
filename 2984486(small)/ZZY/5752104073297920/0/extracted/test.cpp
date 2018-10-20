#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map> 
#define MAXN 1005
#define G 0.6180340
using namespace std; 
int a[MAXN];
int main()
{
      int T,cases,N,i,j,sum,m;
      freopen("C-small-attempt0.in","r",stdin);
      freopen("output.txt","w",stdout);
      scanf("%d",&T);
      for (cases=1;cases<=T;cases++)
      {
              scanf("%d",&N);
              for (i=1;i<=N;i++) scanf("%d",&a[i]);
              sum=0;
              m=(int)(N*(N-1)/2*G);
              for (i=1;i<N;i++)
                 for (j=i+1;j<=N;j++)
                    if (a[j]<a[i]) 
                       sum++;
              printf("Case #%d: ",cases);
              if (sum>=m)  puts("GOOD");
                     else  puts("BAD");
      }
      return 0;
}
