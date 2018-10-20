#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > T;


pair<int, int> dfs(int v, int pv) {
	//cout << v << " " << pv << endl;
	vector<pair<int, int> > results;
	for (int j=0; j<T[v].size(); ++j) {
		if (T[v][j] == pv) {
			//cout << pv << endl;
			continue;
		}
		else {
			//cout << "HERE" << endl;
			results.push_back(dfs(T[v][j], v));
		}
	}
	if (results.empty())
		return pair<int, int>(0, 1);
	else if (results.size() == 1) {
		//cout << "HERE2" << endl;
		return pair<int, int>(results[0].second, results[0].second + 1);
	}
	else {
		vector<int> costs;
		int total = 0;
		for (size_t i=0; i<results.size(); ++i) {
			total += results[i].second;
			costs.push_back(results[i].first - results[i].second);
		}
		sort(costs.begin(), costs.end());
		return pair<int, int>(total + costs[0] + costs[1], total + 1);
	}
}

int main() {
	
	int tnum;
	cin >> tnum;
	for (int ts=1; ts<=tnum; ++ts) {
		int N;
		cin >> N;
		T.assign(N, vector<int>());
		for (int i=1; i<N; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			T[a].push_back(b);
			T[b].push_back(a);
		}
		int ans = N;
		for (int i=0; i<N; ++i) {
			pair<int, int> res = dfs(i, -1);
			if (res.first < ans) {
				ans = res.first;
			}
		}
		cout << "Case #" << ts << ": " << ans << endl; 
	}


	return 0;
}
