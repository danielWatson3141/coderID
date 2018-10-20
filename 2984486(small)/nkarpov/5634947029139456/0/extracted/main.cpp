#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define sz(c) (int)(c).size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 200;
char str[maxn];
long long a[maxn], b[maxn];
int used[maxn];

int cnt_bit(long long mask) {
	int res = 0;
	while (mask) {
		res += mask & 1;
		mask >>= 1;
	}           
	return res;
}

int check(int n, long long mask) {
	for (int i = 0; i < n; i++) used[i] = 0;
	for (int i = 0; i < n; i++) {
		int found = 0;
		for (int j = 0; j < n; j++) {
			if (!used[j] && ((a[i] ^ mask) == b[j])) {
				found = 1;
				used[j] = 1;
				break;
			}
		}
		if (!found) {
			return 0;
		}
	}
	return 1;
}

void solve(int test) {
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		a[i] = 0;
		for (int j = 0; j < l; j++) a[i] = a[i] * 2LL + (str[j] - '0');
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		b[i] = 0;
		for (int j = 0; j < l; j++) b[i] = b[i] * 2LL + (str[j] - '0');
	}
	int ans = l + 1;
	for (int j = 0; j < n; j++) { 
		long long mask = a[0] ^ b[j];
		if (check(n, mask)) ans = min(ans, cnt_bit(mask));
	}
	if (ans == l + 1) {
		printf("Case #%d: NOT POSSIBLE\n", test);
	} else {
		printf("Case #%d: %d\n", test, ans);
	}
}

int main() {
	int T; scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		solve(test);
	}
}
