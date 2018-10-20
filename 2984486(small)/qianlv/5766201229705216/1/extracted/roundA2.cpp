/*************************************************************************
  > File Name: roundA2.cpp
  > Author: qianlv
  > Mail: qianlv7@qq.com 
  > Created Time: 2014年04月26日 星期六 09时46分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1100
#define INF 0x7ffffff
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CL(a,b) memset(a,b,sizeof(a))
#define LL long long ing
using namespace std;
struct data{
    int node;
    struct data *next;
}*g[N];
void insert(int x,int y)
{
    data *temp = new data;
    temp->next = NULL;
    temp->node = y;
    if(g[x]==NULL)
      g[x] = temp;
    else
    {
        temp->next = g[x];
        g[x] = temp;
    }
}
int n;
int q[N];
bool vis[N];
int del[N];
int ge[N];
void bfs(int b)
{
    CL(vis,false);
    CL(del,0);
    int head,tail;
    head = tail = 0;
    q[head++] = b;
    vis[b] = true;
    while(head!=tail)
    {
   //     printf("%d\n",head);
        int t = q[tail++];
        data *temp;
        int sum = 0;
        for(temp = g[t]; temp!=NULL; temp=temp->next)
        {
            int v = temp->node;
            if(vis[v]==false){
                sum++;
                del[t]++;
                q[head++]=v;
                vis[v]=true;
            }
        }
    }
}
int dfs(int b)
{
    data *temp;
    vis[b]=true;
    for(temp = g[b]; temp != NULL ; temp = temp->next)
    {
        if(vis[temp->node]==false)
        {
            dfs(temp->node);
            ge[b]+=ge[temp->node];
        }
    }
    ge[b]++;
}
int solve(int b)
{
    int head,tail;
    head = tail = 0;
    CL(vis,false);
    q[head++] = b;
    vis[b]=true;
    int sum = 0;
    while(head!=tail)
    {
        int  t = q[tail++];
        data *temp;
        if(del[t]==0||del[t]==2)
        {
            for(temp = g[t]; temp!=NULL; temp=temp->next)
            {
                int v = temp->node;
                if(vis[v]==false)
                {
                    vis[v]=true;
                    q[head++]=v;
                }
            }
        }
        else if(del[t]==1)
        {
           // printf("--%d\n",t);
            for(temp = g[t]; temp != NULL; temp = temp->next)
            {
                int v = temp->node;
           //     printf("--%d %d\n",v,ge[v]);
                if(vis[v]==false)
                {
                    sum+=ge[v];
                    vis[v]=true;
                }
            }
        }
        else
        {
            int maxv,max2v;
            maxv=max2v=-1;
            for(temp = g[t]; temp != NULL; temp = temp->next)
            {
                int v = temp->node;
                if(vis[v]==false)
                {
                    if(maxv==-1)
                        maxv=v;
                    else if(ge[maxv]<ge[v])
                    {
                        max2v = maxv;
                        if(max2v == -1|| ge[max2v]<ge[v])
                            maxv = v;
                    }
                    else if(max2v==-1)
                        max2v=v;
                    else if(ge[max2v]<ge[v])
                        max2v = v;
                }
            }
            for(temp = g[t]; temp != NULL; temp = temp->next)
            {
                int v = temp->node;
                if(vis[v]==false)
                {
                    if(maxv==v)
                        q[head++]=v;
                    else if(max2v == v)
                        q[head++] = v;
                    else
                        sum+=ge[v];
                    vis[v]=true;
                }
            }
        }
    }
    return sum;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-out","w",stdout);
    int T;
    scanf("%d",&T);
    int cas;
    for(cas=1;cas<=T;cas++)
    {
        int x,y;
        int i,j,k;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
          g[i]=NULL;
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&x,&y);
            insert(x,y);
            insert(y,x);
        }
        int ans = INF;
        for(i=1;i<=n;i++)
        {
            CL(vis,false);
            CL(ge,0);
            dfs(i);// puts("a");
            bfs(i);// puts("b");
            int t;
           // for(j=1;j<=n;j++)
            //    printf("%d ",del[j]);
            t = solve(i); //puts("c");
           // printf("(%d)\n",t);
            ans = MIN(ans,t);
        }
       // puts("");
        printf("Case #%d: %d\n",cas,ans);
    }
}

