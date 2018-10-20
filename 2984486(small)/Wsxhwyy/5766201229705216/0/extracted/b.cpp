#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
vector<vector<int> > edges;
int vis[2000];

void dfs(int root, int& nc)
{
    vis[root] = 1;
    nc = 1;
    int childnc;
    int childs = 0, can = 0;
    vector<pair<int, int> > childvec;
    for (int i = 0; i < edges[root].size(); i++)
    {
	if (!vis[edges[root][i]])
	{
	    childs++;
	    dfs(edges[root][i], childnc);
	    childvec.push_back(make_pair(childnc, edges[root][i]));    
	}
    }
    sort(childvec.rbegin(), childvec.rend());
    if (childs >= 2)
    {
	nc += childvec[0].first;
	nc += childvec[1].first;
    }
}

int work(int root)
{
    memset(vis, 0, sizeof vis);
    int i = 0;
    dfs(root, i);
    return i;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
	int N;
	cin >> N;
	edges.clear();
	edges.resize(N + 1);
	for (int i = 1; i < N; i++)
	{
	    int a, b;
	    cin >> a >> b;
	    edges[a].push_back(b);
	    edges[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	    ans = max(ans, work(i));
	cout << "Case #" << t << ": " << N - ans << endl;
    }
}
