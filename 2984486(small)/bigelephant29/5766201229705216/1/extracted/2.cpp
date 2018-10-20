#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 1000 + 10;
const int INF = 2147483647;
const int MINF = -INF;

int n, dp[MAX];
bool vis[MAX];
vector<int> v[MAX];

int dfs(int x){
	vis[x] = true;
	int siz = (int) v[x].size(), cnt = 0, sum = 1, max1 = 0, max2 = 0;
	for(int i = 0 ; i < siz ; i++) if(!vis[v[x][i]]){
		cnt++;
		int tmp = dfs(v[x][i]);
		int tmax = tmp - dp[v[x][i]];
		if(tmax > max1) max2 = max1, max1 = tmax;
		else if(tmax > max2) max2 = tmax;
		sum += tmp;
	}
	if(cnt < 2) dp[x] = sum - 1;
	else{
		if(max1==0 && max2==0){
			dp[x] = sum-1;
		}else if(max2==0){
			dp[x] = sum-1;
		}else{
			dp[x] = sum-1-max1-max2;
		}
	}
	vis[x] = false;
	return sum;
}

int root(int x){
	dfs(x);
	return dp[x];
}

int main(){
	int TN, x, y;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		int ans = INF;
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 1 ; i <= n ; i++) v[i].clear();
		for(int i = 1 ; i < n ; i++){
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i = 1 ; i <= n ; i++){
			ans = min(ans, root(i));
		}
		printf("Case #%d: %d\n", casen, ans);
	}
	return 0;
}
