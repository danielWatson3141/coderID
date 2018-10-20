#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

const int INF = 123123123;

int N;
vector<int> G[1010];
int size[1010];

int get_size(int u, int p)
{
	size[u] = 1;
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(v == p) continue;
		get_size(v, u);
		size[u] += size[v];
	}
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return (a.first - a.second < b.first - b.second);
}
int compute(int u, int p) // min nodes we need to delete to KEEP this node
{
	vector< pair<int, int> > subs; // (keep, delete)
	for(int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if(v == p) continue;
		subs.push_back(make_pair(compute(v, u), size[v]));
	}
	if(subs.size() == 0) return 0;
	if(subs.size() == 1) return subs[0].second;
	sort(subs.begin(), subs.end(), cmp);
	int total = 0;
	for(int i = 0; i < 2; i++) total += subs[i].first;
	for(int i = 2; i < subs.size(); i++) total += subs[i].second;
	return total;
}

int main2()
{
	for(int i = 0; i < 1010; i++) G[i].clear();
	cin >> N;
	for(int i = 1; i <= N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int best = INF;
	for(int i = 1; i <= N; i++)
	{
		get_size(i, -1);
		best = min(best, compute(i, -1));
	}
	cout << best << endl;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		main2();
	}
}
