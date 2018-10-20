#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#endif

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int solve(){
	int n, L;
	cin >> n >> L;
	
	string s;
	vector<LL> v(n), w(n), t(n);
	for(int i = 0; i < n; ++i){
		cin >> s;
		v[i] = strtoll(s.c_str(), 0, 2);
	}
	for(int i = 0; i < n; ++i){
		cin >> s;
		w[i] = strtoll(s.c_str(), 0, 2);
	}
	sort(ALL(w));

	int ans = INT_MAX;
	for(int i = 0; i < n; ++i){
		LL d = v[0] ^ w[i];
		for(int j = 0; j < n; ++j){
			t[j] = v[j] ^ d;
		}
		sort(ALL(t));
		if(w == t){
			ans = min(ans, __builtin_popcountll(d));
		}
	}
	
	if(ans == INT_MAX){
		ans = -1;
	}
	return ans;
}


int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		cerr << i << "/" << T << endl;
	
		cout << "Case #" << i << ": ";
		int ans = solve();
		
		if(ans < 0){
			cout << "NOT POSSIBLE\n";
		}
		else{
			cout << ans << '\n';
		}
	}
}
