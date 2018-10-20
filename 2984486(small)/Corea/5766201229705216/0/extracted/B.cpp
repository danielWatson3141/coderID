#include <stdio.h>
#include <vector>

using namespace std;

int N;

bool Visit[ 1003 ];

vector<int> edge[ 1003 ];

// count of node, dp value
pair<int, int> make_full( int root ) {
    Visit[ root ] = true;

    pair<int, int> ret( 1, 0 );
    vector<int> lst;

    for( auto& x : edge[ root ] ) {
        if( Visit[ x ] ) {
            continue;
        }
        pair<int, int> value = make_full( x );
        ret.first += value.first;
        ret.second += value.second;
        lst.push_back( value.first - value.second );
    }
    if( lst.size() == 1 ) {
        ret.second = ret.first - 1;
    }
    if( lst.size() > 2 ) {
        sort( lst.begin(), lst.end() );
        for( int i = 0; i < lst.size() - 2; i ++ ) {
            ret.second += lst[ i ];
        }
    }
    return ret;
}

int main() {
    int T;
    scanf( "%d", &T );
    for( int test = 1; test <= T; test ++ ) {
        scanf( "%d", &N );
        for( int i = 1; i < N; i ++ ) {
            int a, b;
            scanf( "%d %d", &a, &b );
            edge[ a ].push_back( b );
            edge[ b ].push_back( a );
        }

        int result = N;
        for( int i = 1; i <= N; i ++ ) {
            pair<int, int> ret = make_full( i );
            if( result > ret.second ) {
                result = ret.second;
            }
            memset( Visit, 0, sizeof( Visit ) );
        }
        printf( "Case #%d: %d\n", test, result );

        for( int i = 1; i <= N; i ++ ) {
            edge[ i ].clear();
        }
    }

    return 0;
}
