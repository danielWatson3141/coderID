#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int n,l,f[2][155],now,ans,g[55],maxn;
char s[55];

void dfs(int now,int sum)
{
    if(sum>=ans)return;
    sort(f[0],f[0]+n);
    for(int i=0;i<n;i++)
        if((f[0][i]&g[now+1])!=(f[1][i]&g[now+1]))return;
    if(now==-1)
    {
        if(sum<ans)ans=sum;
        return;
    }
    dfs(now-1,sum);
    for(int i=0;i<n;i++)
        f[0][i]^=1<<now;
    dfs(now-1,sum+1);
    for(int i=0;i<n;i++)
        f[0][i]^=1<<now;
}

int main()
{
    //freopen("a-in.txt","r",stdin);
    //freopen("a-out.txt","w",stdout);
    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("A-small-output1.txt","w",stdout);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&n,&l);
        for(int k=0;k<2;k++)
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            f[k][i]=0;
            for(int j=0;j<l;j++)
                f[k][i]|=(s[j]-'0')<<j;
        }
        maxn=(1<<l)-1;
        g[l]=0;
        for(int i=l-1;i>=0;i--)
            g[i]=g[i+1]|(1<<i);
        sort(f[1],f[1]+n);
        ans=l+5;
        dfs(l-1,0);
        if(ans<=l)printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: NOT POSSIBLE\n",cas);
    }
    return 0;
}
