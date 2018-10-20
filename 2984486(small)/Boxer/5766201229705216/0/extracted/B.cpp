#include <bits/stdc++.h>
using namespace std;

#define sc( x ) scanf( "%d" , &x )
#define REP( i , n ) for( int i = 0 ; i < n ; i++ )
#define FOR( it , A ) for( typeof A.begin() it = A.begin() ; it != A.end() ; it++ )
#define clr( t , val ) memset( t , val , sizeof(t) )

#define all(v)  v.begin() , v.end()
#define rall(v)  v.rbegin() , v.rend()
#define pb push_back

#define mp make_pair
#define fi first
#define se second

#define ones(x) __builtin_popcount(x)
#define test puts("************test************");
#define sync ios_base::sync_with_stdio(false);

#define N 1000
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > pii;
typedef pair< ll , ll > pll;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< ull > vull;

int n;
int root;
vi G[ N + 5 ] , E[ N + 5 ];
bool used[ N + 5 ];
int memo[ N + 5 ];
int dp( int u ){
	if( used[ u ] ) return memo[ u ];
	used[ u ] = 1;
	int &dev = memo[ u ] = 0;
	int sz = E[ u ].size();
	vi v;
	REP( i , sz ) v.pb( dp( E[ u ][ i ] ) );
	sort( all( v ) );
	if( sz >= 2 ) dev = max( dev , v[ sz - 2 ] + v[ sz - 1 ] + 2 );
	/*
	for( int i = 0 ; i < sz ; ++i )
		for( int j = i + 1 ; j < sz ; ++j ){
			int v1 = E[ u ][ i ] , v2 = E[ u ][ j ];
			dev = max( dev , 2 + dp( v1 ) + dp( v2 ) );
		}*/
	return dev;
}


int vis[ N + 5 ];
void dfs( int u , int p = -1 ){
	vis[ u ] = 1;
	REP( i , G[ u ].size() ){
		int v = G[ u ][ i ];
		if( !vis[ v ] && v != p ){
			//cout << u << " " << v << endl;
			E[ u ].pb( v );
			dfs( v );
		}
	}
}

int main(){
	int cases , x , y ;
	sc( cases );
	REP( tc , cases ){
		sc( n );
		REP( i , n ) G[ i ].clear();
		REP( i , n - 1 ){
			sc( x ) , sc( y );
			x -- , y --;
			G[ x ].pb( y );
			G[ y ].pb( x );
		}
		int maxi = 0;
		REP( i , n ) {
			clr( used , 0 );
			root = i;
			
			clr( vis , 0 );
			REP( k , n ) E[ k ].clear();
			dfs( root );
			maxi = max( maxi , 1 + dp( root ) );
		}
		//cout << maxi << endl;
		cout << "Case #" << tc + 1 << ": " << n - maxi << "\n";
	}
}


