#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;

ul one = 1;

int t,n,x,y,ans;
vector<int> adjList[1010];
int deg[1010];
int vis[1010];
int child[1010];
int memo[1010];

int dfs(int v, int p, int d){
	if (vis[v]) return memo[v];
//cout << v << " " << deg[v] << endl;
	vis[v] = 1;
	if (deg[v]-p == 0){
		return d;
	} else if (deg[v]-p == 2){
		int q = d;
		for (int i=0; i<adjList[v].size(); i++){
			if (!vis[adjList[v][i]]){
				q += dfs(adjList[v][i],1,d);
			}
		}
		return memo[v] = q;
	} else {
		vector<int> w;
		int q = d;
		for (int i=0; i<adjList[v].size(); i++){
			if (!vis[adjList[v][i]]){
				w.push_back(1+dfs(adjList[v][i],1,0));
			}
		}
		sort(w.begin(),w.end());
		//reverse(w.begin(),w.end());
		if (deg[v]-p == 1){
			q += w[0];
		} else {
			for (int j=0; j<deg[v]-p-2; j++){
				q += w[j+2];
			}
			if (w[0] != 0 || w[1] != 0){
				q += (w[0]+w[1]);
			}
		}
		/*
		for (int i=0; i<deg[v]-p; i++){
			cout << w[i] << " ";
		}
		cout << endl;
		*/
		return memo[v] = q;
		/*
		for (int j=0; j<adjList[v].size(); j++){
			child[j] = dfs(adjList[v][j]);
		}
		sort(child,child+n);
		ans = 0;
		if (deg[v] == 1){
			ans += child[0];
		} else {
			for (int j=0; j<deg[v]-2; j++){
				ans += child[j];
			}
		}
		*/
	}
}

int main(){
	scanf("%d",&t);
	for (int jj=1; jj<=t; jj++){
		scanf("%d",&n);
		memset(deg,0,sizeof deg);
		for (int i=0; i<n; i++) adjList[i].clear();
		for (int i=1; i<n; i++){
			scanf("%d%d",&x,&y);
			x--;y--;
			deg[x]++;deg[y]++;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		ans = 1000000000;
		for (int i=0; i<n; i++){
			memset(vis,0,sizeof vis);
			memset(memo,0,sizeof memo);
			ans = min(ans,dfs(i,0,0));
		}
		printf("Case #%d: %d\n",jj,ans);
	}
	return 0;
}
