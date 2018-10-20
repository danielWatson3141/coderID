#include<bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define scf scanf
#define ptf printf
#define fst first
#define scd second
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
using namespace std;
typedef long long LL;

const int N=1010;

int mp[N][N],n,dp[N][N];

int dfs(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    int t0=0,t1,t2=0,mx1=-1,mx2=-1;
    forp(i,1,n+1)
        if(i-x&&i-y&&mp[x][i])
        {
            t0++;
            t1=dfs(i,x);
            if(t1>mx1){mx2=mx1;mx1=t1;}
            else
                if(t1>mx2)mx2=t1;
            t2+=t1;
        }
    if(t0<2)dp[x][y]=1;
    if(t0==2)dp[x][y]=t2+1;
    if(t0>2)dp[x][y]=mx1+mx2+1;
    return dp[x][y];
}



int main()
{
    freopen("B-large.in","r",stdin);
    freopen("2.txt","w",stdout);
    int T,x,y;
    scf("%d",&T);
    forp(tcnt,0,T)
    {
        scf("%d",&n);
        memset(mp,0,sizeof(mp));
        forp(i,0,n-1)
        {
            scf("%d%d",&x,&y);
            mp[x][y]=mp[y][x]=1;
        }
        int ans=10000;
        memset(dp,-1,sizeof(dp));
        forp(i,1,n+1)
            ans=min(ans,n-dfs(i,0));
        ptf("Case #%d: %d\n",tcnt+1,ans);
    }
    return 0;
}

