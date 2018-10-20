#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define FORR(i,n) for(int i = n-1;i >= 0;i--)
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()
#define CLEAR(a) memset(a, 0, sizeof(a))
#define INF 100000

typedef long long LL;

int n;
vector<int> g[1001];
int sz[1001];

inline int gosz(int idx, int par) {
	sz[idx] = 1;
	FOR(i, g[idx].size()) {
		if (g[idx][i] != par)
		sz[idx] += gosz(g[idx][i], idx);
	}
	return sz[idx];
}

inline int go(int idx, int par) {
	if (par == -1) {
		if (g[idx].size() == 0)
			return 0;

		if (g[idx].size() == 1) {
			return sz[g[idx][0]];
		}

		int s1=INF,s2=INF,sum = 0;

		FOR(i, g[idx].size()) {
			int r = go(g[idx][i], idx) - sz[g[idx][i]];
			sum+=sz[g[idx][i]];

			if (r < s1) {
				s2 = s1;
				s1 = r;
			} else if (r < s2) {
				s2 = r;
			}
		}

		int rt = (sum + s1 + s2); // + g[idx].size() - 2;
		if (rt > INF)
			return INF;
		return rt;
	} else {
		if (g[idx].size() == 1)
			return 0;
		if (g[idx].size() == 2) {

			if (g[idx][0] == par)
				swap(g[idx][0], g[idx][1]);

			return sz[g[idx][0]];
		}

		int s1=INF,s2=INF,sum=0;

		FOR(i, g[idx].size()) {
			if (g[idx][i] == par)
				continue;
			int r = go(g[idx][i], idx) - sz[g[idx][i]];
			
			sum+=sz[g[idx][i]];

			if (r < s1) {
				s2 = s1;
				s1 = r;
			} else if (r < s2) {
				s2 = r;
			}
		}

		int rt = (sum+s1+s2); // +g[idx].size()-3;
		if (rt > INF)
			return INF;
		return rt;
	}
}

int main() {
  ios_base::sync_with_stdio(0);
  int tt,x,y;
  cin >> tt;

  FOR(tn,tt) {
  	cin >> n;

  	FOR(i, n)
  	g[i].clear();

  	FOR(i, n-1) {
  		cin >> x >> y;
  		x--;
  		y--;
  		g[x].push_back(y);
  		g[y].push_back(x);
  	}

  	int res = n - 1;

  	FOR(i,n) {
  		gosz(i,-1);
  		res = min(res, go(i, -1));
  		//cerr << i << ' ' << res << endl;
  	}

    cout << "Case #" << tn + 1 << ": ";
    cout << res << endl;
  }

  return 0;
}
