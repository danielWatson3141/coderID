#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

#define d				double
#define ll 				long long
#define pb 				push_back
#define mp 				make_pair
#define forn( i, n ) 	for( ll i = 0; i < (ll) (n); i ++ )
#define y1 				dsaddassd

using namespace std;

ll t;
ll n, l;
string s[11];
string c[11];
bool b[11];

void inv() {
	forn( i, n ) {
		forn( j, l ) {
			if( b[j] ){
				if( s[i][j] == '0' )
					s[i][j] = '1';
				else
					s[i][j] = '0';	
			}	
		}	
	}	
}

bool check() {
	bool b1[11], b2[11];
	forn( i, n ) {
		b1[i] = false;	
		b2[i] = false;
	}
	inv();
	ll res = 0;
	forn( i, n ) {
		forn( j, n ) {
			if( !b1[j] && s[j] == c[i] ) {
				b1[j] = true;
				res ++;
				break;
			}	
		}	
	}
	inv();
	return res == n;
}

int main( void ) {
	freopen( "A-small-attempt1.in", "r", stdin );
	freopen( "A-small-attempt1.out", "w", stdout );
	//srand( time( NULL ) );
	cin >> t;
	forn( _, t ) {
		cin >> n >> l;
		forn( i, n ) {
			cin >> s[i];		
		}
		forn( i, n ) {
			cin >> c[i];	
		}
		ll ans = -1;
		forn( i, 1 << l ) {
			ll res = 0;
			forn( j, l )
				if( i & ( 1 << j ) ) {
					b[j] = true;
					res ++;
				}
				else
					b[j] = false;
			if( check() ) {
				if( ans == -1 || ans > res ) {
					ans = res;		
				}
			}
		}
		cout << "Case #" << _ + 1 << ": "; 
		if( ans != -1 )
			cout << ans << endl;
		else
			cout << "NOT POSSIBLE" << endl;

	}
	
	TIMESTAMP;
	cin >> t;
	return 0;	
}
