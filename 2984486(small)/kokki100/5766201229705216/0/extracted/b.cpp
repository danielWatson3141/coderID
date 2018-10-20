#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int t,n,xx,yy;
vector<int> v[1005];
string s;
int dp[1005][1005];

int cari(int x, int y)
{
    if (dp[x][y]!=-1) return dp[x][y];

    int temp=0;
    for (int i=0;i<v[x].size();i++)
    {
        if (v[x][i]!=y){
            for (int j=i+1;j<v[x].size();j++)
            {
                if (v[x][j]!=v[x][i] && v[x][j]!=y){
                    temp=max(temp,cari(v[x][i],x)+cari(v[x][j],x));
                }
            }
        }
    }

    dp[x][y]=temp+1;
    return dp[x][y];
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);

    scanf("%d",&t);
    for (int ll=1;ll<=t;ll++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) v[i].clear();
        for (int i=1;i<n;i++)
        {
            scanf("%d %d",&xx,&yy);
            v[xx].push_back(yy);
            v[yy].push_back(xx);
        }

        int ans=1;
        for (int i=1;i<=n;i++)
            ans=max(ans,cari(i,i));

        printf("Case #%d: %d\n",ll,n-ans);
    }

    return 0;
}
