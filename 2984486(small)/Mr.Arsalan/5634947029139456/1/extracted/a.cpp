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

vector<int> f ( string & a , string & b ){
	vector<int> ret;
	//cerr << a << " " << b << " => " ;
	for ( int i=0 ; i<a.size() ; i++ )
		if ( a[i] != b[i] ){
			ret.push_back(i);
		//	cerr << i << " " ;
		}
//	cerr << endl;
	return ret;
}
bool check ( vector<string>   a , vector<string>  b , vector<int> sol ){
	//cerr << "sol : " ;
	//for ( int i=0 ; i<sol.size() ;i++ )
	//	cerr << sol[i] << " ";
	//cerr << endl;
	int n = a.size();
	for ( int i=0 ; i<sol.size() ;i++ ){
		int index = sol[i];
		for ( int j=0 ; j<a.size() ; j++ ){
			a[j][index] = (1-(a[j][index]-'0')) + '0';
			//b[j][index] = (1-(b[j][index]-'0')) + '0';
		}
	}
	/*for ( int i=0 ; i<n ; i++) 
		cerr << a[i] << " " ;
	cerr << endl;
	for ( int i=0 ; i<n ; i++) 
		cerr << b[i] << " " ;
	cerr << endl;*/

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for ( int i=0 ; i<a.size() ;i++) 
		if ( a[i] != b[i] )
			return false;
	return true ;

}
int main(){
	int tc;
	cin >> tc;
	for ( int C = 1 ; C<=tc ; C++ ){
		set < vector<int> > table;
		cerr << C << " " << tc << endl;
		int n , l ;
		vector<string> init , target;
		cin >> n >> l ;
		init.resize(n) ;
		target.resize(n);
		for ( int i=0 ; i<n ; i++ )
			cin >> init[i];
		for ( int i=0 ; i<n ; i++ )
			cin >> target[i] ;
		int ret = -1 ;
		for ( int i=0 ; i<n ; i++ )
			for ( int j=0 ; j<n ; j++ ){
				vector<int> sol = f(init[i],target[j]);
				if ( table.find(sol) != table.end() ) continue ;
				table.insert(sol);
				if ( check (init,target,sol) ){
					if ( ret == -1 ) ret = sol.size() ;
					else ret = min ( ret , (int) sol.size() ) ;
				}
				
			}
		cout << "Case #" << C << ": " ;
		if ( ret == -1 ) cout << "NOT POSSIBLE" << endl;
		else cout << ret << endl;
	}
	return 0 ;
}
