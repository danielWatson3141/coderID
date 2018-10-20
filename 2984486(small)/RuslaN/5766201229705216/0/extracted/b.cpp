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

int t,n,vis[2000],res,ans=INF,x,y;
vector < vector < int > > xy;

void func( int par ){
	if ( vis[par] == 0 )res++;
	vis[par]=1;
	for ( int i=0; i<xy[par].size(); i++ )
		if ( vis[xy[par][i]-1] == 0 )
			func( xy[par][i]-1 );

}

void tree( int par ){
	
	int ch=0;
	for ( int i=0; i<xy[par].size(); i++ )
		ch+=( vis[xy[par][i]-1] == 0 ? 1 : 0 );
	
	vis[par]=1;
	if( ch == 1 ){
		func( par );
		return;
	}
	
	for ( int i=0; i<xy[par].size(); i++ )
		if ( vis[xy[par][i]-1] == 0 )
			tree(xy[par][i]-1);
	return;
}

int main(){
	fin >> t;
	for ( int j=0; j<t; j++ ){
		fin >> n;	xy.resize(n);
		for ( int i=0; i<n-1; i++ ){
			fin >> x >> y;
			xy[x-1].push_back(y);
			xy[y-1].push_back(x);
			
		}
	
		for ( int i=0; i<n; i++ ){
			tree( i );	ans=min( res , ans );
			fill( vis , vis+n , 0 );
			res=0;
		}	
		fout << "Case #" << j+1 << ": " << ans << endl;
		ans=INF;
		fill( vis , vis+n , 0 );
		xy.clear();
	}
	return 0;
}

