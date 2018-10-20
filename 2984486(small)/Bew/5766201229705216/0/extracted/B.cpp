#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
vector<int> V[111];
int T;
int n;
int x[111];
int LIM=999999999;
int ANS;
int VISIT[22];
int GO(int G)
{
  if(x[G]==0)return 0;
  if(VISIT[G]==1)return 0;
  VISIT[G]=1;
  int i,k;
  k=V[G].size();
  for(i=0;i<k;i++)
   {
     GO(V[G][i]);
   }
  return 0;
}
int ALL()
{
  int i,j,k;
  for(i=1;i<=n;i++)
   {
     if(x[i]==1)
      {
        k=i;
        break;
      }
   }
  for(i=0;i<22;i++)VISIT[i]=0;
  GO(k);
  for(i=1;i<=n;i++)
   {
     if(VISIT[i]==0 && x[i]==1) return 0;
   }
  return 1;
}
int rec(int h)
{
  if(h==n+1)
   {
     int i,j,k,p;
     int ONE=0,TWO=0,THREE=0,OTHER=0;
     for(i=1;i<=n;i++)
      {
        if(x[i]==1)break;
      }
     if(i==n+1)return 0;
     int AAA=ALL();
     if(AAA==0)return 0;
     for(i=1;i<=n;i++)
      {
        if(x[i]==1)
         {
           k=V[i].size();
           p=0;
           for(j=0;j<k;j++)
            {
              if(x[V[i][j]]==1)
               {
                 p++;
               }
            }
           if(p==1)ONE++;
           else if(p==2)TWO++;
           else if(p==3)THREE++;
           else OTHER++;
   //        printf("> %d %d\n",i,p);
         }
      }
     if(OTHER!=0)return 0;
     if(TWO!=1)return 0;
     p=0;
     for(i=1;i<=n;i++)
      {
        if(x[i]==0)p++;
      }
   //  for(i=1;i<=n;i++)printf("%d",x[i]);
   //  printf("\n");
    // printf("%d %d %d %d\n\n",ONE,TWO,THREE,OTHER);
     if(p<ANS)ANS=p;
     
     return 0;
   }
  x[h]=0;
  rec(h+1);
  x[h]=1;
  rec(h+1);
}
int main()
{
freopen("B-small-attempt0 (1).in","r",stdin);
freopen("B-small-attempt0 (1).out","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
  ANS=LIM;
  for(i=0;i<110;i++)V[i].clear();
  scanf("%d",&n);
  for(i=0;i<n-1;i++)
   {
     scanf("%d %d",&p,&q);
     V[p].push_back(q);
     V[q].push_back(p);
   }
  /*
  for(i=1;i<=n;i++)
   {
     k=V[i].size();
     printf("%d: ",i);
     for(j=0;j<k;j++)
      {
        printf("%d ",V[i][j]);
      }
     printf("\n");
   }printf("\n\n");
   */
  rec(1);
   printf("Case #%d: ",ii);
   if(ANS==LIM)printf("%d",n-1);
   else printf("%d",ANS);
   if(ii<=T-1)printf("\n");
}    
    
    scanf(" ");
    return 0;
}
