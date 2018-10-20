#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int count_bits(int b) {
	int r = 0;
	while (b) {
		b &= (b - 1);
		r++;
	}
	return r;
}

bool conn[16][16];
int n, i, cnt;

bool nav(int a, int p, bool r) {
	int j, c = 0;
	cnt++;
	for (j = 0; j < n; j++) {
		if (!(i & 1 << j)) {
			if (conn[a][j]) {
				c++;
			}
		}
	}
	if (c > 3) {
		return false;
	}
	if (c == 2) {
		if (r) {
			return false;
		}
		r = true;
	}
	for (j = 0; j < n; j++) {
		if (!(i & 1 << j)) {
			if (conn[a][j]) {
				if (j != p) {
					if (!nav(j, a, r)) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	int t, T;
	int a, b, o;
	int r, j;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &n);
		r = n;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				conn[i][j] = false;
			}
		}
		for (i = 0; i < (n - 1); i++) {
			scanf("%d%d", &a, &b);
			a--;
			b--;
			conn[a][b] = true;
			conn[b][a] = true;
		}
		for (i = 0; i <= (1 << n + 1); i++) {
			o = count_bits(i);
			for (j = 0; i & 1 << j; j++);
			cnt = 0;
			if (nav(j, -1, false) && cnt == (n - o)) {
				if (o < r) {
					r = o;
				}
			}
		}
		printf("Case #%d: %d\n", t, r);
	}
	return EXIT_SUCCESS;
}
