#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))

int del(const vector<vector<int>> &edge, int now, int parent, vector<vector<int>> &deltab)
{
	if(parent == -1)
		parent = now;

	if(deltab[parent][now] != -1)
		return deltab[parent][now];

	int res = 1;
	rep(i, edge[now].size()) {
		if(edge[now][i] == parent)
			continue;
		res += del(edge, edge[now][i], now, deltab);
	}
	return deltab[parent][now] = res;
}

int check(const vector<vector<int>> &edge, int now, int parent, vector<vector<int>> &deltab)
{
	vector<int> res;
	const int delall = del(edge, now, parent, deltab) - 1;
	rep(i, edge[now].size()) {
		if(edge[now][i] == parent)
			continue;
		For(j, i + 1, edge[now].size()) {
			if(edge[now][j] == parent)
				continue;
			res.push_back(delall - del(edge, edge[now][i], now, deltab) - del(edge, edge[now][j], now, deltab) + check(edge, edge[now][i], now, deltab) + check(edge, edge[now][j], now, deltab));
		}
	}

	if(res.empty())
		return delall;
	return *min_element(res.begin(), res.end());
}

int solve()
{
	int N;

	cin >> N;
	vector<vector<int>> edge(N);
	vector<vector<int>> deltab(N, vector<int>(N, -1));

	rep(i, N - 1) {
		int a, b;
		cin >> a >> b;
		edge[a-1].push_back(b-1);
		edge[b-1].push_back(a-1);
	}

	vector<int> res;
	rep(i, N)
		res.push_back(check(edge, i, -1, deltab));
	return *min_element(res.begin(), res.end());
}

int main()
{
	int T;

	cin >> T;
	rep(i, T)
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
}
