#include <stdio.h>
#include <set>
#include <string>

using namespace std;

int N, L, result;

char device[ 153 ][ 43 ];
char electric[ 153 ][ 43 ];

int device_cnt[ 153 ];
int electric_cnt[ 153 ];

void flip( int depth ) {
    for( int i = 1; i <= N; i ++ ) {
        if( device[ i ][ depth ] == '1' ) {
            device[ i ][ depth ] = '0';
        } else {
            device[ i ][ depth ] = '1';
        }
    }
}

bool check( int depth ) {
    multiset<string> set_check;

    for( int i = 1; i <= N; i ++ ) {
        set_check.insert( electric[ i ] + depth );
    }
    for( int i = 1; i <= N; i ++ ) {
        if( set_check.find( device[ i ] + depth ) != set_check.end() ) {
            set_check.erase( set_check.find( device[ i ] + depth ) );
        } else {
            return false;
        }
    }
    return true;
}

bool process( int depth, int cnt ) {
    if( cnt >= result ) {
        return false;
    }
    if( depth == 0 ) {
        result = cnt;
        return false;
    }
    
    if( electric_cnt[ depth ] == device_cnt[ depth ] ) {
        if( check( depth ) && process( depth - 1, cnt ) ) {
            return true;
        }
    }
    if( electric_cnt[ depth ] == N - device_cnt[ depth ] ) {
        flip( depth );
        if( check( depth ) && process( depth - 1, cnt + 1 ) ) {
            return true;
        }
        flip( depth );
    }
    if( electric_cnt[ depth ] != device_cnt[ depth ] && 
        electric_cnt[ depth ] != N - device_cnt[ depth ] ) {
        printf( "NOT POSSIBLE\n" );
        return true;
    }

    return false;
}

int main() {
    int T;
    scanf( "%d", &T );
    for( int test = 1; test <= T; test ++ ){
        scanf( "%d %d", &N, &L );

        for( int i = 1; i <= N; i ++ ) {
            scanf( "%s", device[ i ] + 1 );
            for( int j = 1; j <= L; j ++ ) {
                if( device[ i ][ j ] == '1' ) {
                    device_cnt[ j ] ++;
                }
            }
        }

        for( int i = 1; i <= N; i ++ ) {
            scanf( "%s", electric[ i ] + 1 );
            for( int j = 1; j <= L; j ++ ) {
                if( electric[ i ][ j ] == '1' ) {
                    electric_cnt[ j ] ++;
                }
            }
        }

        printf( "Case #%d: ", test );
        result = L + 1;
        if( ! process( L, 0 ) ) {
            if( result == L + 1 ) {
                printf( "NOT POSSIBLE\n" );
            } else {
                printf( "%d\n", result );
            }
        }

        for( int i = 1; i <= L; i ++ ) {
            device_cnt[ i ] = 0;
            electric_cnt[ i ] = 0;
        }
        memset( device, 0, sizeof( device ) );
        memset( electric, 0, sizeof( electric ) );
    }
    return 0;
}
