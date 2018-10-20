#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

typedef vector<int> VI;



const int MAXN = 1000 + 10;
int N;
VI edges[MAXN];

int gao(int root, int p) {
	int maxf = 0, maxs = 0;
	for (int i = 0; i < edges[root].size(); i ++) {
		if (edges[root][i] != p) {
			int tmp = gao(edges[root][i], root);
			if (tmp >= maxf) {
				maxs = maxf;
				maxf = tmp;
			} else if (tmp > maxs) {
				maxs = tmp;
			}
		}
	}
	if (maxs == 0) return 1;
	return maxs + maxf + 1;
}

int main() {
	int cases; cin >> cases;
	for (int tc = 1; tc <= cases; tc ++ ) {
		cout <<"Case #" << tc <<": ";
		cin >> N;
		for (int i = 1; i <= N; i ++)
			edges[i].clear();
		for (int i = 0; i < N - 1; i ++) {
			int a,b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		int ret = INT_MAX;
		for (int root = 1; root <= N; root ++) {
			ret = min(ret, N - gao(root, 0));
		}	
		cout << ret << endl;

	}
}
