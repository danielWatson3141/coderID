//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<cctype>
#include<string>
#include<algorithm>
#include<iostream>
#include<ctime>
#include<map>
#include<set>
using namespace std;
#define MP(x,y) make_pair((x),(y))
#define PB(x) push_back(x)
typedef long long LL;
//typedef unsigned __int64 ULL;
/* ****************** */
const int INF=1000111222;
const double INFF=1e100;
const double eps=1e-8;
const int mod=1000000007;
const int NN=1005;
const int MM=401010;
/* ****************** */

struct G
{
    int v,next;
}E[NN*2];
int p[NN],T,cnt;
bool vis[NN],fg;
bool viss[NN];

void add(int u,int v)
{
    E[T].v=v;
    E[T].next=p[u];
    p[u]=T++;
}

void dfs(int u)
{
    int i,v,tol=0;
    for(i=p[u];i+1;i=E[i].next)
    {
        v=E[i].v;
        if(!vis[v])
        {
            cnt++;
            vis[v]=true;
            dfs(v);
            tol++;
        }
    }
    if(tol!=0 && tol!=2)
        fg=false;
}

int main()
{
    freopen("E:\\B-small-attempt0.in","r",stdin);
    freopen("E:\\B-small-attempt0.out","w",stdout);

    int cas,ee=0;
    int n,i,u,v,mask,t,k;
    int ans,j;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(p,-1,sizeof(p));
        T=0;

        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }

        ans=n;
        mask=1<<n;

      //  puts("fuck!");

        for(i=0;i<mask;i++)
        {
            cnt=0;
            t=0;
            for(j=0;j<n;j++)
            {
                if((1<<j)&i)
                {
                    viss[j+1]=true;
                    t++;

                 //   printf("shan==%d\n",j+1);
                }
                else
                    viss[j+1]=false;
            }

         //   puts("st");

            for(j=1;j<=n;j++)
            {
                fg=true;
                if(!viss[j])
                {
                    for(k=1;k<=n;k++)
                    {
                        vis[k]=viss[k];
                    }

                    cnt=t+1;
                    vis[j]=true;
                    dfs(j);

                    if(fg && cnt==n)
                    {
                        ans=min(ans,t);
                    }
                }
            }

          //  puts("en");
        }

        printf("Case #%d: ",++ee);
        printf("%d\n",ans);
    }
    return 0;
}
