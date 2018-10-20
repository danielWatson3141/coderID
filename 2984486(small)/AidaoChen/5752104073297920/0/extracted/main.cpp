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
int a[mN];
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int ta,tz;
    cin>>ta;
    rep(tz,ta)
    {
        int n,tt=0;
        cin>>n;
        rep(i,n)
            cin>>a[i];
        double avg=(n*(n-1))/4.0;
        rep(i,n)
            repb(j,i+1,n)
                if (a[i]<a[j])
                    tt++;
        bool ans;
        if (tt>=avg*0.95 && tt<=avg*1.05)
            ans=true;
        else
            ans=false;
        printf("Case #%d: %s\n",tz,(!ans)?"BAD":"GOOD");
    }
    return 0;
}
