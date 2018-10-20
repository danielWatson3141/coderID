#include<bits/stdc++.h>

using namespace std;

set< vector<long long> > visit;

struct node{
	vector<long long> outlets;
	int moves;
	node( vector<long long> &outlets, int moves) : outlets( outlets ) , moves( moves ) {}
};

int N, L, T;

bool ok( const vector<long long> &out, const vector<long long> dev ){
	set<long long> ss( out.begin() , out.end() );
	for( int i=0; i<N; i++ )
		if( ss.find( dev[i] ) == ss.end() )
			return false;
	return true;
}

int bfs ( vector<long long> &outlets, const vector<long long> &devices ) {
	queue< node > q;
	q.push( node( outlets , 0 ) );
	visit.insert( outlets );
	vector <long long> oo;
	while( !q.empty() ){
		node p = q.front();
		q.pop();
		if( ok( p.outlets, devices ) )
			return p.moves;
		for( int i=0; i<L; i++ ){
			oo = p.outlets;
			for( int j=0; j<N; j++ ){
				oo[j] ^= (1 << i);
			}
			if( visit.find( oo ) == visit.end() ){
				visit.insert( oo );
				q.push( node( oo, p.moves + 1 ) );
			}
		}
	}
	return -1;
}

int main(){
	cin >> T;
	for( int caze=1; caze<=T; caze++ ){
		visit.clear();
		char bit;
		long long x;
		cin >> N >> L;
		vector< long long > devices( N ) , outlets( N );
		for( int i=0; i<N; i++ ){
			x = 0LL;
			for( int j=0; j < L; j++ ){
				cin >> bit;
				if( bit == '1' )
					x |= ( 1 << j );
			}
			devices[i] = x;
		}

		for( int i=0; i<N; i++ ){
			x = 0LL;
			for( int j=0; j < L; j++ ){
				cin >> bit;
				if( bit == '1' )
					x |= ( 1 << j );
			}
			outlets[i] = x;
		}
	
		/*
		for( int i=0; i<N; i++ )
			cout << devices[i]  << " ";
		cout << endl;
		for( int i=0; i<N; i++ )
			cout << outlets[i]  << " ";
		cout<< endl << endl;
		*/
	
		int ans = bfs( outlets, devices );	
		
		cout << "Case #" << caze << ": ";
		if( ans == -1 )
			cout << "NOT POSSIBLE";
		else cout << ans;
		cout << endl;
	}
	
	return 0;
}
