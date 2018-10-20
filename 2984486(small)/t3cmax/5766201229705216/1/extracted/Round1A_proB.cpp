#include<fstream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;

ifstream fin("B-large.in");
ofstream fout("ans.out");

struct node{
       int num,next;
       };

int edge[1001],taile;
node e[2001];


int dp[1001];
int sum[1001];
int t,n;
int ans;
void DFS(int now,int fa)
{
    dp[now]=0;
    sum[now]=1;
    int i;
    int max1,max2;
    int temp;
    int po=0;
    max1=max2=-1;
    for(i=edge[now];i!=-1;i=e[i].next)
    {
         if(e[i].num!=fa)
         {
             po++;
             DFS(e[i].num,now);
             
             sum[now]+=sum[e[i].num];
             temp=sum[e[i].num]-dp[e[i].num];
             if(temp>max1)
             {
                  max2=max1;
                  max1=temp;
             }
             else if(temp>max2)
             {
                 max2=temp;
             }
         }
    }
    
    if(po==0)
    {
        dp[now]=0;
    }
    else if(po==1)
    {
        dp[now]=sum[now]-1;
    }
    else
    {
        dp[now]=sum[now]-1;
        dp[now]-=max1;
        dp[now]-=max2;
    }
    
    return ;
}


int main()
{
    int i,j,k,times;
    int xx,yy;
    fin>>t;
    for(times=1;times<=t;times++)
    {
         memset(edge,-1,sizeof(edge));
         taile=1;
         fin>>n;
         for(i=1;i<=n-1;i++)
         {
             fin>>xx>>yy;
             e[taile].num=yy;
             e[taile].next=edge[xx];
             edge[xx]=taile;
             taile++;
             
             e[taile].num=xx;
             e[taile].next=edge[yy];
             edge[yy]=taile;
             taile++;
         }
         
         
         ans=999999;
         for(i=1;i<=n;i++)
         {
             DFS(i,0);
             //fout<<i<<' '<<dp[i]<<endl;
             ans=min(ans,dp[i]);
         }
         
         fout<<"Case #"<<times<<": ";
         fout<<ans<<endl;
         
         
    }
    
    system("pause");
    return 0;
}
