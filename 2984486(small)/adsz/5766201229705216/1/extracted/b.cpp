#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, set<int>> tree;

pair<int, int> get_cost(int root, int parent)
{
	//<cost of repair, count of nodes here>
	vector<pair<int, int>> costs;
	for(int child : tree[root])
	{
		if(child==parent) continue;
		
		costs.push_back(get_cost(child, root));
	}
	
	pair<int, int> result;
	if(costs.size()==0)
	{
		result.first = 0;
		result.second = 1;
	}
	else if(costs.size()>=2)
	{
		//<diff, id>
		vector<pair<int, int>> diffs;
		int i=0;
		for(auto p :costs)
		{
			diffs.push_back(make_pair(p.first-p.second, i));
			i++;
		}
		sort(diffs.begin(), diffs.end());
		
		
		result.first = costs[diffs[0].second].first + costs[diffs[1].second].first;
		result.second = 1 + costs[diffs[0].second].second + costs[diffs[1].second].second;
		
		for(int i=2;i<diffs.size();i++)
		{
			int id = diffs[i].second;
			result.first += costs[id].second;
			result.second += costs[id].second;
		}
	}
	else//=1
	{
		result.second = 1 + costs[0].second;
		result.first = costs[0].second;
	}
	return result;
}

int get_cost(int root)
{
	return get_cost(root, -1).first;
}

void solve_case()
{
	tree.clear();
	
	int N;
	scanf("%d", &N);
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		tree[a].insert(b);
		tree[b].insert(a);
	}
	
	int mincost = N;
	for(int i=1;i<=N;i++)
	{
		int cost = get_cost(i);
		
		if(cost < mincost)
			mincost = cost;
	}
	printf("%d", mincost);
}


int main()
{
	int t;
	scanf("%d", &t);
	for(int cn=1;cn<=t;cn++)
	{
		printf("Case #%d: ", cn);
		solve_case();
		printf("\n");
	}
}
