#include <stdio.h>
#include <vector>

typedef std::vector< int > IntVec;

int const MAXN = 1024;

int n;
IntVec g[MAXN];
int d[MAXN][MAXN];

int calc1( int i, int parent )
{
    if( d[i][parent] != -1 )
        return d[i][parent];
    
    int res = 1;
    
    int maxl = -1, l = -1;
    for( int j = 0; j < (int)g[i].size(); ++ j )
    {
        int v = g[i][j];
        if( v != parent )
        {
            int t = calc1( v, i );
            if( t > maxl )
            {
                maxl = t;
                l = v;
            }
        }
    }

    if( l != -1 )
    {
        int maxr = -1, r = -1;
        for( int j = 0; j < (int)g[i].size(); ++ j )
        {
            int v = g[i][j];
            if( v != parent && v != l )
            {
                int t = calc1( v, i );
                if( t > maxr )
                {
                    maxr = t;
                    r = v;
                }
            }
        }

        if( r != -1 )
            res += maxl + maxr;
    }

    return res;
}

int solve()
{
    memset( d, -1, sizeof(d) );
    int max = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int t = calc1( i, 0 );
        if( t > max )
            max = t;
    }

    return n - max;
}

int main()
{
    //freopen( "in.txt", "rt", stdin );

    int tests;
    scanf( "%d", &tests );
    for( int test = 1; test <= tests; ++ test )
    {
        scanf( "%d", &n );

        for( int i = 0; i < MAXN; ++ i )
            g[i].clear();
        
        for( int i = 0; i < n - 1; ++ i )
        {
            int x, y;
            scanf( "%d %d", &x, &y );

            g[x].push_back( y );
            g[y].push_back( x );
        }

        int ans = solve();

        printf( "Case #%d: %d\n", test, ans );
    }

    return 0;
}
