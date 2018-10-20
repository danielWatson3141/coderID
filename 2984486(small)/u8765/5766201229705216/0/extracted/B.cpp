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

vector<int> list[1000];

int memo_del[1000];
int memo[1000];

int rec_del( int k, int parent ) {
	int& res = memo_del[k];
	if( res != -1 ) return res;

	int n = list[k].size();
	int children = n;
	if( parent != -1 ) --children;
	if( children == 0 ) return res = 1;
	res = 1;
	for( int i = 0; i < n; ++i ) {
		if( list[k][i] != parent ) res += rec_del( list[k][i], k );
	}
	return res;
}

int rec( int k, int parent ) {
	int& res = memo[k];
	if( res != -1 ) return res;

	int n = list[k].size();
	int children = n;
	if( parent != -1 ) --children;
	if( children == 0 ) return res = 0;
	if( children == 1 ) {
		for( int i = 0; i < n; ++i ) {
			if( list[k][i] != parent ) {
				return res = rec_del( list[k][i], k );
			}
		}
		assert(0);
	}

	int children_del = 0;
	for( int i = 0; i < n; ++i ) {
		if( list[k][i] != parent ) children_del += rec_del( list[k][i], k );
	}

	res = 1+children_del;
	for( int i = 0; i < n; ++i ) {
		if( list[k][i] == parent ) continue;
		for( int j = i+1; j < n; ++j ) {
			if( list[k][j] == parent ) continue;
			int cost = rec( list[k][i], k ) + rec( list[k][j], k )
					+ children_del
					- rec_del( list[k][i], k ) - rec_del( list[k][j], k );
			res = min( res, cost );
		}
	}
	return res;
}

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";
		int N;
		cin >> N;
		assert( N <= 1000 );
		for( int i = 0; i < N; ++i ) list[i].clear();
		for( int i = 1; i < N; ++i ) {
			int x, y;
			cin >> x >> y;
			list[x-1].push_back(y-1);
			list[y-1].push_back(x-1);
		}
		int result = 1000000;
		for( int i = 0; i < N; ++i ) {
			memset( memo, -1, sizeof(int)*N );
			memset( memo_del, -1, sizeof(int)*N );
			int cost = rec( i, -1 );
			result = min( result, cost );
		}
		cout << result << endl;
	}
	return 0;
}

