#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> G;
vector<int> cnt;
int ans, dropped;

void dfs_count(int v, int parent)
{
	cnt[v] = 1;
	for (auto &to : G[v])
		if (to != parent) {
			dfs_count(to, v);
			cnt[v] += cnt[to];
		}
}

void dfs(int v, int parent)
{
	// if (dropped >= ans)
	// 	return;
	vector<pair<int, int>> cand;
	for (auto &to : G[v])
		if (to != parent)
			cand.push_back(make_pair(cnt[to], to));

	// printf("[%d <- %d]: %zu: ", v + 1, parent + 1, cand.size());
	// for (auto &i : cand)
	// 	cout << i.first << "," << i.second + 1 << " ";
	// cout << endl;

	if (cand.empty()) {
		return;
	}

	if (cand.size() == 1) {
		dropped += cnt[cand[0].second];
		return;
	}

	sort(cand.rbegin(), cand.rend());
	for (unsigned i = 2; i < cand.size(); ++i)
		dropped += cnt[cand[i].second];
	dfs(cand[0].second, v);
	dfs(cand[1].second, v);
}

int main()
{
	int test_total;
	cin >> test_total;

	for (int test = 0; test < test_total; ++test) {
		int N;
		cin >> N;
		G.clear();
		G.resize(N);
		ans = N - 1;
		for (int i = 0; i < N - 1; ++i) {
			int from, to;
			cin >> from >> to;
			from--;
			to--;
			G[from].push_back(to);
			G[to].push_back(from);
		}

		for (int i = 0; i < N; ++i) {
			cnt = vector<int>(N, 0);
			dropped = 0;
			dfs_count(i, -1);
			dfs(i, -1);
			// for (int i = 0; i < N; ++i)
			// 	printf("dropped[%d] = %d\n", i + 1, dropped[i]);
			// cout << endl;
			// return 0;
			// cout << endl;
			if (ans > dropped) {
				ans = dropped;
				// cout << "COOL ROOT " << i + 1 << ": " << ans << endl;
			}
		}

		cout << "Case #" << test + 1 << ": " << ans << endl;
	}

	return 0;
}