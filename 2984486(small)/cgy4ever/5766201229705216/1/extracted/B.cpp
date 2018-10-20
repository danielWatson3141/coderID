#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n;
vector <int> e[1001];

int dfs(int cur, int from)
{
	vector <int> sons;
	for(int i = 0; i < e[cur].size(); i++)
	{
		int t = e[cur][i];
		if(t == from) continue;
		sons.push_back(dfs(t, cur));
	}
	if(sons.size() < 2) return 1;
	int max1 = 0, max2 = 0;
	for(int i = 0; i < sons.size(); i++)
	{
		if(sons[i] > max2) max2 = sons[i];
		if(max2 > max1) swap(max1, max2);
	}
	return 1 + max1 + max2;
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		e[i].clear();
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dfs(i, -1));
	cout << n - ans << endl;
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
