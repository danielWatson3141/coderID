#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>

#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)

using namespace std;

vector<set<int>> v;
map<pair<int, int>, int> edgecount;
map<pair<int, int>, int> edgedel;

void calcedge(int from, int to)
{
	if (edgecount.count(make_pair(from, to)) > 0) return;
	int &count = edgecount[make_pair(from, to)];
	int &del = edgedel[make_pair(from, to)];
	count = 0;
	vector<int> maxkeep;
	for (auto it = v[to].begin(); it != v[to].end(); it++)
	{
		if (*it == from) continue;
		pair<int, int> p = make_pair(to, *it);
		if (edgecount.count(p) == 0)
		{
			calcedge(to, *it);
		}
		count += edgecount[p] + 1;
		maxkeep.push_back(edgecount[p] - edgedel[p]);
	}
	if (maxkeep.size() < 2)
		del = count;
	else
	{
		sort(maxkeep.begin(), maxkeep.end());
		del = count - (maxkeep[maxkeep.size() - 1]
			+ maxkeep[maxkeep.size() - 2] + 2);
	}
}

void calc()
{
	static int caseno = 0;
	caseno++;
	cerr << "Case #" << caseno << endl;

	// code begin

	int n;
	cin >> n;

	v = vector<set<int>>(n + 1, set<int>());
	edgecount = map<pair<int, int>, int>();
	edgedel = map<pair<int, int>, int>();

	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}

	int bestdel = n-1;



	for (int i = 1; i <= n; i++)
	{
		calcedge(0, i);
		int del = edgedel[make_pair(0, i)];
		if (del < bestdel) bestdel = del;
	}

	// code end

	cout << "Case #" << caseno << ": ";
	cout << bestdel;
	cout << endl;
}

int main()
{
	int k = 1;
	cin >> k;
	while (k-- > 0)
	{
		calc();
	}

	return 0;
}

