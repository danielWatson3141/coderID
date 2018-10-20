#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int tc; scanf( "%d", &tc );
    for ( int _ = 0; _ < tc; _++ ) {
        printf( "Case #%d: ", _+1 );
        int N, L; scanf( "%d%d\n", &N, &L );
        string a[200], b[200];
        for ( int i = 0; i < N; i++ ) {
            cin >> a[i];
        }
        for ( int i = 0; i < N; i++ ) {
            cin >> b[i];
        }
        
        long long c[200][200] = {0};
        
        for ( int i = 0; i < N; i++ ) {
            for ( int j = 0; j < N; j++ ) {
                for ( int k = 0; k < L; k++ ) {
                    if ( b[i][k] != a[j][k] ) {
                        c[i][j] += 1LL << k;
                    }
                }
            }
        }
        
        int res = 100000;
        for ( int i = 0; i < N; i++ ) {
            long long val = c[0][i];
            bool used[200] = {false};
            used[i] = true;
            int cnt = 1;
            bool good = true;
            for ( int j = 1; good && j < N; j++ ) {
                for ( int k = 0; good && k < N; k++ ) {
                    if ( c[j][k] == val ) {
                        if ( !used[k] ) {
                            used[k] = true;
                            cnt++;
                            break;
                        }
                        else {
                            good = false;
                        }
                    }
                }
            }
            if ( good && cnt == N ) {
                int res1 = 0;
                for ( int j = 0; j < L; j++ ) {
                    if ( (1LL<<j) & val ) {
                        res1++;
                    }
                }
                res = min(res, res1);
            }
        }
        if ( res == 100000 ) {
            printf( "NOT POSSIBLE" );
        }
        else {
            printf( "%d", res );
        }
        
        printf( "\n" );
    }
    
    return 0;
}
