#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1005;

typedef pair<int, int> PII;

int Dp[MAXN];
vector<int> Gr[MAXN];
int cases, N;

int gao(int v, int fa){
	vector<int> tmp;
	for(int i = 0; i < Gr[v].size(); ++i)
		if(Gr[v][i] != fa){
			gao(Gr[v][i], v);
			tmp.push_back(Dp[Gr[v][i]]);
		}
	sort(tmp.begin(), tmp.end());
	if(tmp.size() == 0){
		Dp[v] = 1;
	} else if(tmp.size() == 1){
		Dp[v] = 1;
	} else if(tmp.size() == 2){
		Dp[v] = tmp[0] + tmp[1] + 1;
	} else {
		Dp[v] = tmp[tmp.size() - 1] + tmp[tmp.size() - 2] + 1;
	}
}

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			Gr[i].clear();
		for(int i = 0; i < N - 1; ++i){
			int x, y;
			scanf("%d%d", &x, &y);
			--x; --y;
			Gr[x].push_back(y);
			Gr[y].push_back(x);
		}
		int ans = -1;
		for(int i = 0; i < N; ++i){
			memset(Dp, 0, sizeof(Dp));
			gao(i, -1);
			ans = max(ans, Dp[i]);
		}
		ans = N - ans;
		printf("Case #%d: %d\n", xx, ans);
	}
}
