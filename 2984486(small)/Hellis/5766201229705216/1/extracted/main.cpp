#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

vector <int> vec[1005];
void _addedge(int x, int y) { vec[x].push_back(y); vec[y].push_back(x); };

int vis[1005], son[1005], f[1005];

void upb12(int &x, int &y, int z)
{
	if (z > y) y = z;
	if (y > x) swap(x, y);
}
void dfs(int m)
{
	vis[m] = son[m] = f[m] = 1;
	int b1 = 0, b2 = 0;
	for (int i=0; i<vec[m].size(); i++)
		if (vis[vec[m][i]] == 0)
		{
			dfs(vec[m][i]);
			son[m] += son[ vec[m][i] ];
			upb12(b1, b2, f[vec[m][i]]);
		}
	if (b2) f[m] += b1 + b2;
}

int work(int m, int n)
{
	for (int i=1; i<=n; i++) vis[i] = son[i] = f[i] = 0;
	dfs(m);
	return n - f[m];
}

int main()
{
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int cas, T;
	//int cnt = 1;
	for (cas=scanf("%d", &T); cas<=T; cas++)
	{
		int n;
		cin >> n; //cnt++;
		for (int i=1; i<=n; i++) vec[i].clear();
		for (int i=1; i<n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			_addedge(x, y);
			//cnt ++;
		}
		//if (cas == 53) cout << cnt <<endl;
		int ans = n;
		
		for (int i=1; i<=n; i++) ans = min(ans, work(i, n)); 
		
		printf("Case #%d: %d\n", cas, ans);
	}
    return 0;
}
