#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> test(const vector<vector<int>> &edge, vector<bool> &use, int root)
{
	pair<int, int> ans = make_pair<int, int>(1, 0);
	vector<pair<int, int>> tmp;
	use[root] = true;
	for (int t:edge.at(root))
	{
		if (use[t])
			continue;
		tmp.push_back(test(edge, use, t));
		ans.first += tmp.back().first;
	}
	sort(tmp.begin(), tmp.end(), [](pair<int, int> a, pair<int, int>b)
	{
		return (a.first-a.second)>(b.first-b.second);
	});
	if (tmp.size()==0)
		;
	else if (tmp.size()==1)
		ans.second += tmp[0].first;
	else
	{
		ans.second += tmp[0].second+tmp[1].second;
		for (int i=2;i<tmp.size();i++)
			ans.second += tmp[i].first;
	}
	return ans;
}

int ans(const vector<vector<int>> &edge)
{
	int ans = edge.size();
	vector<bool> use;
	for (int i=0;i<edge.size();i++)
	{
		use.clear();
		use.resize(edge.size());
		ans = min(ans, test(edge, use, i).second);
	}
	return ans;
}

int main()
{
	int t, n;
	int tmp1, tmp2;
	vector<vector<int>> edge;
	cin >> t;
	for (int i=1;i<=t;i++)
	{
		cin >> n;
		edge.clear();
		edge.resize(n);
		for (int j=1;j<n;j++)
		{
			cin >> tmp1 >> tmp2;
			tmp1--;
			tmp2--;
			edge[tmp1].push_back(tmp2);
			edge[tmp2].push_back(tmp1);
		}
		cout << "Case #" << i << ": " << ans(edge) << endl;
	}
	return 0;
}
