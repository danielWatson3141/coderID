#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

const int MAXn = 1010;
const int INF = 1e9;
vector<int> nb[MAXn];
bool mark[MAXn];

int dfs(int v) {
	mark[v] = true;
	vector<int> ret;
	for(int i = 0; i < (int)nb[v].size(); i++)
		if(!mark[nb[v][i]])
			ret.push_back(dfs(nb[v][i]));
	sort(ret.begin(), ret.end());
	if((int)ret.size() < 2)
		return 1;
	else
		return ret[ret.size()-1] + ret[ret.size()-2]+1;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
			nb[i].clear();
		for(int i = 0; i < n-1; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			nb[x].push_back(y);
			nb[y].push_back(x);
		}
		int best = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				mark[j] = false;
			best = max(best, dfs(i));
		}
		cout << "Case #" << t << ": " << n-best << endl;
	}
	return 0;
}
