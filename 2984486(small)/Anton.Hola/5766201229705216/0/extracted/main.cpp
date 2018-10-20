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

int n;
vector<int> G[20];
bool used[20];

bool dfs(int node, int from = -1) {
    used[node] = true;
    bool res = false;
    if ( from == -1 ) {
        if ( G[node].size() == 2 ) {
            res = dfs( G[node][0], node ) && dfs( G[node][1], node );            
        }
    }
    else {
        if ( G[node].size() == 1 ) res = true;
        else if ( G[node].size() == 3 ) {
            res = true;
            for ( int i = 0; i < G[node].size(); i++ ) {
                if ( G[node][i] != from ) {
                    res &= dfs( G[node][i], node );
                }
            }
        }
    }
    return res;
}

int check(int mask) {
    int res = 0;
    for ( int i = 0; !res && i < n; i++ ) {
        int res1;
        if ( (1<<i) & mask ) {
            memset(used, false, sizeof(used));
            if ( dfs(i, -1) ) {
                res1 = 0;
                for ( int j = 0; j < n; j++ )
                    res1 += used[j];
                res = max(res, res1);
            }
        }
    }
    return res;
}

int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int tc; scanf( "%d", &tc );
    for ( int _ = 0; _ < tc; _++ ) {
        printf( "Case #%d: ", _+1 );
        scanf( "%d", &n );
        int a[20]={0}, b[20]={0};
        for ( int i = 0; i < n-1; i++ ) {
            scanf( "%d%d", &a[i], &b[i] );
            a[i]--; b[i]--;
        }
        int res = 1000;
        for ( int i = 0; i < (1<<n); i++ ) {
            for ( int j = 0; j < n; j++ ) {
                G[j].clear();
            }
            for ( int j = 0; j < n-1; j++ ) {
                if ( ((1<<a[j])&i) && ((1<<b[j])&i) ) {
                    G[a[j]].push_back(b[j]);
                    G[b[j]].push_back(a[j]);
                }
            }
            int res1 = check(i);
            if ( res1 ) {
                res = min(res, n-res1);
            }
        }
        printf( "%d", res == 1000 ? n-1 : res );
        
        printf( "\n" );
    }
    
    return 0;
}
