#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int n;
vector<vector<int>> v;


int Go(int i, int par)
{
	int ncnt = v[i].size();
	if (par != -1) ncnt--;
	if (ncnt < 2) return 1;

	vector<int> nei;
	for (int j = 0; j < v[i].size(); ++j)
		if (v[i][j] != par) 
		{
			nei.push_back(Go(v[i][j], i));
		}
	sort(nei.begin(), nei.end());
	reverse(nei.begin(), nei.end());
	return 1+nei[0] + nei[1];
}

int main()
{
	ifstream ifs("b.in");
	ofstream ofs("b.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		ifs >> n;
		v.assign(n, vector<int>());
		for (int i =0; i < n-1; ++i)
		{
			int x, y;
			ifs >> x >> y;
			--x; --y;
			v[x].push_back(y);
			v[y].push_back(x);
		}

		int maxn = 0;
		for (int i = 0; i < n; ++i)
			maxn = max(maxn, Go(i, -1));
		ofs << "Case #" << test+1 << ": " << n-maxn << endl;
	}
	return 0;
}
