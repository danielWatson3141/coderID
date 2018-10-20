#include <cstdio>
#include <set>
#include <string>
#include <iostream>

using namespace std;

const int N = 160;
const int L = 45;

int n, l;
string outlet[N], device[N];

int same(int len) {
	multiset<string> a, b;
	for (int i = 0; i < n; i++) {
		string &cur = outlet[i];
		a.insert(cur.substr(0, len));
	}
	for (int i = 0; i < n; i++) {
		string &cur = device[i];
		b.insert(cur.substr(0, len));
	}
	return a == b;
}

void flip_k(int k) {
	for (int i = 0; i < n; i++) {
		if (outlet[i][k] == '0') {
			outlet[i][k] = '1';
		} else if (outlet[i][k] == '1') {
			outlet[i][k] = '0';
		}
	}
}

int dfs(int dep, int sw) {
	if (dep == l) return sw;
	if (same(dep + 1)) {
		return dfs(dep + 1, sw);
	} else {
		flip_k(dep);
		if (same(dep + 1)) {
			return dfs(dep + 1, sw + 1);
		} else {
			return -1;
		}
	}
}

int main() {
	int cas; scanf("%d", &cas);
	for (int ca = 1; ca <= cas; ca++) {
		scanf("%d%d", &n, &l);
		for (int j = 0; j < n; j++) {
			cin >> outlet[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> device[j];
		}
		int ans = L;
		for (int i = 0; i < 1 << l; i++) {
			int cur = 0;
			for (int j = 0; j < l; j++) {
				if (i & (1 << j)) {
					cur++;
					flip_k(j);
				}
			}
			if (same(l)) {
				//printf("cur: %d\n", cur);
				ans = min(ans, cur);
			}
			for (int j = 0; j < l; j++) {
				if (i & (1 << j)) flip_k(j);
			}
		}
		printf("Case #%d: ", ca);
		if (ans == L) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
