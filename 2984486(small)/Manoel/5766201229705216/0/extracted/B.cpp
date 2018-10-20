#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

#define MAXN 1005

using namespace std;

vector<int> adj[MAXN+1];

int dfs(int node, int p)
{
	int ans = 1;
	
	if((adj[node].size() == 2 && p==-1) || adj[node].size() == 3)
		for(int i=0; i<adj[node].size(); i++)
			if(adj[node][i] != p)
				ans += dfs(adj[node][i], node);
	
	return ans;
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	
	int nt, t=1;
	scanf(" %d", &nt);
	
	while(nt--)
	{
		int n;
		scanf(" %d", &n);
		
		for(int i=0; i<MAXN; i++)
			adj[i].clear();
		
		for(int i=0; i<n-1; i++)
		{
			int a, b;
			scanf(" %d %d", &a, &b);
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int ans = n;
		
		for(int i=1; i<=n; i++)
			ans = min(ans, n-dfs(i, -1));
		
		printf("Case #%d: %d\n", t++, ans);
	}
	
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
}
