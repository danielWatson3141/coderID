#include<cstdio>
#include<cstdlib>
#include<queue>
#include<cmath> 
#include<cstring> 
#include<map> 
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> adj[1024];
bool used[1024];

int UU;

int dfs_UU(int v)
{
	int i, j, n;
	int cc = 0;
	int ret = 1;
	used[v] = true;
	for(i = 0; i < adj[v].size(); i ++)
	{
		int nv = adj[v][i];
		if(used[nv])continue;
		if((1<<(nv-1))&UU)continue;
		
		int tmp = dfs_UU(nv);
		if(tmp == -1)return -1;
		ret += tmp;
		cc ++;
	}
	
	used[v] = false;
	if(cc != 2 && cc != 0)return -1;
	return ret;
}


int dfs(int v)
{
	int i, j, n;
	int ret = 1;
	int tmp1, tmp2, tmp3;
	used[v] = true;
	tmp1 = tmp2 = 0;
	for(i = 0; i < adj[v].size(); i ++)
	{
		int nv = adj[v][i];
		if(used[nv])continue;
		
		tmp3 = dfs(nv);
		if(tmp3 > tmp1)
		{
			if(tmp3 > tmp2)
			{
				tmp2 = tmp3;
			}
			else 
			{
				tmp1 = tmp3;
			}
		}
	}
	if(tmp1 > 0 )ret += (tmp1 + tmp2);
	used[v] = false;
	return ret;
}

int count(int a)
{
	int ret = 0;
	while(a > 0)
	{
		if(a&1)ret ++;
		a /= 2;
	}
	return ret;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++)
	{
		int n;
		scanf("%d", &n);
		int i, j;
		for(i = 1; i <= n; i++)adj[i].clear();
		for(i = 0; i < n-1; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int ans = 0;
		
		for(UU = 0; UU < (1<<n); UU ++)
		{
			bool flag = false;
			for(i = 1; i <= n; i ++)
			{
				if((1<<(i-1))&UU)continue;
				memset(used, false, sizeof(used));
				ans >?= dfs_UU(i);
			}
		}
		printf("Case #%d: %d\n", cas, n-ans);
	}
	return 0;
}
