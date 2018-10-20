#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define S(x) (int)x.size()

int n, subs[1005], cost[1005];
vector<int> e[1005];

int dp(int cur, int par){
	int ms = 1;
	if(cur == par && S(e[cur]) == 1){
		dp(e[cur][0], cur);
		return cost[cur] = subs[e[cur][0]];
	}
	else if(S(e[cur]) == 1){
		cost[cur] = 0;
		subs[cur] = ms;
		return cost[cur];
	}
	else if(cur != par && S(e[cur]) == 2){
		for(int i = 0; i < 2; i++){
			if(e[cur][i] == par) continue;
			dp(e[cur][i], cur);
			cost[cur] = subs[e[cur][i]];
		}
		subs[cur] = cost[cur]+ms;
		return cost[cur];
	}
	else{
		priority_queue<int> pq;
		int tot = 0;
		for(int i = 0; i < S(e[cur]); i++){
			if(e[cur][i] == par) continue;
			int a = dp(e[cur][i], cur);
			tot += subs[e[cur][i]];
			pq.push(subs[e[cur][i]]-a);
		}
		subs[cur] = tot+ms;
		cost[cur] = tot;
		for(int i = 0; i < 2; i++,pq.pop()) cost[cur] -= pq.top();
		return cost[cur];
	}
}

int main(){
	int tc;
	scanf("%d",&tc);
	for(int x = 1; x <= tc; x++){
		printf("Case #%d: ", x);
		scanf("%d",&n);
		for(int i = 0; i <= n; i++){
		    e[i].clear();
			subs[i] = -1;
			cost[i] = -1;
		}
		for(int i = 1; i < n; i++){
			int a, b;
			scanf("%d %d",&a,&b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		int best = 1000000;
		for(int i = 1; i <= n; i++){
			int cur = dp(i,i);
			if(cur < best) best = cur;			
		}
		printf("%d\n", best);
	}
	return 0;
}
