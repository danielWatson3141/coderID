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
#define MAX       1200
int N , ans ;
int u[ MAX ] ;
int s[ MAX ] ;
vector <int> E[ MAX ] ;
int DFS( int Now )
{
    int Sz = (int)E[Now].size() ;
    int Ct = 0 ;
    int Ns = 0 ;
    int r  = 0 ;
    u[Now] = 1 ;
    for( int i = 0 ; i < Sz ; i++ )
    {
        if( u[E[Now][i]] == 0 )
        {
            Ct += DFS( E[Now][i] ) ;
            s[Now] += s[E[Now][i]] ;
            Ns++ ;
        }
    }
    s[Now] += 1 ;
    //printf( "Now %d %d %d\n" , Now , Ns , s[Now] ) ;
    if( Ns == 0 )
        return 0 ;
    else if( Ns == 1 )
        return s[Now]-1 ;
    else if( Ns == 2 )
        return Ct ;
}
int main( )
{
    //freopen( "B-small-attempt2.in" , "r" , stdin ) ;
    //freopen( "B-s2.out" , "w" , stdout ) ;
    int t , T = 1 ;
    int a , b ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {
        for( int i = 0 ; i < MAX ; i++ )
            E[ i ].clear( ) ;
        scanf( "%d" , &N ) ;
        for( int i = 0 ; i < N-1 ; i++ )
        {
            scanf( "%d%d" , &a , &b ) ;
            E[ a-1 ].push_back( b-1 ) ;
            E[ b-1 ].push_back( a-1 ) ;
        }
        ans = MAX ;
        for( int i = 0 ; i < N ; i++ )
        {
            memset( u , 0 , sizeof( u ) ) ;
            for( int j = 0 ; j < N ; j++ )
                s[j] = 0 ;
            int Ta = DFS( i ) ;
            ans = min( ans , Ta ) ;
            //printf( "aa %d %d\n\n" , i , Ta ) ;
        }
        printf( "Case #%d: %d\n" , T++ , ans ) ;
    }
    return 0 ;
}
/*
3
7
4 5
4 2
1 2
3 1
6 4
3 7
3
2 1
1 3
4
1 2
2 3
3 4
*/
/*
Case #1: 0
Case #2: 2
Case #3: 1
*/
