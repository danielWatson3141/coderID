#include <algorithm>
#include <cstdio>
#include <vector>

using std::min;
using std::vector;

const int MaxN = 1010;

int T, N, sz[MaxN], ans, cs;
bool hsh[MaxN];
vector<int> g[MaxN];

void dfs(int x) {
	hsh[x] = true;
	int a = -1, b = -1;
	for(vector<int> :: iterator cur = g[x].begin(); cur != g[x].end(); ++cur) {
		if(!hsh[*cur]) {
			dfs(*cur);
			if(sz[*cur] > a) {
				b = a;
				a = sz[*cur];
			}
			else {
				if(sz[*cur] > b) {
					b = sz[*cur];
				}
			}
		}
	}
//printf("%d: %d %d\n", x, a, b);
	if(a != -1 && b != -1) {
		sz[x] = a + b + 1;
	}
	else {
		sz[x] = 1;
	}
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i) {
			g[i].clear();
		}
		for(int i = 1; i < N; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = N;
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j) {
				hsh[j] = false;
			}
//printf("%d:\n", i);
			dfs(i);
			ans = min(ans, N - sz[i]);
		}
		printf("Case #%d: %d\n", ++cs, ans);
	}
	return 0;
}
