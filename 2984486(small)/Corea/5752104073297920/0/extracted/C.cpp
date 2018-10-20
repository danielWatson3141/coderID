#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int N;

int data[ 1003 ];
int table[ 1003 ];

bool process() {
    vector< pair<double, double> > lst;
    vector<double> value_lst;

    for( int i = 1; i <= N; i ++ ) {
        bool changed = false;
        for( int j = i; j <= N; j ++ ) {
            if( table[ j ] == data[ i ] ) {
                pair<double, double> value( (j - i) / double(N - i + 1), (j - i + 1) / double(N - i + 1) );
                value_lst.push_back( value.first );
                value_lst.push_back( value.second );
                lst.push_back( value );

                int t = table[ i ];
                table[ i ] = table[ j ];
                table[ j ] = t;

                changed = true;
                break;
            }
        }
        if( !changed ) {
            return false;
        }
    }
    
    value_lst.push_back( 0 );
    value_lst.push_back( 1 );
    sort( value_lst.begin(), value_lst.end() );
    value_lst.erase( unique( value_lst.begin(), value_lst.end() ), value_lst.end() );

    double v = 0;
    int MX = 100000;
    for( int i = 1; i <= MX; i ++ ) {
        double st = (i - 1) / double(MX);
        double en = i / double(MX);
        double gap = en - st;

        double prob = 0;
        for( auto& x : lst ) {
            if( x.first - 1e-8 <= st && en <= x.second + 1e-8 ) {
                prob += 1. / (x.second - x.first) / double(N);
            }
        }
        v += prob * prob;
    }

    if( v > 150000 ) {
        return false;
    }
    return true;
}

int main() {
    int T;
    scanf( "%d", &T );
    for( int test = 1; test <= T; test ++ ) {
        scanf( "%d", &N );

        for( int i = 1; i <= N; i ++ ) {
            scanf( "%d", &data[ i ] );
            data[ i ] ++;
            table[ i ] = i;
        }

        printf( "Case #%d: %s\n", test, (process() ? "GOOD" : "BAD") );
    }
    return 0;
}
