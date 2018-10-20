// AUTHOR : SIKANDER MAHAN
// sikander_nsit
// PLAGIARISM IS BAD

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define itor(c) typeof(c.begin())
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define msi multiset<int>
#define ii pair<int,int>
#define sii set<ii>
#define vii vector<ii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair

using namespace std;

vector<int> adj[1001];
bool vis[1002];

int dfs(int node)
{
    int i,k,j=0;
    vi v;
    k=adj[node].size();
    for(i=0;i<k;++i)
        if(vis[adj[node][i]]==false)
        ++j;
    vis[node]=true;
    if(j<2)
        return 1;
    for(i=0;i<k;++i)
    {
        if(vis[adj[node][i]]==false)
        {
            v.pb(dfs(adj[node][i]));
        }
    }
    sort(all(v),greater<int>());
    return (v[0]+v[1]+1);
}

int main()
{
    //ios::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t=0,i=0,j=0,n=0,m=0,k=0,num=0,temp=0,ans=0,a,b;
    cin>>t;
    string str;
    for(i=0;i<t;++i)
    {
        cin>>n;
        ans=n-1;
        for(j=1;j<=n;++j)
            adj[j].clear();
        for(j=1;j<n;++j)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(j=1;j<=n;++j)
        {
            //memset(vis,0,sizeof(vis));
            for(k=0;k<=n;++k)
                vis[k]=false;
            num=dfs(j);
            temp=n-num;
            ans=min(ans,temp);
        }
        cout<<"Case #"<<i+1<<": "<<ans<<"\n";
    }
	return 0;
}
