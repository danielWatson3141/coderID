#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cstring>
#include <vector>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define REPR(i,a,b) for (int i = a; i <= b; i++)
#define PB push_back

const int N = 1005;
bool seen[N];
vector<int> v[N];
int n, a, b;

pair<int,int> dfs(int x) {
	seen[x] = true;
	vector<pair<int,int> > r;
	int child = 0;
	REP(i,v[x].size()) {
		int to = v[x][i];
		if (!seen[to]) {
			child++;
			r.PB( dfs(to) );
		}
	}
	if (child == 0) {
		return make_pair(0, 1);
	} else if (child == 2) {
		return make_pair(r[0].first + r[1].first, 1 + r[0].second + r[1].second);
	} else if (child == 1) {
		return make_pair(r[0].second, r[0].second + 1); //delete only child
	} else {
		int st = 0;
		REP(i,child) st += r[i].second;

		vector<int> v;
		REP(i,child) v.PB(  r[i].first - r[i].second );
		sort(v.begin(), v.end());

		return make_pair(st + v[0] + v[1] , 1 + st);
	}
}

int main() {
	int t;
	cin >> t;
	REP(qqq,t) {
		cin >> n;
		REP(i,n) v[i].clear();

		REP(i,n-1) {
			cin >> a >> b;
			a--; b--;
			v[a].PB(b); v[b].PB(a);
		}
		int ans = n-1;
		REP(i,n) {
			//try as root
			memset(seen, 0, sizeof(seen));
			ans = min(ans, dfs(i).first);
		}
		cout << "Case #" << (qqq+1) << ": " << ans << endl;
	}
}
