#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
#define repb(i,b,n) for (int b__=b,n__=n,i=b__;i<=n__;i++)

const int mN=150+5;
long long a[mN],b[mN],c[mN];
void ch(string s,long long &x)
{
    x=0;
    repb(i,0,s.size()-1)
    {
        x=x*2+(s[i]-'0');
    }
}

int t1(long long k)
{
    int ans=0;
    while (k>0)
    {
        if (k%2==1)
            ans++;
        k/=2;
    }
    return ans;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int tz,ta;
    cin>>ta;
    int n,l;
    string x;
    repb(tz,1,ta)
    {
        printf("Case #%d: ",tz);
        int ans=10000;
        cin>>n>>l;
        repb(i,1,n)
        {
            cin>>x;
            ch(x,a[i]);
        }
        repb(i,1,n)
        {
            cin>>x;
            ch(x,b[i]);
        }
        sort(a+1,a+n+1);

        repb(i,1,n)
        {

            int k=a[1]^b[i];
            repb(j,1,n)
                c[j]=k^b[j];

            sort(c+1,c+n+1);
            bool fans=true;

            repb(j,1,n)
                if (c[j]!=a[j])
                {
                    fans=false;

                    break;
                }


            if (fans)
            {

                ans=min(ans,t1(k));
            }

        }
        if (ans>l)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
