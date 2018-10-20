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

#define N 100005
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
typedef vector< string > vs;

ll toi(string s){istringstream is(s);ll x;is>>x;return x;}
string tos(ll t){stringstream st; st<<t;return st.str();}
int n , L;
ll trans( string s ){
	ll num = 0;
	REP( i , s.size() ) num = num * 2 + s[ i ] - '0';
	return num;
}
vi get( vs v , int mask ){
	int nv = v.size();
	vi w( nv );
	REP( i , nv ) w[ i ] = trans( v[ i ] ) ^ mask ;
	return w;
}
int main(){
	sync
	string s;
	int cases;
	cin >> cases;
	REP( tc , cases ){
		cin >> n >> L;
		vs A( n ) , B( n );
		REP( i , n ) cin >> A[ i ];
		REP( i , n ) cin >> B[ i ];
		vi b = get( B , 0 );
		sort( all( b ) );
		int mini = INT_MAX;
		REP( mask , 1 << L ){
			vi a = get( A , mask );
			sort( all( a ) );
			if( a == b ) mini = min( mini , ones( mask ) );
		}
		if( mini == INT_MAX ) cout << "Case #" << tc + 1 << ": NOT POSSIBLE\n";
		else cout << "Case #" << tc + 1 << ": " << mini << "\n";
	}
}


