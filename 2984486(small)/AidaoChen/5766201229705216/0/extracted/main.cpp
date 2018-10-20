#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
#define repb(i,b,n) for (int b__=b,n__=n,i=b__;i<=n__;i++)

#define rep(i,n) for (int n__=n,i=1;i<=n__;i++)

const int mN=1000+10;
vector<int> tr[mN];
int sum[mN],shan[mN];

void dfs(int x,int fa)
{
    vector<int>::iterator ch=tr[x].begin();
    sum[x]=1;
    int tson=0,a[2]={0,0};
    while (ch!=tr[x].end())
    {
        int son=*ch;
        if ((son)!=fa)
        {
            dfs(son,x);
            sum[x]+=sum[son];
            tson++;
            int bl=sum[son]-shan[son];
            if (bl>a[0])
                a[1]=a[0],a[0]=bl;
            else
                if (bl>a[1])
                a[1]=bl;
        }
        ch++;
    }
    if (tson==0)
    {
        shan[x]=0;
        return;
    }
    else
        if (tson==1)
    {
        shan[x]=sum[x]-1;
        return;
    }
    else
        if (tson>=2)
    {
        shan[x]=sum[x]-1-a[0]-a[1];
        return;
    }
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int ta,tz;
    cin>>ta;
    rep(tz,ta)
    {

        int n,x,y;
        cin>>n;

        rep(i,n)
            tr[i].clear();
        rep(i,n-1)
        {
            cin>>x>>y;
            tr[x].push_back(y);
            tr[y].push_back(x);
        }

        int ans=10000000;
        rep(i,n)
        {
            memset(sum,0,sizeof(sum));
            memset(shan,0,sizeof(shan));
            dfs(i,0);
            ans=min(ans,shan[i]);
        }
        printf("Case #%d: %d\n",tz,ans);
    }
    return 0;
}
