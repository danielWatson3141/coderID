#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 150
string c[ 2 ][ N ] , b[ N ];
//char c[ 2 ][ N ][ N ];
int t , n , l , cs , cnt[ 2 ][ N ] , ans;
void init(){
    scanf( "%d%d" , &n , &l ); ans = -1;
    for( int i = 0 ; i < 2 ; i ++ )
        for( int j = 0 ; j < n ; j ++ )
            cin >> c[ i ][ j ];
    std::sort( c[ 1 ] , c[ 1 ] + n );
}
void solve(){
    printf( "Case #%d: " , ++ cs );
    int ans = -1;
    for( int i = 0 ; i < n ; i ++ ){
        bool flag[ N ] = {}; int flip = 0;
        for( int j = 0 ; j < l ; j ++ )
            if( c[ 0 ][ i ][ j ] != c[ 1 ][ 0 ][ j ] )
                flag[ j ] = true , flip ++;
        for( int j = 0 ; j < l ; j ++ ) if( flag[ j ] )
           for( int k = 0 ; k < n ; k ++ )
                if( c[ 0 ][ k ][ j ] == '1' ) c[ 0 ][ k ][ j ] = '0';
                else c[ 0 ][ k ][ j ] = '1';
        for( int j = 0 ; j < n ; j ++ )
            b[ j ] = c[ 0 ][ j ];
        for( int j = 0 ; j < l ; j ++ ) if( flag[ j ] )
           for( int k = 0 ; k < n ; k ++ )
                if( c[ 0 ][ k ][ j ] == '1' ) c[ 0 ][ k ][ j ] = '0';
                else c[ 0 ][ k ][ j ] = '1';
        std::sort( b , b + n );
        bool tflag = true;
        for( int k = 0 ; k < n ; k ++ )
            if( b[ k ] != c[ 1 ][ k ] ){
                tflag = false; break;
            }
        if( tflag ){
            if( ans == -1 || flip < ans )
                ans = flip;
        }
    }
    if( ans == -1 ) puts( "NOT POSSIBLE" );
    else printf( "%d\n" , ans );
}
int main(){

    freopen( "A-large.in" , "r" , stdin );
    freopen( "A-large.out" , "w" , stdout );

    scanf( "%d" , &t ); while( t -- ){
        init();
        solve();
    }

    fclose( stdin ); fclose( stdout );
}
