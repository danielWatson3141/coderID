#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;
int N, L, ans;
long long flow[155], req[155], check[155];
void go(int x, int used) {
	if (x == L) {
		for (int i = 0; i < N; ++i) check[i] = flow[i];
		sort(check, check + N);
		for (int i = 0; i < N; ++i)
			if (check[i] != req[i]) return;
		ans = min(ans, used);
		return;
	}
	map<long long, int> cnt, actual;
	for (int i = 0; i < N; ++i) {
		long long prefix = flow[i] & ((1LL << x) - 1);
		if (flow[i] & (1LL << x)) ++cnt[prefix];
		else --cnt[prefix];
		prefix = req[i] & ((1LL << x) - 1);
		if (req[i] & (1LL << x)) ++actual[prefix];
		else --actual[prefix];
	}
	bool can = true;
	for (auto i = actual.begin(); i != actual.end(); ++i) {
		long long c = cnt[i->first];
		if (i->second != c) {
			can = false;
			break;
		}
	}
	if (can) go(x + 1, used);
	can = true;
	for (auto i = actual.begin(); i != actual.end(); ++i) {
		long long c = cnt[i->first];
		if (-i->second != c) {
			can = false;
		}
	}
	if (!can) return;
	for (int i = 0; i < N; ++i) flow[i] ^= (1LL << x);
	go(x + 1, used + 1);
	for (int i = 0; i < N; ++i) flow[i] ^= (1LL << x);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d%d", &N, &L);
		ans = INT_MAX;
		memset(flow, 0, sizeof(flow));
		memset(req, 0, sizeof(req));
		char str[45];
		for (int i = 0; i < N; ++i) {
			scanf("%s", str);
			for (int j = 0; j < L; ++j)
				if (str[j] == '1') flow[i] += 1LL << j;
		}
		for (int i = 0; i < N; ++i) {
			scanf("%s", str);
			for (int j = 0; j < L; ++j)
				if (str[j] == '1') req[i] += 1LL << j;
		}
		sort(req, req + N);
		go(0, 0);
		printf("Case #%d: ", cn);
		if (ans == INT_MAX) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
}

