//============================================================================
// Name        : cf.cpp
// Author      : HX
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#define RD(x) scanf("%d", &x)
#define REP(i, n) for (int i=0; i<(n); i++)
#define REP1(i, n) for (int i=1; i<=(n); i++)
#define pii pair<int, int>
#define piL pair<int, LL>
#define mp make_pair

using namespace std;
#define  N   111111
#define  M   22222
#define  eps 1e-9
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long

//struct Edge {
//	int v, num, size;
//	friend bool operator < (const Edge &a, const Edge &b) {
//		return a.num - a.size < b.num - b.size;
//	}
//	Edge(){}
//	Edge(int vv, int nnum) : v(vv), num(nnum) {}
//};
//vector <Edge> node[N];
//int ans, n;
//pii dfs(int u, int fa = 0) {
//	int child = 0;
//	int sz = 1;
//	REP(i, node[u].size()) {
//		if (node[u][i].v == fa)
//			continue;
//		child++;
//		pii tmp = dfs(node[u][i].v, u);
//		node[u][i].num = tmp.first;
//		node[u][i].size = tmp.second;
//		sz += tmp.second;
//	}
//	if (child == 0)
//		return mp(0, sz);
//	if (child == 1)
//		return mp(sz-1, sz);
//	int ret = inf;
//	REP(i, node[u].size()) {
//		if (node[u][i].v == fa)
//			continue;
//		REP(j, i) {
//			if (node[u][j].v == fa)
//				continue;
//			ret = min(ret,
//				sz - 1 - node[u][i].size + node[u][i].num - node[u][j].size + node[u][j].num);
//		}
//	}
//	return mp(ret, sz);
//}
//
//void dfs1(int u, int fa=0, int fnum=0, int fsize=0) {
//	REP(i, node[u].size()) if (node[u][i].v == fa) {
//		node[u][i].num = fnum;
//		node[u][i].size = fsize;
//		break;
//	}
//	sort(node[u].begin(), node[u].end());
//	if (node[u].size() > 1) {
//		ans = min(ans, n-1 +
//				node[u][0].num - node[u][0].size + node[u][1].num - node[u][1].size);
//	}
//	REP(i, node[u].size()) {
//		if (node[u][i].v == fa)
//			continue;
//		int sz = n-1 - node[u][i].size;
//		if (node[u].size() == 2) {
//			dfs1(node[u][i].v, u, sz, sz+1);
//		} else {
//			int cao = sz;
//			for (int j=0, c=0; j<node[u].size()&&c<2; j++) {
//				if (i == j)
//					continue;
//				c++;
//				cao += node[u][j].num - node[u][j].size;
//			}
//			dfs1(node[u][i].v, u, cao, sz+1);
//		}
//	}
//}
//
//int main() {
//	freopen("B-large.in", "r", stdin);
//	freopen("out1.txt", "w", stdout);
//	int T; RD(T);
//	REP1(t, T) {
//		RD(n);
//		REP1(i, n) node[i].clear();
//		REP(i, n-1) {
//			int u, v; RD(u); RD(v);
//			node[u].push_back(Edge(v, inf));
//			node[v].push_back(Edge(u, inf));
//		}
//		ans = dfs(1).first;
//		dfs1(1);
//		cout << "Case #" << t << ": " << ans << endl;
//	}
//
//	return 0;
//}



string outlet[N];
string device[N];
int main() {
	freopen("A-small-attempt0 (1).in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cases; cin >> cases;
	REP1(T, cases) {
		int n, l;
		cin >> n >> l;
		REP(i, n) cin >> outlet[i];
		REP(i, n) cin >> device[i];
		sort(device, device + n);
		bool flag = false;
		int ans = inf;
		REP(i, 1<<l) {
			int cnt = 0;
			REP(j, l) {
				if ((i>>j) & 1) {
					cnt++;
					REP(k, n) {
						outlet[k][j] = '1' - outlet[k][j] + '0';
					}
				}
			}
			sort(outlet, outlet + n);
			bool ok = true;
			REP(o, n) {
				if (outlet[o] != device[o]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				flag = true;
				ans = min(ans, cnt);
			}
			REP(j, l) {
				if ((i>>j) & 1) {
					REP(k, n) {
						outlet[k][j] = '1' - outlet[k][j] + '0';
					}
				}
			}
		}
		cout << "Case #" << T << ": ";
		if (!flag) cout << "NOT POSSIBLE" << endl;
		else cout << ans << endl;
	}

	return 0;
}
