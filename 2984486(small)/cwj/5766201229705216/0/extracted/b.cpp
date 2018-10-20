#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;

bool b[1005];
int T,N,s[1005],f[1005];
vector<int> edg[1005];

void dfs(int id)
{
    b[id]=1;
    int fir=0,sec=0;
    s[id]=1;
    f[id]=1;
    for(int i=0;i<edg[id].size();i++)
    {
        int tag=edg[id][i];
        if(b[tag]) continue;
        dfs(tag);
        s[id]+=s[tag];
        if(f[tag]>fir)
        {
            sec=fir;
            fir=f[tag];
        }
        else
        {
            sec=max(sec,f[tag]);
        }
    }
    if(s[id]==1)
    {
        return;
    }
    else
    {
        if(sec>0)
        {
            f[id]+=(fir+sec);
        }
        return;
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>N;
        for(int i=1;i<=N;i++)
        {
            edg[i].clear();
        }
        for(int i=1;i<N;i++)
        {
            int x,y;
            cin>>x>>y;
            edg[x].push_back(y);
            edg[y].push_back(x);
        }
        int ans=10000;
        for(int i=1;i<=N;i++)
        {
            memset(b,0,sizeof(b));
            memset(s,0,sizeof(s));
            memset(f,0,sizeof(f));
            dfs(i);
            ans=min(ans,N-f[i]);
        }
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}
