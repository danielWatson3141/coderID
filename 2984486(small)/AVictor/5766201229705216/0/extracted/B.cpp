#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <limits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;


typedef pair<int, int> ii;
int N;
vector<vector<int> > ways;

ii dfs(int v, int p)
{
	vector< ii > d;
	int total = 0;
	for(int i=0;i<ways[v].size();i++)
	{
		int x = ways[v][i];
		if (x==p) continue;
		ii t = dfs(x, v);
		d.push_back(t);
		total += t.second;
	}	
	int M = d.size();
	if (M==0) return ii(0, 1);
	else if (M==1) return ii(total, total+1);
	else
	{
		int best = 1000000;
		for(int i=0;i<M;i++)
			for(int j=i+1;j<M;j++)
			{
				best = min(best, d[i].first+d[j].first+total-d[i].second-d[j].second);
			}
		return ii(best, total+1);
	}
}

int main()
{
	int test_cnt;
	cin >> test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		cin >> N;
		ways.clear();
		ways.resize(N);
		for(int i=0;i<N-1;i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			ways[a].push_back(b);
			ways[b].push_back(a);
		}
		int best = 1000000;
		for(int root=0;root<N;root++)
		{
			ii t = dfs(root, -1);
			best = min(best, t.first);
		}
		printf("Case #%d: %d\n", test_num, best);		
	}
    
	return 0;
}
