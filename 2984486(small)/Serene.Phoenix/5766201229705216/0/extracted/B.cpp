#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define maxn 1010
using namespace std;

int Tn;
int n;
class Edge
{
public:
	int st,dest;
	Edge(int s,int t)
	{
		st = s;
		dest = t;
	}
};
vector<Edge> edges[maxn];

int search(int node, int par)
{
	int res = 0;
	int i;

	vector<int> subtrees;
	subtrees.clear();
		for (i=0;i<edges[node].size();i++)
			if (edges[node][i].dest != par)
				subtrees.push_back(search(edges[node][i].dest, node));
	
	if (subtrees.size() == 0)
		return 1;
	if (subtrees.size() == 1)
		return 1;

	sort(subtrees.begin(), subtrees.end(),std::greater<int>());
	return 1 + subtrees[0] + subtrees[1];
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small.out","w",stdout);
	cin >> Tn;
	int i;
	for (int t=1;t<=Tn;t++)
	{
		cin >> n;
		for (i=1;i<=n;i++)
			edges[i].clear();
		for (i=0;i<n-1;i++)
		{
			int ss,tt;
			cin >> ss >> tt;
			edges[ss].push_back(Edge(ss,tt));
			edges[tt].push_back(Edge(tt,ss));
		}

		int ans = 0;
		for (i=1;i<=n;i++)
			ans = max(ans, search(i,-1));

		cout << "Case #" << t << ": " << n - ans << endl;

	}
}