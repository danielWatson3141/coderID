#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;

char buf[1000];
long long outlet[1000], device[1000];

long long str2ll(const char *s) {
	long long ret = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		ret *= 2;
		ret += s[i] - '0';
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int re = 1; re <= T; ++re) {
		int n, l;
		scanf("%d%d", &n, &l);
		for (int i = 0; i < n; ++i) {
			scanf(" %s", buf);
			outlet[i] = str2ll(buf);
		}

		for (int i = 0; i < n; ++i) {
			scanf(" %s", buf);
			device[i] = str2ll(buf);
		}

		int ans = 10000000;
		for (int i = 0; i < n; ++i) {
			long long flip = device[i] ^ outlet[0];
			vector<long long> d;
			vector<long long> o;
			for (int j = 0; j < n; ++j) {
				d.push_back(device[j]);
				o.push_back(outlet[j] ^ flip);
			}
			sort(d.begin(), d.end());
			sort(o.begin(), o.end());
			if (d == o) {
				ans = min(ans, __builtin_popcount(flip));
			}
		}
		printf("Case #%d: ", re);
		if (ans <= l) {
			printf("%d\n", ans);
		} else {
			puts("NOT POSSIBLE");
		}
	}
	return 0;
}