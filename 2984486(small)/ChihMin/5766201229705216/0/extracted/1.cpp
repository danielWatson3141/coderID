#include <cstdio>
#include <Cstdlib>
#include <algorithm>
#include <vector>
#include <queue> 

using namespace std;

struct Node{
	int t , f , dis  ; 
	Node(){}  
	Node( int _t , int _f ){
		t = _t , f = _f ;  
	}
} tree[1000] ;  ; 

vector < int > v[2000] ;
bool visit[2000] ;  
int child[2000] ; 
int n ; 

bool cmp( const Node &A , const Node &B ){
	int disA = A.f - A.t  ; 
	int disB = B.f - B.t ;  
	
	return disA < disB ; 
}

void ini(){
	for(int i=0;i<=n;++i)	v[i].clear() ; 
}

void dfs( int now ){
	
	tree[now].f = 0 ;
	tree[now].t = 1 ; 
	
	
	vector < Node > table ; 
	table.clear() ; 
	int m = v[now].size() ; 
	for(int i=0;i<m;++i){
		int a = now ;	
		int b = v[a][i] ; 
		
		if( !visit[b] ){
			visit[b] = 1 ; 
			dfs( b ) ; 
			table.push_back( Node( tree[b].t , tree[b].f) ) ;  
		}
	}
		
	int cnt = table.size() ; 
	if( cnt == 0 )	return ; 
	else if( cnt == 1 ){	
		tree[now].t += table[0].t ;
		tree[now].f = table[0].t ; 
	}		
	else{
		sort( table.begin() , table.end() , cmp ) ;
		for(int i=0;i<cnt;++i){
			const Node &tmp = table[i] ; 
			tree[now].t = tree[now].t + tmp.t ; 
		}
		tree[now].f = tree[now].t - 1 - table[0].t - table[1].t ;  
		tree[now].f += (table[0].f + table[1].f) ; 
	}	
}

int main(){
	
	int CASE = 0 ;
	int T; 
	scanf("%d",&T ) ; 
	
	while( T-- ){
		scanf("%d",&n) ; 
		ini( ) ; 
		
		
		for(int i=0;i<n-1;++i){
			int x ,y  ; 
			scanf("%d %d",&x,&y ) ; 
			
			v[x].push_back( y ); 
			v[y].push_back( x );
		}	
		
		int MIN = 1 << 20 ;
		for(int i=1;i<=n;++i){	
			for(int j=0;j<=n;++j) visit[j] = 0 ; 
			visit[i] = 1 ; 
			dfs( i ) ; 
			MIN = min( MIN , tree[i].f ) ;
			
		//	for(int j=1;j<=n;++j) 
		//		printf("%d -> ( %d , %d )\n",j,tree[j].t,tree[j].f) ; 
		}
		printf("Case #%d: %d\n",++CASE,MIN) ; 
	}
	return 0 ;
}
