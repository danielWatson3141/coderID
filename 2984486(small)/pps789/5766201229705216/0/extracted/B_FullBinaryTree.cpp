#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

vector<vector<int> > graph;
bool visited[1111];

int dfs(int root, bool toDelete){
	visited[root] = true;

	int cnt = 0;
	for(int i=0; i<graph[root].size(); i++)
		if(!visited[graph[root][i]])
			cnt ++;

	if(toDelete){
		int ret = 0;
		for(int i=0; i<graph[root].size(); i++)
			if(!visited[graph[root][i]])
				ret += dfs(graph[root][i], true);
		return ret+1;
	}

	if(cnt == 2){
		int ret = 0;
		for(int i=0; i<graph[root].size(); i++)
			if(!visited[graph[root][i]])
				ret += dfs(graph[root][i], false);
		return ret;
	}
	else if(cnt == 0)
		return 0;
	else{
		int ret = 0;
		for(int i=0; i<graph[root].size(); i++)
			if(!visited[graph[root][i]])
				ret += dfs(graph[root][i], true);
		return ret;
	}
}


int n;

int main(){
	freopen("B-small-attempt2.in","r",stdin);
	freopen("out_small","w",stdout);

	int t;
	scanf("%d",&t);
	for(int tc=1; tc<=t; tc++){
		int ans=11111;
		scanf("%d",&n);
		graph = vector<vector<int> >(n+1);
		int a,b;
		for(int i=0; i<n-1; i++){
			scanf("%d%d",&a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for(int root = 1; root <= n; root ++){
			fill(visited, visited+1111, false);
			ans = min(ans, dfs(root, false));
		}

		printf("Case #%d: %d\n", tc, ans);
	}
}