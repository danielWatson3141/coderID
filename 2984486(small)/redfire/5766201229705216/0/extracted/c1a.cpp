/* @author Ishita Gupta*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector< vi >
#define vs vector<string>
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fori(s,e) for(int i=s;i<=e;i++)
#define forj(s,e) for(int j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define aa first
#define bb second
using namespace std;
int ind[1003];
bool vis[1003];
vvi adj;
int countt;
void dfs ( int u,int mask )
{
    //cout<<u<<" ";
    vis[u]=1;
    int sz=adj[u].size(),child=0,tot=0;
    vi children;
    fori ( 0,sz-1 )
    {
        int v=adj[u][i];
        if ( !vis[v] &&( (1<<(v-1))&mask ))
        {
            children.pb ( v );
            child++;
        }
    }
    countt++;
    if (child==2)
    {
        fori ( 0,child-1 ) dfs ( children[i],mask );
    }
}
int main()
{
    ios::sync_with_stdio ( false );
    int t,i,j,k,m,n,x,y;
    freopen ( "B-small-attempt2.in","r",stdin );
    freopen ( "B-small20.txt","w",stdout );
    cin>>t;
    rep ( T,1,t )
    {
        adj.clear();
        cin>>n;
        mem ( ind,0 );
        adj.resize ( n+2 );
        vi roots;
        fori ( 1,n-1 )
        {
            cin>>x>>y;
            adj[x].pb ( y );
            adj[y].pb ( x );
        }
        /*fori ( 1,n )
        {
            if ( adj[i].size() <=2 )
            {
                roots.pb ( i );
            }
        }
        int r=roots.size();
        int ans=n-1;
        fori ( 0,r-1 )
        {
            int root=roots[i];
            mem ( vis,0 );
            countt=0;
            dfs ( root );
            cout<<"root=  "<<root<<endl;
            ans=min ( ans,n-countt );
           // cout<<root<<" "<<countt<<" "<<ans<<endl;
        }*/
        int ans=n-1;
        int tot= ( 1<<n )-1;
        fori ( 0,tot )
        {
            int mask=i;
            forj ( 0,n-1 )
            {
                if ( ( 1<<j ) &mask ) //j is root
                {
                    mem ( vis,0 );
                    countt=0;
                    dfs ( j+1,mask );
                    ans=min ( ans,n-countt );
                }
            }
        }
        printf ( "Case #%d: ",T );
        printf ( "%d\n",ans );
    }
    return 0;
}

