//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

char re[200][100],ar[200][100],ch[100];
map<string,int>Si;
map<string,int>vis;
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    freopen("A-large.in","r",stdin);
   freopen("Output.txt","w",stdout);
    scanf("%d",&t);
   for(r=1;r<=t;r++)
   {
       scanf("%d %d",&n,&l);
       m=1000;
       for(i=0;i<n;i++)
       {
           scanf("%s",&ar[i]);
       }
       for(i=0;i<n;i++)
       {
           scanf("%s",&re[i]);
           for(j=0;j<n;j++)
           {
               for(k=0,a=0;k<l;k++)
               {
                   if(re[i][k]!=ar[j][k])
                    ch[a++]=k+1+'0';
               }
               ch[a]='\0';
               if(vis[ch]!=i+1)
               {
                   vis[ch]=i+1;
                   if(Si[ch]==0)
                 Si[ch]=1;
                  else
                    Si[ch]=Si[ch]+1;
               }
              if(i==n-1)
              {
                  if(Si[ch]==n)
                    {
                        if(strlen(ch)<m)
                            m=strlen(ch);
                    }
              }
           }
       }
       if(m==1000)
        printf("Case #%d: NOT POSSIBLE\n",r);
       else
       printf("Case #%d: %d\n",r,m);
       Si.clear();
        vis.clear();

   }
    return 0;
}

