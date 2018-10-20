#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cn[1005];
vector<int> e[1005];
bool v[1005];
int f[1005];

void solve(int ind)
{
	vector<int> cs;
	v[ind] = true;
	for (int i = 0; i < e[ind].size(); ++i)
	{
		if (v[e[ind][i]])
			continue;
		solve(e[ind][i]);
		cn[ind] += cn[e[ind][i]];
		cs.push_back(f[e[ind][i]]);
	}
	if (cs.size() < 2)
		f[ind] = 1;
	else
	{
		sort(cs.rbegin(), cs.rend());
		f[ind] = 1 + cs[0] + cs[1];
	}
}

int main()
{
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> n;
		for (int i = 0; i <= n; ++i)
			e[i].clear();
		for (int i = 1; i < n; ++i)
		{
			int j, k;
			cin >> j >> k;
			e[j].push_back(k);
			e[k].push_back(j);
		}
		
		int best = n - 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= n; ++j)
			{
				cn[j] = 1;
				f[j] = -1;
				v[j] = false;
			}
			solve(i);
			if (n - f[i] < best)
				best = n - f[i];
		}
		
		cout << "Case #" << tt << ": " << best << endl;
	}
}
