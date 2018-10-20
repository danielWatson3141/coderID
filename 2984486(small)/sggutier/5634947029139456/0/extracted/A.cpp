#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <set>
using namespace std ;

void t_case() {
	int N, K ;
	int ins[300], outs[300] ;
	int res = (1<<30) ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		char tmp[105] ;
		scanf("%s", tmp ) ;
		ins[i] = 0 ;
		for( int j=0; j<K; j++ ) {
			if( tmp[j]=='1' ) 
				ins[i] += (1<<j) ;
		}
	}
	for( int i=0; i<N; i++ ) {
		char tmp[105] ;
		scanf("%s", tmp ) ;
		outs[i] = 0 ;
		for( int j=0; j<K; j++ ) {
			if( tmp[j]=='1' ) 
				outs[i] += (1<<j) ;
		}
	}

	for( int i=0; i<N; i++ ) {
		int msk = ins[0]^outs[i] ;
		set <int> cmbs ;
		bool flg = 1 ;
		for( int j=0; j<N; j++ ) {
			if( j==i )
				continue ;
			cmbs.insert( outs[j]^msk ) ;
		}
		for( int j=1; j<N; j++ ) {
			if( cmbs.find( ins[j] ) == cmbs.end() ) {
				flg = 0 ;
				break ;
			}
		}
		if( !flg )
			continue ;
		int cnt = 0 ;
		for( int j=0; j<K; j++ ) {
			if( (1<<j) & msk )
				cnt ++ ;
		}
		res = min( res, cnt ) ;
	}

	if( res==(1<<30) )
		printf("NOT POSSIBLE\n" ) ;
	else
		printf("%d\n", res ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=1; i<=T; i++ ) {
		printf("Case #%d: ", i ) ;
		t_case() ;
	}

	return 0 ;
}
