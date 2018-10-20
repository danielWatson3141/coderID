#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
int n;
const int maxn = 2005;
int head[maxn],tot;
struct array
{
    int to,next;
}edge[maxn*2];
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int num[maxn];
int Max;
void dfs(int u,int fa)
{
    int i,j;
    num[u]=1;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs(v,u);
        num[u]+=num[v];
    }
}
int anst[maxn];
int dfs2(int u,int fa)
{
    int i,j;
    int sum=0;
    anst[u]=0;
    int f=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa)continue;
        dfs2(v,u);
        sum += anst[v];
        f++;
    }
    if(f==0)return anst[u]=0;
    if(f==1)return anst[u]=num[u]-1;
    if(f==2)return anst[u]=sum;
    if(f>2)
    {
        int M=num[u];
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            if(edge[i].to==fa)continue;
            int v1 = edge[i].to;
            for(j=head[u];j!=-1;j=edge[j].next)
            {
                if(edge[j].to==fa)continue;
                if(i==j)continue;
                int v2=edge[j].to;
                int tmp = num[u]-1-num[v1]-num[v2]+anst[v1]+anst[v2];
                if(M>tmp)M=tmp;
            }
        }
        return anst[u]=M;
    }
}
int main()
{
    int i,j,t;
//        freopen("B-small-attempt0.in","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int a,b;
    int cas=0;
    while(t--)
    {
        memset(head,-1,sizeof(head));
        tot=0;
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        int ans=-1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                num[j]=0;
            dfs(i,-1);
//            for(j=1;j<=n;j++)
//                cout<<num[j]<<" ";
//            cout<<endl;
            Max=dfs2(i,-1);
//            cout<<Max<<endl;
            if(ans==-1||ans>Max)
                ans=Max;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}
