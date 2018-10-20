
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
typedef complex<int> P;
typedef pair<int,int> pii;
const double EPS = 1e-10;
const double PI  = acos(-1.0);


char rev(char c){
	if(c == '0') return '1';
	if(c == '1') return '0';
}

void rec(int k, int L, int cnt, vector<string> vstr, vector<pair<vector<string>, int> > &vvstr){
	if(k == L){
		pair<vector<string>, int> a(vstr, cnt);
		vvstr.pb(a);
		return;
	}
	rec(k+1, L, cnt, vstr, vvstr);
	for(int i=0;i<vstr.size();i++){
		vstr[i][k] = rev(vstr[i][k]);
	}
	rec(k+1, L, cnt+1, vstr, vvstr);
	return;
}

bool solve(){
	int n, L;
	cin>> n>> L;
	vector<string> vstr(n), vstr2(n);
	vector<pair<vector<string>, int> > vvstr;
	for(int i=0;i<n;i++) cin>> vstr[i];
	for(int i=0;i<n;i++) cin>> vstr2[i];

	rec(0, L, 0, vstr, vvstr);
	for(int i=0;i<vvstr.size();i++) sort(all(vvstr[i].first));
	sort(all(vstr2));
/*	for(int i=0;i<vvstr.size();i++){
		cout<< " "<< vvstr[i].second;
		for(int j=0;j<n;j++){
			cout<< " "<< vvstr[i].first[j];
		}
		cout<< endl;
	}
*/
	for(int i=0;i<vvstr.size();i++){
		if(vvstr[i].first == vstr2){
			cout<< vvstr[i].second<< endl;
			return true;
		}
	}
	cout<< "NOT POSSIBLE"<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	
	int n;
	cin>> n;
	for(int i=0;i<n;i++){
		cout<< "Case #"<< i+1<< ": ";
		solve();
	}
	return 0;
}

 