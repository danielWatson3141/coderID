#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <string> VS;

const int MAXN = 1010;

int N;
VI adj[MAXN];
int sum[MAXN];
int dp[MAXN];

int solve (int u, int p)
{
	sum[u] = 1;
	VI son;
	
	for (int i = 0; i < adj[u].size(); ++ i)
	{
		int v = adj[u][i];
		if (v == p)	continue;
		
		solve (v, u);
		sum[u] += sum[v];
		son.PB (v);
	}
	
	int res = sum[u] - 1;
	for (int i = 0; i < son.size(); ++ i)
		for (int j = 0; j < i; ++ j)
			res = min (res, dp[son[i]] + dp[son[j]] + sum[u] - sum[son[i]] - sum[son[j]] - 1);
	return 	dp[u] = res;
}

int main()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);

	
	
	int T;	cin >> T;
	
	for (int cas = 1; cas <= T; ++ cas)
	{
		cin >> N;
		for (int i = 1; i < N; ++ i)
		{
			int u, v;
			cin >> u >> v;
			adj[u].PB (v);
			adj[v].PB (u);	
		}
		
		int res = MAXN;
		for (int i = 1; i <= N; ++ i)
		{
			res = min (res, solve (i, -1));	
		}
		cout << "Case #" << cas << ": " << res << endl;
		
		for (int i = 0; i <= N; ++ i)
		{
			adj[i].clear();	
		}	
	}
	
	
	return 0;	
}
