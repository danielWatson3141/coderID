// Google Code Jam Template by rabbit125 @2014/02/13
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <bits/stdc++.h>
using namespace std ;
/* Define Useful Vars. */
#define ULL  unsigned long long
#define LLI  long long
#define BIT         17
#define INF 1000000000
#define MOD 1000000007
#define MAX        500
int N , L ;
LLI Dis[ MAX ][ MAX ] ;
char  I[ MAX ][ 500 ] ;
char  R[ MAX ][ 500 ] ;
int use[ MAX ] ;
int Ans ;
LLI Val ;
LLI Cmp[ MAX ] ;
LLI F( int a , int b )
{
    LLI r = 0 ;
    LLI B = 1 ;
    for( int i = 0 ; i < L ; i++ )
    {
        if( I[a][i] != R[b][i] )
            r += B ;
        B *= 2 ;
    }
    //printf( "%s %s / %lld\n" , I[a] , R[b] , r ) ;
    return r ;
}
void BK( int NowN )
{
    //printf( "%d\n" , NowN ) ;
    if( Ans < __builtin_popcount( Val ) )
        return ;
    if( NowN == N )
    {
        Ans = min( Ans , __builtin_popcount( Val ) ) ;
        //printf( "%d\n" , __builtin_popcount( Val ) ) ;
        return ;
    }
    for( int i = 0 ; i < N ; i++ )
        if( use[i] == 0 )
        {
            if( NowN == 0 )
                Val = Cmp[i] ;
            use[i] = 1 ;
            if( Dis[NowN][i] == Val )
                BK( NowN+1 ) ;
            use[i] = 0 ;
        }
}
int main( )
{
    freopen( "A-small-attempt0.in" , "r" , stdin ) ;
    freopen( "A-s0.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        scanf( "%d%d" , &N , &L ) ;
        for( int i = 0 ; i < N ; i++ )
            scanf( "%s" , I[i] ) ;
        for( int i = 0 ; i < N ; i++ )
            scanf( "%s" , R[i] ) ;
        for( int i = 0 ; i < N ; i++ )
            for( int j = 0 ; j < N ; j++ )
            {
                Dis[i][j] = F( i , j ) ;
                if( i == 0 )
                    Cmp[j] = Dis[i][j] ;
            }
        Ans = MAX ;
        //sort( Cmp , Cmp+N ) ;
        //for( int i = 0 ; i < N ; i++ )
        {
            //Val = Cmp[i] ;
            //printf( "vvv %lld\n" , Val ) ;
            memset( use , 0 , sizeof( use ) ) ;
            BK( 0 ) ;
        }
        if( Ans != MAX )
            printf( "Case #%d: %d\n" , T++ , Ans ) ;
        else
            printf( "Case #%d: NOT POSSIBLE\n" , T++ ) ;
    }
    return 0 ;
}
/*
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
*/
/*
Case #1: 1
Case #2: NOT POSSIBLE
Case #3: 0
*/
