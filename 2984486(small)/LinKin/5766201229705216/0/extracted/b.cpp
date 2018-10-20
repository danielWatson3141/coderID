#pragma comment(linker, "/STACK:16777216")

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<list>
using namespace std;

#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define SZ(a) ((long)a.size())
#define ALL(a) a.begin(),a.end()
#define FOREACH(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define AREA2(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define SQR(x) ((x)*(x))
#define STR string
#define IT iterator
#define ff first
#define ss second
#define MP make_pair
#define EPS 1e-9
#define INF 1000000007

#define chk(a,k) ((bool)(a&(1<<(k))))
#define set0(a,k) (a&(~(1<<(k))))
#define set1(a,k) (a|(1<<(k)))

typedef long long Long;
typedef vector<long> Vl;
typedef vector<Long> VL;
typedef pair<long,long> Pll;
typedef pair<Long,Long> PLL;

inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }

long IR[] = { 0,-1,0,1,-1,-1,1,1 };
long IC[] = { 1,0,-1,0,1,-1,-1,1 };

#define MAX 1007

long N;
vector<long> ed[MAX+7];
long vi[MAX+7],TRUE;
long mn[MAX+7];
long sz[MAX+7];

void dfs( long u,long p )
{
    if( !ed[u].size() ){
        mn[u] = 0;
        sz[u] = 1;
        return;
    }
    if( ed[u].size()==1 && ed[u][0]==p ){
        mn[u] = 0;
        sz[u] = 1;
        return;
    }
    if( vi[u]==TRUE ) return;
    vi[u] = TRUE;
    sz[u] = 1;
    vector<Pll> vc( 1 );
    long i;
    for( i=0;i<ed[u].size();i++ ){
        long v = ed[u][i];
        if( v==p ) continue;
        dfs( v,u );
        vc.pb( MP( mn[v],sz[v] ) );
        sz[u] += sz[v];
    }
    vector< Vl > sol( vc.size()+7 );
    sol[0].pb( 0 );
    sol[0].pb( INF );
    sol[0].pb( INF );
    for( i=1;i<vc.size();i++ ){
        sol[i].resize( 3 );
        sol[i][0] = sol[i-1][0] + vc[i].ss;
        sol[i][1] = min( sol[i-1][0]+vc[i].ff, sol[i-1][1]+vc[i].ss );
        sol[i][2] = min( sol[i-1][1]+vc[i].ff, sol[i-1][2]+vc[i].ss );
    }
    mn[u] = min( sol[vc.size()-1][0], sol[vc.size()-1][2] );
}

int main( void )
{
    long i,j,u,v,Icase,k=0;

    //freopen("text1.txt","r",stdin );
    freopen("b.in","r",stdin );
    freopen("b.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        cin>>N;
        for( i=1;i<N;i++ ){
            cin>>u>>v;
            ed[u].pb( v );
            ed[v].pb( u );
        }
        long ans = N;
        for( i=1;i<=N;i++ ){
            TRUE++;
            dfs( i,i );
            //printf("%ld %ld\n",i,mn[i] );
            ans = min( ans,mn[i] );
        }
        printf("Case #%ld: %ld\n",++k,ans );
        for( i=0;i<=N;i++ ){
            ed[i].clear();
        }
    }

    return 0;
}
