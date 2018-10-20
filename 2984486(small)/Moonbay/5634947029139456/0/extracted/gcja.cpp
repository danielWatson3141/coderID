/*
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
const int INF = 0x7fffffff;
typedef long long LL;

typedef struct Node {
	char str[12];
}Node;
Node node1[12], node2[12], node3[12];
int N, L;

inline bool cmp(const Node& a,const Node& b) {
	return strcmp(a.str, b.str) < 0;
}

bool judge() {
	sort(node3, node3 + N, cmp);
	for (int i = 0; i < N; i++) {
		if (strcmp(node3[i].str, node2[i].str) != 0) {
			return false;
		}
	}
	return true;
}

int work(int a) {
	for (int i = 0; i < N; i++) {
		strcpy(node3[i].str, node1[i].str);
	}
	int t = 0, s = 0;
	while (a) {
		if (a & 1) {
			for (int i = 0; i < N; i++) {
				node3[i].str[t] = 1 - (node3[i].str[t] - '0') + '0';
			}
			s++;
		}
		t++;
		a /= 2;
	}
	if (judge()) {
		return s;
	}
	return INF;
}

int main() {
//	freopen("A-small-attempt0.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		scanf("%d%d", &N, &L);
		for (int i = 0; i < N; i++) {
			scanf("%s", node1[i].str);
		}
		for (int i = 0; i < N; i++) {
			scanf("%s", node2[i].str);
		}
		sort(node2, node2 + N, cmp);
		int tot = 1 << L, ans = INF;
		for (int i = 0; i < tot; i++) {
			ans = min(ans, work(i));
		}
		if (ans == INF) {
			printf("%s\n","NOT POSSIBLE");
		} else {
			printf("%d\n",ans);
		}
	}
	return 0;
}
