#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <ctime>
#include <stdint.h>

using namespace std;

const int MAXN = 1010;

int n;
vector<int> a[MAXN];
bool vis[MAXN];

void Search(int now, int &cost_left, int &cost_del) {
	int left[3];
	int sum_del = 0;
	vis[now] = true;
	left[0] = left[1] = left[2] = 0;
	int num = a[now].size();
	for (uint32_t i = 0; i < a[now].size(); ++i) {
		if (vis[a[now][i]]){
			num--;
			continue;
		}
		int tmp1, tmp2;
		Search(a[now][i], tmp1, tmp2);
		sum_del += tmp2;
		left[0] = tmp2 - tmp1;
		sort(left, left + 3);
	}
	if (num < 2) {
		cost_left = sum_del;
	} else {
		cost_left = sum_del - left[1] - left[2];
	}
	cost_del = sum_del+1;
//	printf("n:%d l:%d d:%d\n", now, cost_left, cost_del);
}

int Solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		a[i].clear();
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int ans = n;
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		int cost_left, cost_del;
		Search(i, cost_left, cost_del);
		if (cost_left < ans) {
			ans = cost_left;
//			printf("%d:%d\n", i, ans);
		}
	}
	return ans;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out-small.txt", "w", stdout);
	int nCase;
	scanf("%d", &nCase);
	for (int t = 1; t <= nCase; ++t) {
		printf("Case #%d: %d\n", t, Solve());
	}
	return 0;
}

