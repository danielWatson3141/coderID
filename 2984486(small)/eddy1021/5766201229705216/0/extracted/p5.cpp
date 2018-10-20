#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1010
int getint(){
    int x=0; char c=getchar();
    while( c<'0'||c>'9' ) c=getchar();
    while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
    return x;
}
vector<int> r[ N ];
int t , n , cnt[ N ] , ans , tans , cs;
void init(){
    ans = n = getint();
    for( int i = 1 ; i <= n ; i ++ )
        r[ i ].clear();
    for( int i = 1 ; i < n ; i ++ ){
        int a , b;
        a = getint(); b = getint();
        r[ a ].push_back( b );
        r[ b ].push_back( a );
    }
}
void DFS( int now , int pre ){
    int chdsz[ N ];
    int chd = 0 , tcnt = 0;
    for( int i = 0 ; i < r[ now ].size() ; i ++ )
        if( r[ now ][ i ] != pre ){
            DFS( r[ now ][ i ] , now );
            tcnt += cnt[ r[ now ][ i ] ];
            chdsz[ chd ] = cnt[ r[ now ][ i ] ];
            chd ++;
        }
    std::sort( chdsz , chdsz + chd );
    if( chd == 1 ) tans += tcnt , cnt[ now ] = 1;
    else if( chd > 2 ){
        tans += tcnt - chdsz[ chd - 1 ] - chdsz[ chd - 2 ];
        cnt[ now ] = chdsz[ chd - 1 ] + chdsz[ chd - 2 ] + 1;
    }else cnt[ now ] = tcnt + 1;
    return;
}
void solve(){
    for( int i = 1 ; i <= n ; i ++ ){
        tans = 0;
        for( int j = 1 ; j <= n ; j ++ )
            cnt[ j ] = 0;
        DFS( i , -1 );
        if( tans < ans )
            ans = tans;
    }
    printf( "Case #%d: %d\n" , ++ cs , ans );
}
int main(){

    freopen( "B-small-attempt1.in" , "r" , stdin );
    freopen( "B-small-attempt1.out" , "w" , stdout );

    t = getint(); while( t -- ){
        init();
        solve();
    }

    fclose( stdin ); fclose( stdout );
}
