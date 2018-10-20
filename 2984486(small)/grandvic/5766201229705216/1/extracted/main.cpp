#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

int n;
vector<vector<int> > g;

int dfs(int r, int p=-1)
{
	if(p==-1 && g[r].size()==1){return 1;}
	if(p!=-1 && g[r].size()<3){return 1;}

	int best1 = 0, best2 = 0;

	for(int i=0; i<g[r].size(); ++i)
	{
		int to = g[r][i];
		if(to==p)continue;
		int res = dfs(to, r);
		if(best2<res)best2 = res;
		if(best2>best1)swap(best1, best2);
	}

	return 1 + best1 + best2;
}

void solve()
{
	cin>>n; g.clear(); g.resize(n);
	for(int i=1; i<n; ++i)
	{
		int x, y; cin>>x>>y; --x; --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int best = 0;
	for(int i=0; i<n; ++i)
	{
		best = max(best, dfs(i));
	}
	cout<<(n-best)<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("i:/input.txt", "rt", stdin);
#endif
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}

	return 0;
} 
