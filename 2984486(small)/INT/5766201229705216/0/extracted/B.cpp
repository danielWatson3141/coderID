#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> edge[1010];
int f[1010],g[1010];

void dp(int p, int fa)
{
    g[p]++;
    int cnt=0,max1=0,max2=0;
    for (int i=0;i<edge[p].size();i++)
    {
        int j=edge[p][i];
        if (j!=fa)
        {
            cnt++;
            dp(j,p);
            g[p]+=g[j];
            if (max1<g[j]-f[j])
            {
                max2=max1;
                max1=g[j]-f[j];
            }
            else if (max2<g[j]-f[j]) max2=g[j]-f[j];
        }
    }
    if (cnt>=2) f[p]=g[p]-1-max1-max2;
    else f[p]=g[p]-1;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            edge[i].clear();
        for (int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--,y--;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        int ans=100010;
        for (int i=0;i<n;i++)
        {
            memset(f,0x3f,sizeof(f));
            memset(g,0,sizeof(g));
            dp(i,-1);
            ans=min(ans,f[i]);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
