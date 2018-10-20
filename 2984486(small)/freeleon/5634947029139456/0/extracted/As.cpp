#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 155;
bool ans;
int n, l, cnt;
int a[maxn], b[maxn];
int a1[maxn], b1[maxn];

bool same_array(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void dfs(int j, int tot) {
	if (j == -1) {
		sort(a, a+n);
		if (same_array(a, b, n) && (cnt > tot)) {
			cnt = tot;
		}
		return;
	}
	if (a1[j] == b1[j] && a1[j] == n - b1[j]) {
		dfs(j-1, tot);
		for (int i = 0; i < n; i++) {
			a[i] ^= (1 << j);
		}
		dfs(j-1, tot+1);
		for (int i = 0; i < n; i++) {
			a[i] ^= (1 << j);
		}
	} else {
		return dfs(j - 1, tot);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		scanf("%d%d", &n, &l);
		char str[100];
		for (int i = 0; i < n; i++) {
			a[i] = 0;
			scanf("%s", str);
			for (int j = 0; j < l; j++) {
				a[i] |= str[j] == '0' ? 0 : (1 << j);
			}
		}
		for (int i = 0; i < n; i++) {
			b[i] = 0;
			scanf("%s", str);
			for (int j = 0; j < l; j++) {
				b[i] |= str[j] == '0' ? 0 : (1 << j);
			}
		}
		ans = true;
		cnt = 0;
		for (int j = 0; j < l; j++) {
			a1[j] = b1[j] = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] & (1<<j)) a1[j]++;
				if (b[i] & (1<<j)) b1[j]++;
			}
			if (a1[j] == b1[j]) continue;
			if (a1[j] != b1[j] && a1[j] == n - b1[j]) {
				cnt++;
				for (int i = 0; i < n; i++) {
					a[i] ^= (1 << j);
				}
			} else {
				//puts("NOT 1");
				ans = false;
				break;
			}
		}
		if (ans) {
			if (n & 1) {
				sort(a, a + n);
				sort(b, b + n);
				ans = same_array(a, b, n);
			} else {
				int al = cnt;
				cnt = INT_MAX;
				sort(b, b + n);
				dfs(l-1, 0);
				if (cnt == INT_MAX) ans = false;
				cnt += al;
			}
		}
		printf("Case #%d: ", ca);
		if (ans) printf("%d\n", cnt);
		else puts("NOT POSSIBLE");
	}
	return 0;
}
