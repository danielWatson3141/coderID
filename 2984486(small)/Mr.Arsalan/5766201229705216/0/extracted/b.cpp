#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<map>
#include<cctype>
#include<vector>
#include<cmath>
#include<sstream>

using namespace std;
const int max_n = 1000 + 10 ;
vector<int> g[max_n];
vector<int> gg[max_n];
int mark[max_n];
int n ;
void dfs ( int x ){
	mark[x]=1;
	for ( int i=0 ; i<gg[x].size() ; i++ )
		if ( mark[gg[x][i]] != 1 )
			dfs(gg[x][i]);
	
}
bool solve ( int mask ){
//	cerr << "mask = " << mask << endl;
	for ( int i=0 ; i<n ; i++ ) gg[i].clear();
	int last = -1 ;
	for ( int i=0 ; i<n ; i++ )
		if ( mask & (1<<i) ){
			last = i ;
			for ( int j=0 ; j<g[i].size() ; j++ ){
				if ( mask & (1<<g[i][j]) )
					gg[i].push_back(g[i][j]);
			}
		}
	//cerr << "here" << endl;
	memset(mark,0,sizeof mark);
	dfs(last);
	//cerr << "here" << endl;
	/*for ( int i=0 ; i<n ; i++ )
		if ( mask &(1<<i) )
		cerr << gg[i].size() << " ======> " << mark[i]<< endl;*/
	int cnt[4] = {0};
	for ( int i=0 ; i<n ; i++ )
		if ( mask & (1<<i) ){
			if ( gg[i].size() > 3  )
				return false;
			cnt[gg[i].size()] ++ ;
			if ( mark[i] == 0 ) return false;
		}
	if ( cnt[2] == 0 ){
		return cnt[1]==0 && cnt[3] == 0;
	}
	else if ( cnt[2] > 1 ) return false;
	return true ;
	
}
/*pair<int,int> dfs ( int x ){
	mark[x] = 1;
	vector<int> data;
	pair<int,int> ret = make_pair(1,0);
	for ( int i=0 ; i<g[x].size() ; i++ ){
		if ( mark[g[x][i]] ) continue ;
		data.push_back(dfs(g[x][i]);
		ret.first += data[data.size()-1].first;
	}
	if ( g[x].size() > 3 ){
		sort(data.begin(),data.end());
		for ( int i=0 ; i<g[x].size()-3 )
			ret.second += data[i].first ;		
	}
	
	
}*/

int main(){
	int tc;
	cin >> tc;
	for ( int C = 1 ; C<=tc ; C++ ){
		
		cin >> n ;
		for ( int i=0 ; i<n ; i++ )
			g[i].clear();
		for ( int i=0 ; i<n-1 ; i++ ){
			int a , b ;
			cin >> a >> b;
			--a , -- b ;
			g[a].push_back(b);
			g[b].push_back(a);
			
		}
		int ret = -1 ;
		for ( int mask = 1 ; mask <(1<<n) ; mask ++ ){
			int z = 0 ;
			for ( int i=0 ; i<n ; i++ )
				if ( (mask&(1<<i)) == 0 ) 
					z ++ ;
			if ( ret != -1 && ret <= z ) continue ;
			if ( solve(mask) ){
				//cerr << "found " << mask << endl;
				ret = z;
			}
		}
		cout << "Case #" << C << ": " << ret << endl;
	}
	return 0 ;
}
