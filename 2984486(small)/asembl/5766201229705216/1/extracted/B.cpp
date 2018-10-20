#include <cstdio>
#include <iostream>
#include <vector>
using namespace std ;
int T ;
int n ;

vector<int> e[1000] ;
int f[1000] ;
int size[1000] ;

int dfs( int root , int fa ) {

    f[root] = 0 ;
    size[root] = 1 ;
    int cnt = 0 ;
    for ( int i = 0 ; i < e[root].size() ; ++i ) {
        int next = e[root][i] ;
        if ( next != fa ) {
            ++cnt ;
            dfs( next , root ) ;
            size[root] += size[next] ;
        }
    }

    int min1 = n , min2 = n , sum = 0 ;
    for ( int i = 0 ; i < e[root].size() ; ++i ) {
        int next = e[root][i] ;

        if ( next != fa ) {
            sum += size[next] ;
            if ( f[next] - size[next] < min1 ) {
                min2 = min1 ;
                min1 = f[next] - size[next] ;
            }
            else if ( f[next] - size[next] < min2 ) {
                min2 = f[next] - size[next] ;
            }
        }
    }
    if ( cnt == 0 )
        f[root] = 0 ;
    else if ( cnt == 1 )
        f[root] = size[root]-1 ;
    else
        f[root] = min1 + min2 + sum ;
    return f[root] ;
}

int main() {

    int test = 1 ;
    cin >> T ;

    while ( T-- ) {

        cin >> n ;
        for ( int i = 0 ; i < n ; ++i )
            e[i].clear();

        for ( int i = 1 ; i < n ; ++i ) {
            int x , y ;
            cin >>x >> y ;

            --x , --y ;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        int ans = n ;
        for ( int i = 0 ; i < n ; ++i ) {

            int t = dfs( i , -1 );
            if ( t < ans ) {
                ans = t ;
                //cout << i << '#' << ans << endl ;
            }
        }
        printf("Case #%d: %d\n",test++,ans);
    }
}
