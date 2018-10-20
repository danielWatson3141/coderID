#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define T 130
#define N 1010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
vector< pair<int,int> > v;
int lb( int x ){ return x&(-x); }
int t , n , BIT[ T ][ N ] , pr[ T ][ N ] , ans[ T ];
void insert( int no , int x ){
    while( x <= n ) BIT[ no ][ x ] ++ , x += lb( x );
}
int query( int no , int x ){
    int sum = 0;
    while( x ) sum += BIT[ no ][ x ] , x -= lb( x );
    return sum;
}
void init( int no ){
    n = getint();
    for( int i = 0 ; i < n ; i ++ )
        pr[ no ][ i ] = getint();
}
void solve( int no ){
    int tans = 0;
    for( int i = n - 1 ; i >= 0 ; i -- ){
        tans += query( no , pr[ no ][ i ] + 1 );
        insert( no , pr[ no ][ i ] + 1 );
    }
    v.push_back( make_pair( tans , no ) );
}
void print(){
    std::sort( v.begin() , v.end() );
    for( int i = 1 ; i <= t ; i ++ )
        if( v[ i ].first > 250000 ) ans[ v[ i ].second ] = 1;
        else ans[ v[ i ].second ] = 0;
    for( int i = 1 ; i <= t ; i ++ )
        printf( "Case #%d: %s\n" , i , ans[ i ] ? "GOOD" : "BAD" );
}
int main(){

    freopen( "C-small-attempt3.in" , "r" , stdin );
    freopen( "C-small-attempt3.out" , "w" , stdout );

    t = getint();
    for( int i = 1 ; i <= t ; i ++ ){
        init( i );
        solve( i );
    }
    print();

    fclose( stdin ); fclose( stdout );
}
