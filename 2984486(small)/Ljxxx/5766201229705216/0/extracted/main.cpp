#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int head[1000];
int id[2000], next_e[2000];

int dp[1000][2];
int n, res;

void input() {
	scanf("%d", &n);
	int edge_c = 0;
	for(int i = 0;i < n;i ++) head[i] = -1;
	for(int i = 0;i < n-1;i ++) {
		int a, b;
		scanf("%d%d", &a, &b);
		-- a; -- b;

		id[edge_c] = b;
		next_e[edge_c] = head[a];
		head[a] = edge_c;
		++ edge_c;

		id[edge_c] = a;
		next_e[edge_c] = head[b];
		head[b] = edge_c;
		++ edge_c;
	}
}

void DP(int p, int x, int keep) {
	if(dp[x][keep] != -1) return ;

	if(!keep) {
		dp[x][0] = 1;
		for(int j = head[x];j != -1;j = next_e[j]) {
			if(id[j] == p) continue;
			DP(x, id[j], 0);
			dp[x][0] += dp[id[j]][0];
		}
		return ;
	}

	dp[x][1] = dp[x][0] - 1;

	int max1 = -1, max2 = -1;
	for(int j = head[x];j != -1;j = next_e[j]) {
		if(id[j] == p) continue;
		DP(x, id[j], 1);

		int tmp = dp[id[j]][0] - dp[id[j]][1];
		if(tmp  >= max1) {
			max2 = max1;
			max1 = tmp;
		}
		else if(tmp > max2) max2 = tmp;
	}

	if(max2 != -1) dp[x][1] = dp[x][1] - max1 - max2;
}

void output() {
	res = n;
	for(int i = 0;i < n;i ++) {
		for(int j = 0;j < n;j ++) dp[j][0] = dp[j][1] = -1;
		DP(-1, i, 0);
		DP(-1, i, 1);
		if(dp[i][1] < res) res = dp[i][1];
	}
	printf("%d\n", res);
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas = 1;cas <= t;cas ++) {
		input();
		printf("Case #%d: ", cas);
		output();
	}
	return 0;
}