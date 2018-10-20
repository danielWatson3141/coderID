#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

using namespace std;

const int nm=152;
const int lm=42;

int n,l;
ll a[nm],b[nm],c[nm];
ll f[nm][lm];
set<ll> x;

ll batbit(ll i,ll j)
{
    return (1ll<<j)|i;
}

int sobit(ll x)
{
    int kq=0;
    while (x)
    {
        kq+=x%2ll;x/=2ll;
    }
    return kq;
}

int kt(ll x)
{
    int i;
    for(i=1;i<=n;++i) c[i]=a[i]^x;
    sort(c+1,c+n+1);
    for(i=1;i<=n;++i) if (c[i]!=b[i]) return 100;
    return sobit(x);
}

int main()
{
    freopen("a-small-attempt1.in","r",stdin);
    freopen("vd.out","w",stdout);
    int t,i,j,kq;set<ll>::iterator it;char tg[152];
    scanf("%d",&t);
    for(int ti=1;ti<=t;++ti)
    {
        scanf("%d%d",&n,&l);
        for(i=1;i<=n;++i)
        {
            scanf("%s",tg);
            a[i]=0;
            for(j=0;j<l;++j) a[i]=a[i]*2ll+(ll)(tg[j]-48ll);
        }
        for(i=1;i<=n;++i)
        {
            scanf("%s",tg);
            b[i]=0;
            for(j=0;j<l;++j) b[i]=b[i]*2ll+(ll)(tg[j]-48ll);
        }
        sort(b+1,b+n+1);
        x.clear();
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                f[i][j]=a[i]^b[j];
                x.insert(f[i][j]);
            }
        }
        kq=100;
        for(it=x.begin();it!=x.end();++it) kq=min(kq,kt(*it));
        printf("Case #%d: ",ti);
        if (kq==100) printf("NOT POSSIBLE\n");else printf("%d\n",kq);
    }
}
