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

#define MAX 300007

long N,L;
vector<string> str1,str2;
long ans;

void check( long I,long c )
{
    if( I==L ){
        sort( ALL( str1 ) );
        if( str1==str2 ) ans = min( ans,c );
        return;
    }
    check( I+1,c );
    long i;
    for( i=0;i<N;i++ ){
        if( str1[i][I]=='0' ) str1[i][I] = '1';
        else str1[i][I] = '0';
    }
    c++;
    check( I+1,c );
    c--;
    for( i=0;i<N;i++ ){
        if( str1[i][I]=='0' ) str1[i][I] = '1';
        else str1[i][I] = '0';
    }
}

int main( void )
{
    long i,j,u,v,Icase,k=0;

    //freopen("text1.txt","r",stdin );
    freopen("a.in","r",stdin );
    freopen("a.out","w",stdout );

    cin>>Icase;
    while( Icase-- ){
        cin>>N>>L;
        str1.clear();
        str2.clear();
        string s;
        for( i=0;i<N;i++ ){
            cin>>s;
            str1.pb( s );
        }
        for( i=0;i<N;i++ ){
            cin>>s;
            str2.pb( s );
        }
        sort( ALL( str2 ) );
        ans = INF;
        i = 0;
        check( 0,i );
        if( ans<INF ) printf("Case #%ld: %ld\n",++k,ans );
        else printf("Case #%ld: NOT POSSIBLE\n",++k );
    }

    return 0;
}
