#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

const int mx = 1000+10;
int n;
vector<int> g[mx];
int deg[mx];
bool vs[mx];
	
bool cmp(int x, int y){return x > y;}

int f(int r)
{
	vs[r] = 1;
	int num = 0;
	bool t[mx] = {0};
	for (int i = 0; i < g[r].size(); i++)
	{
		//cout<<i<<endl;
		if (!vs[g[r][i]]) { num ++;	t[i] = 1;}
	}
		
	if (num == 0) return 1;
	else if (num == 1) return 1;
	else
	{
		vector<int> vec;
		for (int i = 0; i < g[r].size(); i++)
			if (!vs[g[r][i]])
				vec.push_back(f(g[r][i]));
		for (int i = 1; i < vec.size(); i++)
			if (vec[i] > vec[0]) swap(vec[i], vec[0]);
		for (int i = 2; i < vec.size(); i++)
			if (vec[i] > vec[1]) swap(vec[i], vec[1]);
		return vec[0] + vec[1] + 1;
	}

}

int main ()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++)
	{
		scanf("%d", &n);
		memset(deg, 0, sizeof(deg));
		for (int i = 1; i <= n; i++)	g[i].clear();
		for (int i = 2; i <= n; i++)	{int a, b; scanf("%d%d", &a, &b); g[a].push_back(b); g[b].push_back(a); deg[a]++; deg[b]++;}
		//for(int i = 1; i <= n;i++) cout<<deg[i]<<endl;
		if (n == 2)
		{
			printf("Case #%d: %d\n", tc, 1);
			continue;
		}
		int ans = -1;
		for (int i = 1; i <= n; i++)
			if(deg[i] > 1)
			{
				memset(vs, 0, sizeof(vs));
				ans = max(ans, f(i));
			}
		printf("Case #%d: %d\n", tc, n - ans);
	}

}