#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int casenum,T;
int n;
int ans;
const int maxn = 1010;
int d[maxn];
int del[maxn];
int cnt[maxn];
bool visit[maxn];
int g[maxn][maxn];

void dfs(int cur) {
	visit[cur] = true;
	vector<int> childdel;
	vector<int> childcnt;
	childdel.clear();
	childcnt.clear();
	cnt[cur] = 1;
	for (int i = 1; i <= d[cur]; i++) {
		int next = g[cur][i];
		if (visit[next])
			continue;
		dfs(next);
		cnt[cur] += cnt[next];
		childdel.push_back(del[next]);
		childcnt.push_back(cnt[next] - del[next]);
	}
	int childnum = childdel.size();
	if (childnum == 0) {
		return;
	}
	if (childnum == 1) {
		del[cur] = cnt[cur] - 1;
		return;
	}
	if (childnum == 2) {
		del[cur] = childdel[0] + childdel[1];
		return;
	}
	sort(childcnt.begin(), childcnt.end());
	del[cur] = cnt[cur] - 1 - childcnt[childnum - 1] - childcnt[childnum - 2];
}

int main() {
	freopen("gcj14.in","r",stdin);
	freopen("gcj14.out","w",stdout);
	cin >> T;
	for (casenum = 1; casenum <= T; casenum++) {
		cout << "Case #" << casenum << ": ";
		cin >> n;
		memset(d, 0, sizeof(d));
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			d[x]++;
			d[y]++;
			g[x][d[x]] = y;
			g[y][d[y]] = x;
		}
		ans = n;
		for (int root = 1; root <= n; root++) {
			memset(del, 0, sizeof(del));
			memset(cnt, 0, sizeof(cnt));
			memset(visit, 0, sizeof(visit));
			dfs(root);
			ans = min(ans, del[root]);
		}
		cout << ans;
		cout << endl;
	}
	return 0;
}
