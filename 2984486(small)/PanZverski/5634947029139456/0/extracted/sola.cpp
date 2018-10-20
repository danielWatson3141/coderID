#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

int const MAXN = 128;

int n, l;
long long S[MAXN], D[MAXN];

long long read()
{
    char str[64];
    scanf( "%s", str );
    long long res = 0, mask = 1;
    for( int i = l - 1; i >= 0; -- i, mask <<= 1 )
        if( str[i] == '1' )
            res |= mask;
    return res;
}

int calc( long long sol )
{
    long long t[MAXN];
    for( int i = 0; i < n; ++ i )
        t[i] = S[i] ^ sol;

    std::sort( t, t + n );

    if( memcmp( t, D, sizeof(long long) * n ) != 0 )
        return -1;

    int cnt = 0;
    while( sol > 0 )
    {
        if( ( sol & 1 ) != 0 )
            ++ cnt;
        sol /= 2;
    }
    return cnt;
}

int solve()
{
    int min = -1;
    for( int i = 0; i < n; ++ i )
    {
        long long sol = S[i] ^ D[0];
        int res = calc( sol );
        if( res != -1 && ( min == -1 || min > res ) )
            min = res;
    }
    return min;
}

int main()
{
    int tests;
    scanf( "%d", &tests );
    for( int test = 1; test <= tests; ++ test )
    {
        scanf( "%d %d", &n, &l );
        for( int i = 0; i < n; ++ i )
            S[i] = read();
        for( int i = 0; i < n; ++ i )
            D[i] = read();

        std::sort( D, D + n );

        int ans = solve();

        printf( "Case #%d: ", test );
        if( ans != -1 )
            printf( "%d\n", ans );
        else
            printf( "NOT POSSIBLE\n" );
    }

    return 0;
}
