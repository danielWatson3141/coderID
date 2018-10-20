#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define FO(it,c) for ( __typeof( (c).begin() )it=(c).begin(); it!=(c).end();it++ )

int n;
vector<int> v[1005];
int p[1005];
int dn[1005];

int dfs(int nw)
{
    dn[nw]=1;
    int chd=0,lg1=0,lg2=0;
    FO(it,v[nw])if (*it!=p[nw])
    {
        chd++;
        p[*it]=nw;
        int tmp=dfs(*it);
        if (dn[*it]-tmp>lg1)lg2=lg1,lg1=dn[*it]-tmp;
        else if (dn[*it]-tmp>lg2)lg2=dn[*it]-tmp;
        dn[nw]+=dn[*it];
    }
    if (chd==0)return 0;
    if (chd==1)
    {
        return dn[nw]-1;
    }
    //printf("(%d %d %d)\n",nw,lg1,lg2);
    return dn[nw]-1-lg1-lg2;
}

void SOLVE()
{
    for (int i=0;i<1005;i++)v[i].clear();

    scanf("%d",&n);
    int a,b;
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int ans=1000000;
    for (int i=1;i<=n;i++)
    {
        memset(p,-1,sizeof p);
        int tmp=dfs(i);
        //printf("  %d\n",tmp);
        ans=min(ans,tmp);//printf("Y\n");
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int amm;
    scanf("%d",&amm);
    for (int cnt=1;cnt<=amm;cnt++)
    {
        printf("Case #%d: ",cnt);
        SOLVE();
    }
    return 0;
}
