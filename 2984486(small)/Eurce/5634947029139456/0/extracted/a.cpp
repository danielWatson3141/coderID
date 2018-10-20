#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define ll long long

ll t,n,m,a[150],b[150],c[40],d[40],e[40],tag,ans;
ll f[150];
char s[41];

void init()
{
    ll i,j,k,l;
    memset(c,0,sizeof c);
    memset(d,0,sizeof d);
    memset(e,0,sizeof e);
    tag=0;
    ans=m+1;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(j=a[i]=0;s[j];j++)
            a[i]=(a[i]<<1)+s[j]-'0';
    }
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        for(j=b[i]=0;s[j];j++)
            b[i]=(b[i]<<1)+s[j]-'0';
    }
    sort(b,b+n);
    for(i=1,j=0;j<m;i<<=1,j++)
    {
        for(k=0;k<n;k++)
        {
            if(a[k]&i)
                c[j]++;
            if(b[k]&i)
                d[j]++;
        }
        if(c[j]==d[j]&&c[j]!=n-d[j])
            e[j]=0;
        if(c[j]!=d[j]&&c[j]==n-d[j])
            e[j]=1;
        if(c[j]==d[j]&&c[j]==n-d[j])
            e[j]=2;
        if(c[j]!=d[j]&&c[j]!=n-d[j])
            tag=1;
    }
}

void dfs(ll i,ll j)
{
    if(j>=ans)
        return;
    if(i==m)
    {
        memcpy(f,a,sizeof f);
        sort(f,f+n);
        for(i=0;i<n&&f[i]==b[i];i++);
        if(i==n)
            ans=min(ans,j);
        return;
    }
    ll k,l;
    if(e[i]==0||e[i]==2)
        dfs(i+1,j);
    if(e[i]==1||e[i]==2)
    {
        for(k=0,l=1LL<<i;k<n;k++)
            a[k]^=l;
        dfs(i+1,j+1);
        for(k=0,l=1LL<<i;k<n;k++)
            a[k]^=l;
    }
}

void solve()
{
    ll i,j,k,l;
    printf("Case #%lld: ",++t);
    if(tag)
    {
        puts("NOT POSSIBLE");
        return;
    }
    dfs(0,0);
    if(ans==m+1)
    {
        puts("NOT POSSIBLE");
        return;
    }
    printf("%lld\n",ans);
}

int main()
{
    scanf("%*d");
    while(~scanf("%lld%lld",&n,&m))
    {
        init();
        solve();
    }
    return 0;
}
