# include <iostream>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <vector>
# include <fstream>
# include <limits.h>

# define INF 1000000009

using namespace std;

ifstream fin ("file.in");
ofstream fout ("file.out");

int n,l,ans=INF,t;
string out[200],ch[200];

bool func(){
	
	int vis[200],res=0;	fill( vis , vis+n , 0 );
	
	for ( int i=0; i<n; i++ )
		for ( int h=0; h<n; h++ )
			if ( vis[h] == 0 && out[i] == ch[h] )
				vis[h]=1,res++;
	
	return ( res == n ? 1 : 0 );
}

void rec( int x , int L ){
	
	if ( func() == 1 ){
		ans=min( ans , L );
		return;
	}
	
	for ( int i=x+1; i<l; i++ ){
		for ( int h=0; h<n; h++ )
			out[h][i]=( out[h][i] == '0' ? '1' : '0' );
		
		rec( i , L+1 );
		
		for ( int h=0; h<n; h++ )
			out[h][i]=( out[h][i] == '0' ? '1' : '0' );
		
	}
	
	return;
}

int main(){
	
	fin >> t;
	for ( int j=0; j<t; j++ ){
		fin >> n >> l;
		for ( int i=0; i<n; i++ )	fin >> out[i];
		for ( int i=0; i<n; i++ )	fin >> ch[i];
		
		rec( -1 , 0 );
		
		if ( ans != INF )	fout << "Case #" << j+1 << ": " << ans << endl;
		else	fout << "Case #" << j+1 << ": " << "NOT POSSIBLE\n";
		
		ans=INF;
	}
	return 0;
}

