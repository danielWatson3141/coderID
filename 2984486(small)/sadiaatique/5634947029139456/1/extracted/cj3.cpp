#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>
#define ll long long
using namespace std;

string device[250],outlet[250];
string demo[250];
bool bi[250];

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t,n,l;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>n>>l;
        string s,st;

        for(a=0;a<n;a++) cin>>outlet[a];
        for(a=0;a<n;a++) cin>>device[a];

        int ans=-1;

        for(a=0;a<n;a++)
        {
            d=0;

            for(b=0;b<n;b++) demo[b]=outlet[b];

            for(b=0;b<l;b++)
            {
                if(device[0][b]!=demo[a][b])
                {
                    d++;
                    for(c=0;c<n;c++)
                    {
                        if(demo[c][b]=='0') demo[c][b]='1';
                        else demo[c][b]='0';
                    }
                }
            }

            for(b=0;b<n;b++) bi[b]=false;
            bi[a]=true;

            for(b=1;b<n;b++)
            {
                for(c=0;c<n;c++)
                {
                    if(bi[c]) continue;
                    if(device[b]==demo[c])
                    {
                        bi[c]=true;
                        break;
                    }
                }
                if(c==n) break;
            }
            if(b==n)
            {
                if(ans==-1) ans=d;
                else ans=min(ans,d);
            }
        }

        printf("Case #%d: ",i);
        if(ans==-1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
