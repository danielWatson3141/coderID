#include <cstdio>
#include <vector>
#include <algorithm>

const int INF = 2147483647;

int N, L;

char buf[50];
int out[151][50];
int dev[151][50];
int sw[50];
bool use[151];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d%d", &N, &L);
		//printf("== %d %d\n", N, L);
		for (int i = 0; i < N; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < L; ++j)
				out[i][j] = buf[j] - '0';
		}
		for (int i = 0; i < N; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < L; ++j)
				dev[i][j] = buf[j] - '0';
		}
		int ans = INF;
		for (int i = 0; i < 1; ++i) {
			for (int j = 0; j < N; ++j) {
				int t_ans= 0;
				//printf("%d %d\n", i, j);
				for (int k = 0; k < L; ++k) {
					if (out[i][k] != dev[j][k]) sw[k] = 1;
					else sw[k] = 0;
					t_ans += sw[k];
					//printf("%d ", sw[k]);
				}
				//putchar('\n');
				if (t_ans >= ans) continue;
				std::vector<long long> a;
				std::vector<long long> b;
				for (int k = 0; k < N; ++k) {
					if (k == i) continue;
					long long tmp = 0;
					for (int p = 0; p < L; ++p)
						tmp = (tmp << 1) + (out[k][p] ^ sw[p]);
					a.push_back(tmp);
					//printf("%lld\n", tmp);
				}
				for (int k = 0; k < N; ++k) {
					if (k == j) continue;
					long long tmp = 0;
					for (int p = 0; p < L; ++p)
						tmp = (tmp << 1) + dev[k][p];
					b.push_back(tmp);
					//printf("%lld\n", tmp);
				}
				std::sort(a.begin(), a.end());
				std::sort(b.begin(), b.end());
				bool valid = true;
				for (int k = 0; k < a.size() && valid; ++k)
					if (a[k] != b[k]) valid = false;
				if (valid) ans = t_ans;
			}
		}
		printf("Case #%d: ", t);
		if (ans == INF) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
}