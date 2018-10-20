#include <iostream>
#include <vector>
using namespace std;

vector<int> G[1010];
int N;

int dfs(int p, int v) {
	int count = 0;
	int m1=0, m2=0;

	for(int i=0; i<G[v].size(); i++) {
		int w = G[v][i];
		if (w!=p) {
			int value = dfs(v, w);
			if (value > m2) {
				if (value > m1) {
					m2 = m1;
					m1 = value;
				} else {
					m2 = value;
				}
			}
			count++;
		}
	}

	if (count == 2)
		return m1+m2+1;
	else if (count == 1 || count == 0)
		return 1;
	else
		return m1+m2+1;
}

int main() {
	int tests; cin >> tests;
	for(int test=1; test<=tests; test++) {
		cin >> N;
		for(int i=1; i<=N; i++)
			G[i].clear();

		for(int i=1; i<=N-1; i++) {
			int a, b; cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}

		int minn = 0x1f1f1f1f;
		for(int i=1; i<=N; i++) {
			int temp = dfs(-1, i);
			//cout << " " << i << " " << temp << endl;
			minn = min(minn, N-temp);
		}

		cout << "Case #" << test << ": " << minn << endl;
	}
}