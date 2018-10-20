#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int N=300;
ll a[N],b[N];
vector<ll> v;

ll trunc(char s[])
{
    ll res=0;
    for (int i=0; s[i]; i++) res=res*2+(ll)(s[i]-'0');
    //cout<<res<<endl;
    return res;
}

int num(ll n)
{
    int ans=0;
    while (n)
    {
        if (n%2==1) ans++;
        n/=2;
    }
    return ans;
}

bool check(ll x,int n,int l)
{
    ll c[N];
    for (int i=1; i<=n; i++) c[i]=a[i]^x;
    sort(c+1,c+n+1);
    for (int i=1; i<=n; i++) if (b[i]!=c[i]) return false;
    return true;
}

int main()
{
    int o,n,l,cas=0;
    char s[100];
    scanf("%d",&o);
    while (o--)
    {
        scanf("%d%d",&n,&l);
        for (int i=1; i<=n; i++) {scanf("%s",s); a[i]=trunc(s);}
        for (int i=1; i<=n; i++) {scanf("%s",s); b[i]=trunc(s);}
        sort(b+1,b+n+1);
        v.clear();
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                v.push_back(a[i]^b[j]);
        int ans=-1;
        for (int i=0; i<v.size(); i++) if (check(v[i],n,l))
        {
            int s=num(v[i]);
            if (ans==-1 || ans>s) ans=s;
        }
        printf("Case #%d: ",++cas);
        if (ans==-1) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
}