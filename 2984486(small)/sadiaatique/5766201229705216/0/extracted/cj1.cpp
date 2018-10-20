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

int deg[20];
vector<int>v[20];
int ddeg[20];
bool bi[20];
bool df[20];

int h;

void dfs(int i)
{
    h++;
    df[i]=true;
    //cout<<"now at "<<i<<endl;
    for(int a=0;a<v[i].size();a++)
    {
        if( !df[ v[i][a] ] && !bi[ v[i][a] ]) dfs(v[i][a]);
    }
}

int main()
{
    freopen("0.in","r",stdin);
    freopen("0.out","w",stdout);

    int a,b,c,d,e,x,y,z,t,n,l;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>n;

        for(a=1;a<=n;a++) v[a].clear();

        for(a=0;a<n-1;a++)
        {
            cin>>b>>c;
            v[b].push_back(c);
            v[c].push_back(b);
        }
        if(n==2)
        {
            //cout<<1<<" "<<v[1][0]<<endl;
            printf("Case #%d: 1\n",i);
            continue;
        }
        int ans=-1;

        for(a=0;a<(1<<n);a++)
        {
            d=0;

            for(b=1;b<=n;b++) bi[b]=false;

            //cout<<"Now at "<<a<<endl;

            for(b=0;b<n;b++)
            {
                if( (a&(1<<b)) )
                {
                    d++;
                    bi[b+1]=true;
                    //cout<<"blocking "<<b+1<<endl;
                }
            }
            for(b=1;b<=n;b++)
            {
                if(bi[b]) continue;
                deg[b]=0;
                for(c=0;c<v[b].size();c++)
                {
                    if(!bi[ v[b][c] ]) deg[b]++;
                }
            }
            h=0;
            z=0;
            for(b=1;b<=n;b++)
            {
                if(bi[b]) continue;

                if(deg[b]==2)
                {
                    h=0;
                    for(c=1;c<=n;c++) df[c]=false;
                    z=1;
                    dfs(b);
                    //cout<<"DFS from "<<b<<endl;
                    break;
                }
            }
            if(h==n-d && z==1)
            {
                for(c=1;c<=n;c++)
                {
                    if(b==c) continue;
                    if(bi[c]) continue;
                    if(deg[c]==1 || deg[c]==3) continue;
                    break;
                }
                if(c==n+1)
                {
                    if(ans==-1) ans=d;
                    else ans=min(ans,d);
                }
            }
        }

        printf("Case #%d: ",i);
        if(ans==-1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
