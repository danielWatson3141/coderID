#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 33311
using namespace std;
typedef pair<int,int> pt;

int f[3334], s[3334];
int n;
vector<int> v[3334];

void rec(int x, int p) {
	s[x] = 1;
	int q = 0;
	vector<int> g;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) {
		rec(v[x][i], x);
		s[x] += s[v[x][i]];
		q += s[v[x][i]];
		g.pb(f[v[x][i]] - s[v[x][i]]);
	}	
	f[x] = q;
	if (g.size() >= 2) {
		sort(g.begin(), g.end());
		f[x] = min(f[x], q + g[0] + g[1]);
	}
}

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n;
		for (int i = 0; i <= n; i++) v[i].clear();
		for (int i = 1; i < n; i++) {
			int x ,y;
			cin >> x >> y;
			x--;
			y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		int ans = 1e9;
		for (int i = 0; i < n; i++) {
			rec(i, -1);
			ans = min(ans, f[i]);
		}
		cout << "Case #" << tt << ": ";
		cout << ans << endl;

	}
	return 0;
}