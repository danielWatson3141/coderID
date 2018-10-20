#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<map>
using namespace std;
#define PII pair<int,int>
#define X first
#define Y second
#define PB push_back
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FOE(i,a,b) for (int i=(a);i<=(b);i++)
#define INF (1 << 30)
#define EPS (1e-9)
#define REP(i,n) FOR(i,0,n)
#define LL long long
#define N 1010
int n, m;
int T;
int pre[N];
int dp[N], size[N];
vector<int> vec[N];

int find(int x){
	if (dp[x] != -1) return dp[x];
	int ret = 0;
	int a[N][3] = {0}, tmp = 1;
	FOR(i,0,vec[x].size()){
		int y = vec[x][i];
		if (y == pre[x]) continue;
		pre[y] = x;
		int f = find(y);
		size[x] += size[y];
		a[tmp][0] = a[tmp - 1][0] + size[y];
		a[tmp][1] = min(a[tmp - 1][1] + size[y], a[tmp - 1][0] + f);
		a[tmp][2] = min(a[tmp - 1][2] + size[y], a[tmp - 1][1] + f);
		tmp++;
	}
	tmp--;
	if (tmp < 2) ret = a[tmp][0];
	else ret = a[tmp][2];
	size[x]++;

	return dp[x] = ret;
}

int main(){
	scanf("%d", &T);
	FOE(cc,1,T){
		scanf("%d", &n);
		FOR(i,0,n) vec[i].clear();
		FOR(i,0,n - 1){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			vec[x].PB(y);
			vec[y].PB(x);
		}
		int ans = N;
		FOR(i,0,n){
			memset(pre, -1, sizeof(pre));
			memset(size, 0, sizeof(size));
			memset(dp, -1, sizeof(dp));
			ans = min(ans, find(i));
			//printf("%d %d\n", size[0], find(i));
		}
		printf("Case #%d: ", cc);
		printf("%d\n", ans);
	}
	return 0;
}

