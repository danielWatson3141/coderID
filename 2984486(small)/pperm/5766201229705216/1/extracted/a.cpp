#pragma comment(linker, "/STACK:128777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>
#include <windows.h>

typedef long long i64;
typedef unsigned int u32;
const int null = 0;

using namespace std;

typedef vector<int> VI;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T abs(const T &a) {
	return (a < 0? -a: a);
}
template<class T> T sqr(const T &a) {
	return a * a;
}

#define all(a) a.begin(),a.end()

vector<VI> edges;

int dfs(int i, int p) {
	VI &edges = ::edges[i];
	int mx1 = -1, mx2 = -1;
	for (int v : edges) {
		if (v == p) continue;
		int t = dfs(v, i);
		if (t > mx1) {
			mx2 = mx1;
			mx1 = t;
		} else if (t > mx2) {
			mx2 = t;
		}
	}
	if (mx2 == -1) {
		return 1;
	} else {
		return mx1 + mx2 + 1;
	}
}

int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		int n;
		cin >> n;
		edges.clear();
		edges.resize(n);
		for (int i = 1; i < n; i++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);
			v1--, v2--;
			edges[v1].push_back(v2);
			edges[v2].push_back(v1);
		}
		int res = n - 1;
		for (int i = 0; i < n; i++) {
			res = min(res, n - dfs(i, -1));
		}
		printf("Case #%d: %d\n", iTest, res);
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}