#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, t[2000];

int sum(int x) {
	int ret = 0;
	for (; x; x -= x & -x) ret += t[x];
	return ret; 
}

void add(int x) {
	for (; x <= n; x += x & -x) t[x] ++;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);

	int _, __ = 1;
	for (scanf("%d", &_); __ <= _; ++ __) {
		printf("Case #%d: ", __);

		scanf("%d", &n);

		int p = 0;

		memset(t, 0, sizeof t);

		for (int i = 0; i < n; ++ i) {
			int x; scanf("%d", &x);
			p += i - sum(x); // printf("%d %d ", i, sum(x)); 
			add(x + 1); 
		}


		 printf("%d %d\n", p, n * (n - 1) / 4); 

		int judgement = n * (n - 1) / 4;

		if (p > judgement || judgement - p < 10000) puts("GOOD");
		else puts("BAD"); 
	}
}