#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> ady[1000];

int dfs (int u, int p)
{
	int c = 0;
	int total = 0;
	
	for (int i = 0; i < ady[u].size(); i += 1)
	{
		int dv = ady[u][i];
		
		if (dv != p)
		{
			++c;
			int ans = dfs(dv,u);
			total += ans;
		}
	}
	
	if (!c) return 0;
	
	if (c == 1) return 1+total;
	
	return total+c-2;
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; t += 1)
	{
		int n;
		scanf("%d",&n);
		
		for (int i = 0; i < n-1; i += 1)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			
			ady[a-1].push_back(b-1);
			ady[b-1].push_back(a-1);
		}
		
		int minV = n-1;
		for (int i = 0; i < n; i += 1)
		{
			minV = min(minV,dfs(i,i));
		}
		
		printf("Case #%d: %d\n",t,minV);
		
		for (int i = 0; i < n; i += 1)
		{
			ady[i].clear();
		}
	}
	
	return 0;
}
