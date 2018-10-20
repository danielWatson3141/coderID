#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <bitset>

#include <algorithm>
#include <cmath>
using namespace std;

int const MAX_N = 1010;
int const INT_INF = 1000000000;

int sm[MAX_N][MAX_N],sm_list[MAX_N][MAX_N],sm_len[MAX_N],dp[MAX_N],chld_subtree_count[MAX_N],nnew[MAX_N];
int n;

void dfs(int v) {
	if (nnew[v])
		return;
	nnew[v] = 1;

	int mn_1 = INT_INF, mn_2 = INT_INF;
	int ans_v1 = -1, ans_v2 = -1;

	for (int i=0; i<sm_len[v]; i++) {
		int new_v = sm_list[v][i];
		if (!nnew[new_v]) {
			dfs(new_v);

			chld_subtree_count[v] += chld_subtree_count[new_v] + 1;

			if (dp[new_v]-chld_subtree_count[new_v] < mn_1) {
				mn_2 = mn_1;
				ans_v2 = ans_v1;

				mn_1 = dp[new_v]-chld_subtree_count[new_v];
				ans_v1 = new_v;
			}
			else if (dp[new_v]-chld_subtree_count[new_v] < mn_2) {
				mn_2 = dp[new_v]-chld_subtree_count[new_v];
				ans_v2 = new_v;
			}
		}
	}

	dp[v] = chld_subtree_count[v];
	if (ans_v1 != -1 && ans_v2 != -1)
		dp[v] = min(dp[v], chld_subtree_count[v]-2 + mn_1 + mn_2);
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	for (int qq=0; qq<t; qq++) {
		printf("Case #%d: ",qq+1);

		scanf("%d",&n);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				sm[i][j] = 0;
				sm_list[i][j] = 0;
			}
			sm_len[i] = 0;
		}
		for (int i=0; i<n-1; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--; y--;
			sm[x][y] = sm[y][x] = 1;
			sm_list[x][sm_len[x]++] = y;
			sm_list[y][sm_len[y]++] = x;
		}

		int mn = INT_INF;
		
		for (int rt=0; rt<n; rt++) {
			for (int i=0; i<n; i++) {
				dp[i] = INT_INF;
				chld_subtree_count[i] = 0;
			}
			for (int i=0; i<n; i++)
				nnew[i] = 0;
			dfs(rt);
			mn = min(mn, dp[rt]);
		}

		cout<<mn<<"\n";
	}

	return 0;
}