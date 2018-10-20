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

string device[50],outlet[50];
string demo[50];
bool bi[50];

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

        for(a=0;a<(1<<l);a++)
        {
            d=0;

            for(b=0;b<n;b++){ demo[b]=outlet[b]; bi[b]=false; }

            for(b=0;b<l;b++)
            {
                if( (a& (1<<b)) )
                {
                    d++;

                    for(c=0;c<n;c++)
                    {
                        if(demo[c][b]=='0') demo[c][b]='1';
                        else demo[c][b]='0';
                    }
                }
            }

            for(b=0;b<n;b++)
            {
                for(c=0;c<n;c++)
                {
                    if(demo[c]==device[b] && bi[c]==false)
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
