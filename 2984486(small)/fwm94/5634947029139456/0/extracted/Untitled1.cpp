#include<bits/stdc++.h>
#define maxn 15
#define INF 1<<30
using namespace std;
int cx[maxn],cy[maxn],vis[maxn],n;
bool a[maxn][maxn];
char s[maxn][maxn],t[maxn][maxn];
int path(int u)
{
    int v;
    for(v=0;v<n;v++)
    {
        if(a[u][v]&&!vis[v])
        {
            vis[v]=1;
            if(cy[v]==-1||path(cy[v]))
            {
                cx[u]=v;
                cy[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int match()
{
    int res=0;
    memset(cx,-1,sizeof(cx));
    memset(cy,-1,sizeof(cy));
    for(int i=0;i<n;i++)
    {
        if(cx[i]==-1)
        {
            memset(vis,0,sizeof(vis));
            res+=path(i);
        }
    }
    return res;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("AA.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    int cot=1;
    while(tt--)
    {
        int l;
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        for(int i=0;i<n;i++)
            scanf("%s",t[i]);
        int ans=INF;
        for(int i=0;i<1<<l;i++)
        {
            int cnt=0;
            for(int j=0;j<l;j++)
            {
                if(i&(1<<j))
                {
                    cnt++;
                    for(int k=0;k<n;k++)
                        if(s[k][j]=='1')
                            s[k][j]='0';
                        else
                            s[k][j]='1';
                }
            }
            memset(a,0,sizeof(a));
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(!strcmp(s[j],t[k]))
                        a[j][k]=1;
            if(match()==n)
                ans=min(ans,cnt);
             for(int j=0;j<l;j++)
            {
                if(i&(1<<j))
                {
                    cnt++;
                    for(int k=0;k<n;k++)
                        if(s[k][j]=='1')
                            s[k][j]='0';
                        else
                            s[k][j]='1';
                }
            }
        }
        if(ans<INF)
        printf("Case #%d: %d\n",cot++,ans);
        else
            printf("Case #%d: NOT POSSIBLE\n",cot++);
    }
}
