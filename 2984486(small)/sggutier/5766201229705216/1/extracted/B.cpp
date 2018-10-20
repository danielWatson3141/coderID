#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 1005 ;

int N ;
list <int> adj[lim] ;
int nSons[lim] ;

int cnt_sons( int pos, int ant ) {
	nSons[pos] = 1 ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( ant==(*it) )
			continue ;
		nSons[pos] += cnt_sons( (*it), pos ) ;
	}
	return nSons[pos] ;
}

int dpIsh( int pos, int ant ) {
	//printf("^ %d %d %d\n", pos+1, ant+1, adj[pos].size() ) ;
	if( ant!=-1 ) {
		if( adj[pos].size()==1 )
			return 0 ;
		if( adj[pos].size()==2 ) {
			for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
				if( (*it)==ant )
					continue ;
				//printf("<- %d %d\n", pos+1, nSons[*it] ) ;
				return nSons[*it] ;
			}
		}
		if( adj[pos].size()==3 ) {
			int res = 0 ;
			for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
				if( (*it)==ant )
					continue ;
				res += dpIsh( (*it), pos ) ;
			}
			//printf("<- %d %d\n", pos+1, res ) ;
			return res ;
		}
	}
	if( ant==-1 ) {
		if( adj[pos].size()==0 )
			return 0 ;
		if( adj[pos].size()==1 ) {
			for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
				return nSons[*it] ;
			}
		}
		if( adj[pos].size()==2 ) {
			int res = 0 ;
			for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
				res += dpIsh( (*it), pos ) ;
			}
			return res ;
		}
	}

	int minA = (1<<30), minB = minA ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( (*it)==ant )
			continue ;
		minB = min( minB, dpIsh( (*it), pos) - nSons[*it] ) ;
		if( minB<minA ) 
			swap( minB, minA ) ;
	}

	//printf("%d -> %d %d - %d\n", pos+1, minA, minB, nSons[pos]-1 ) ;

	return nSons[pos]-1 + minA + minB ;
}

void t_case() {
	int res = lim ;
	scanf("%d", &N) ;
	for( int i=0; i<lim; i++ ) 
		adj[i].clear() ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}


	for( int i=0; i<N; i++ ) {
		cnt_sons( i, -1 ) ;
		//printf("%d %d\n", i, dpIsh(i,-1) ) ;
		res = min( res, dpIsh( i, -1 ) ) ;
	}

	printf("%d\n", res ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) {
		printf("Case #%d: ", i+1 ) ;
		t_case() ;
	}

	return 0 ;
}
