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


VV(int) G;
vector<char> vis;
VV(int) chld;
vint sz;

void dfs(int u){
	vis[u] = 1;
	sz[u] = 1;
	for(int v : G[u]){
		if(!vis[v]){
			chld[u].push_back(v);
			dfs(v);
			sz[u] += sz[v];
		}
	}
}

int calc(int u){
	if(chld[u].empty()){
		return 0;
	}
	if(chld[u].size() == 1){
		return sz[chld[u][0]];
	}
	if(chld[u].size() == 2){
		return calc(chld[u][0]) + calc(chld[u][1]);
	}

	vector<pii> cs(chld[u].size());
	for(size_t i = 0; i < chld[u].size(); ++i){
		int v = chld[u][i];
		int t = calc(v);
		cs[i] = pii(t - sz[v], t);
	}
	sort(ALL(cs));
	int ret = cs[0].second + cs[1].second;
	for(size_t i = 2; i < cs.size(); ++i){
		ret += cs[i].second - cs[i].first;
	}
	return ret;
}


int root(int rt){
	vis.assign(G.size(), 0);
	chld.clear();
	chld.resize(G.size());
	sz.assign(G.size(), 0);
	dfs(rt);

	return calc(rt);
}


int solve(){
	int x, y, n;
	scanf("%d", &n);
	G.clear();
	G.resize(n + 1);
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}

	int ans = INT_MAX;
	for(int i = 1; i <= n; ++i){
		ans = min(ans, root(i));
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
