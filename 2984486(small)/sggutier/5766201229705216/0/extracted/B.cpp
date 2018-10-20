#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
const int lim = 1005 ;

int N ;
bool adj[lim][lim] ;
int nodTot ;

bool b_tree( int msk, int pos, int ant ) {
	int cnt = 0 ;
	nodTot ++ ;
	for( int i=0; i<N; i++ ) {
		if( !adj[pos][i] || ((1<<i)&msk)!=0 || i==ant )
			continue ;
		cnt ++ ;
	}
	if( cnt!=0 && cnt!=2 )
		return 0 ;
	for( int i=0; i<N; i++ ) {
		if( !adj[pos][i] || ((1<<i)&msk)!=0 || i==ant )
			continue ;
		if( !b_tree(msk,i,pos) )
			return 0 ;
	}
	return 1 ;
}

void t_case() {
	int res = lim ;
	memset( adj, 0, sizeof(adj) ) ;
	scanf("%d", &N) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a][b] = adj[b][a] = 1 ;
	}
	for( int b=0; b<(1<<N); b++ ) {
		for( int i=0; i<N; i++ ) {
			if( (1<<i) & b )
				continue ;
			int tmp = 0 ;
			for( int j=0; j<N; j++ )
				if( (1<<j) & b )
					tmp ++ ;
			nodTot = 0 ;
			if( b_tree(b,i,-1) && nodTot==N-tmp ) {
				res = min( res, tmp ) ;
				break ;
			}
		}
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
