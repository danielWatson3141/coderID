#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> list[1024];
int Dy[1024];
bool chk[1024];
int N;

void dfs(int x) {
	chk[x] = true;

	int mx1, mx2;
	mx1 = mx2 = -1;
	for (int i = 0; i < list[x].size(); i++) {
		int v = list[x][i];
		if (!chk[v]) {
			dfs(v);
			if (mx1 < Dy[v]) {
				mx2 = mx1;
				mx1 = Dy[v];
			}
			else if (mx2 < Dy[v]) {
				mx2 = Dy[v];
			}
		}
	}
	Dy[x] = 1;
	if (mx2 >= 0) {
		Dy[x] += mx1 + mx2;
	}
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		for (int i = 0; i < N-1; i++) {
			int a, b;
			scanf("%d %d", &a, &b); 
			a--; b--;
			list[a].push_back(b);
			list[b].push_back(a);
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				chk[j] = false;
				Dy[j] = 1;
			}
			dfs(i);
			if (ans < Dy[i]) ans = Dy[i];
		}
		for (int i = 0; i < N; i++) {
			list[i].clear();
		}
		static int cs = 1;
		printf("Case #%d: %d\n", cs++, N-ans);
	}
	return 0;
}