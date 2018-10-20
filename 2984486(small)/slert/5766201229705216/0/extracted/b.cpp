#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<int> adj[1001];
vector<int> r[2][1001];
int vis[1001];
int dfs(int i, int q){
	vis[i] = 1;	
	int degleft = 0;
	int vn = adj[i].size();
	for(int j = 0; j < adj[i].size(); j++){
		if(!vis[adj[i][j]]){
			degleft++;
		}
		else vn = j;
	}
	// printf("%d(%d,%d) ",i,q,vn);
	if(r[q][i][vn] >= 0){
		vis[i] = 0;
		return r[q][i][vn];
	}

	if(q == 1){
		int x = 1;
		for(int j = 0; j < adj[i].size(); j++){
			if(!vis[adj[i][j]])
				x += dfs(adj[i][j],1);
		}		
		r[q][i][vn]=x;
	}else{
		if(degleft == 0){
			r[q][i][vn]=0;
		}
		else if(degleft == 2){
			int x = 0;
			for(int j = 0; j < adj[i].size(); j++){
				if(!vis[adj[i][j]])
					x += dfs(adj[i][j],0);
			}
			r[q][i][vn]=x;
		}
		else if(degleft == 1){
			for(int j = 0; j < adj[i].size(); j++){
				if(!vis[adj[i][j]]){
					int x = dfs(adj[i][j],1);
					r[q][i][vn]=x;
					break;
				}
			}
		}
		else{
			int x=0;
			int b[n];
			int k = 0;
			for(int j = 0; j < adj[i].size(); j++){
				if(!vis[adj[i][j]]){
					int p0 = dfs(adj[i][j],0);
					int p1 = dfs(adj[i][j],1);
					x+= p1;
					b[k++] = p0-p1;
				}
			}
			sort(b,b+k);
			r[q][i][vn] = x+b[0]+b[1];
		}
	}
	vis[i] = 0;
	return r[q][i][vn];
}

int main(){
	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			adj[i].clear(); r[0][i].clear(); r[1][i].clear();
			r[0][i].push_back(-1);
			r[1][i].push_back(-1);
		}
		for(int i = 1; i < n; i++)
		{
			int a,b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b); r[0][a].push_back(-1);r[1][a].push_back(-1);
			adj[b].push_back(a); r[0][b].push_back(-1);r[1][b].push_back(-1);
		}
		int m = n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++)
				vis[j] = 0;
			int x = dfs(i,0);
			if(x < m)
				m = x;
		}
		printf("Case #%d: %d\n", ti, m);
	}
	return 0;
}