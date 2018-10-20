#include <bits/stdc++.h>
using namespace std;

int n, f[1010]; 
vector <int> a[1010];

void calc(int x, int par)
{
	int max1 = 0, max2 = 0;
	for (int i = 0; i < int(a[x].size()); i++)
	{
		int y = a[x][i];
		if (y == par) continue;
		calc(y, x);
		if (f[y] > max1) max2 = max1, max1 = f[y];
		else
			if (f[y] > max2) max2 = f[y];
	}
	
	if (max2) f[x] = max2 + max1 + 1;
	else f[x] = 1;
}	

int main()
{
	freopen("b-large.in", "r", stdin); 
	freopen("b-large.out", "w", stdout);
	int test, x, y;
	cin >> test;
	for (int noTest = 1; noTest <= test; noTest++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) a[i].clear();
		for (int i = 1; i < n; i++) 
		{
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		
		int ans = 1;
		for (int i = 1; i <= n; i++) 
		{
			calc(i, 0);
			ans = max(ans, f[i]);
		}
		
		printf("Case #%d: %d\n", noTest, n - ans);
	}
}
