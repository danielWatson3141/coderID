#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

int outlet[10];
int devices[10];

int conv( const string& s ) {
	int n = s.size();
	int res = 0;
	for( int i = 0; i < n; ++i ) {
		res = 2*res + s[i]-'0';
	}
	return res;
}

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		int N, L;
		cin >> N >> L;
		assert( N <= 10 );
		assert( L <= 10 );
		string s;
		for( int i = 0; i < N; ++i ) {
			cin >> s;
			outlet[i] = conv(s);
		}
		for( int i = 0; i < N; ++i ) {
			cin >> s;
			devices[i] = conv(s);
		}
		int result = 1000000;
		for( int i = 0; i < (1<<L); ++i ) {
			int cnt;
			for( int j = 0; j < N; ++j ) {
				bool found = false;
				for( int k = 0; k < N; ++k ) {
					if( (outlet[j]^i) == devices[k] ) {
						found = true;
						break;
					}
				}
				if( !found ) goto nexti;
			}
			cnt = 0;
			for( int j = 0; j < L; ++j ) {
				if( i & (1<<j) ) ++cnt;
			}
			result = min( result, cnt );
		nexti:;
		}
		if( result == 1000000 ) cout << "NOT POSSIBLE\n";
		else cout << result << endl;
	}
	return 0;
}

