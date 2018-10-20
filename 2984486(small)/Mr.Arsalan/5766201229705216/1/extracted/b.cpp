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
bool cmp ( pair<int,int> a , pair<int,int> b ){
	return a.second - a.first < b.second - b.first;
}
pair<int,int> dfs ( int x , int root ){
	//cerr << x << " " << root << endl;
	mark[x] = 1;
	vector<pair<int,int> > data;
	pair<int,int> ret = make_pair(1,0);
	for ( int i=0 ; i<g[x].size() ; i++ ){
		if ( mark[g[x][i]] ) continue ;
		data.push_back(dfs(g[x][i],0));
		ret.first += data[data.size()-1].first;
	}
	sort(data.begin(),data.end(),cmp);
	int remain = ret.first - 1;
	if ( root ){
		int best = remain;
		if ( g[x].size() > 2 ){
			//cerr << "1 ~~~~" << x << " " <<  g[x].size()  << endl;
			int temp = data[0].second - data[0].first + data[1].second - data[1].first + remain;
			//cerr << "~1" << endl;
			best = min ( temp , best ) ;
		}
		else if ( g[x].size() == 2 ){
			int temp = 0;
			for ( int i=0 ; i<data.size(); i++ )
				temp += data[i].second ;
			best = min ( best , temp ) ;
		}
		ret.second = best;
		
	}
	else{
		int best = remain;
		if ( g[x].size() == 1 ){
			best = 0 ;
		}
		else if ( g[x].size() == 2 ){
			best = remain;
		}
		else if ( g[x].size() == 3 ){
			int temp = 0;
			for ( int i=0 ; i<data.size(); i++ )
				temp += data[i].second ;
			best = min ( best , temp ) ;
		}
		else if ( g[x].size() > 3 ){
			int temp = remain ;
			//cerr << "2" << endl;
			for ( int j=0 ; j<2 ; j++ )
				temp += data[j].second - data[j].first ;
			//cerr << "~2" << endl;
			best = min ( best , temp ) ;
		}
		ret.second = best;
	}
	//cerr << x << " " << root << " " << ret.second << " remain " << remain  << endl;
	return ret;
	
}

int main(){
	int tc;
	cin >> tc;
	for ( int C = 1 ; C<=tc ; C++ ){
		cerr << C << " " << tc << endl;
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
		int ret = n - 1;
		for ( int i=0 ; i<n ; i++ ){
			memset(mark,0,sizeof mark);
			pair<int,int> temp = dfs(i,1);
			if ( temp.first != n ){
				cerr << "more than 1 cc" << endl;
			}
			//cerr << "********* " << i << " " << temp.first << " " << temp.second << endl;
			ret = min ( ret , temp.second ) ;
		}
		
		cout << "Case #" << C << ": " << ret << endl;
	}
	return 0 ;
}
