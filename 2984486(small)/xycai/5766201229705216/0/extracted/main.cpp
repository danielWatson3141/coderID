#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#define MAX_N 1005

using namespace std;

int gn_n;
int edge[MAX_N][MAX_N];
int len[MAX_N];
int gn_ans;

int arr[155][155];
int dp[155][155];
int p[155];
int r[155];
int n,pp,root;
void cal123(int v)
{
    int i,j,k;
    for(i=0;i<p[v];i++)
    {
        cal123(arr[v][i]);
    }
    if(v==root) dp[v][1]=p[v];
    else dp[v][1]=p[v]+1;
    for(i=0;i<p[v];i++)
    {
        for(k=pp;k>0;k--)
        {
            for(j=1;j<=pp;j++)
            {
                if(dp[arr[v][i]][j]!=-1 && dp[v][k]!=-1)
                {
                    if(dp[v][k+j]==-1) dp[v][k+j]=dp[v][k]-2+dp[arr[v][i]][j];
                    else
                        if(dp[v][k+j]>dp[v][k]-2+dp[arr[v][i]][j])
                            dp[v][k+j]=dp[v][k]-2+dp[arr[v][i]][j];
                    //printf("dp[%d][%d]=%d dp[%d][%d]=%d dp[%d][%d]=%d\n",arr[v][i],j,dp[arr[v][i]][j],v,k,dp[v][k],v,k+j,dp[v][k+j]);
                }
            }
        }
    }
}

void read()
{
    scanf("%d", &gn_n);
    memset(len, 0, sizeof(len));
    int temx,temy;
    for(int i=1;i<gn_n;++i)
    {
        scanf("%d%d", &temx, &temy);
        edge[temx][len[temx]++] = temy;
        edge[temy][len[temy]++] = temx;
    }
}

int tree_dp(int x, int fat)
{
    int child[MAX_N];
    int childlen = 0;
    for(int i=0;i<len[x];++i)
    {
        if(edge[x][i] == fat) continue;
        child[childlen++] = tree_dp(edge[x][i],x);
    }
    if(childlen<=1) return 1;
    else
    {
        sort(child, child+childlen);
        int ret = child[childlen-1] + child[childlen-2] + 1;
        return ret;
    }
}

void calc()
{
    gn_ans = 0;
    for(int i=1;i<=gn_n;++i)
    {
        int temans = tree_dp(i, -2);
        gn_ans = gn_ans>temans?gn_ans:temans;
    }
}

void solve()
{
    read();
    calc();
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, cas = 1;
    scanf("%d", &t);
    while(t--)
    {
        solve();
        int sol = gn_n-gn_ans;
        printf("Case #%d: %d\n", cas++, sol);
    }
    return 0;
}

//int main()
//{
//    int i,x,y,ans;
//    scanf("%d%d",&n,&pp);
//    memset(p,0,sizeof(p));
//    memset(r,0,sizeof(r));
//    for(i=0;i<n-1;i++)
//    {
//        scanf("%d%d",&x,&y);
//        arr[x][p[x]++]=y;
//        r[y]=1;
//    }
//    memset(dp,-1,sizeof(dp));
//    for(i=1;i<=n;i++) if(r[i]==0)
//    {
//        root=i;
//        cal(i);
//    }
//    ans=dp[1][pp];
//    for(i=2;i<=n;i++)
//    {
//        if(dp[i][pp]!=-1)
//        {
//            if(ans>dp[i][pp]) ans=dp[i][pp];
//        }
//    }
//    printf("%d\n",ans);
//    return 0;
//}

