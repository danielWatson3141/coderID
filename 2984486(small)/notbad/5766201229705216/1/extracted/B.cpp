#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VII;

int go(int v1, int v2, VII &dp, VII const &g) {
	if (dp[v1][v2] == -1) {
		dp[v1][v2] = 1;
		int m1 = -1, m2 = -1;
		for (int i = 0; i < g[v2].size(); ++i) {
			int v3 = g[v2][i];
			if (v1 != v3) {
				if (dp[v2][v3] == -1) go(v2, v3, dp, g);
				int m3 = dp[v2][v3];
				if (m3 > m2) {
					m1 = m2;
					m2 = m3;
				} else if (m3 > m1) {
					m1 = m3;
				}
			}
		}
		if (m1 >= 0 && m2 >= 0) dp[v1][v2] += m1+m2;
	}
}

int main (){
	int T;
	freopen("B-large.in", "r", stdin);
	freopen("B-large.txt", "w", stdout);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		VII g(N+1);
		VII dp(N+1, vector<int>(N+1, -1));
		for (int i = 0; i < N-1; i++) {
			int v1, v2;
			cin >> v1 >> v2;
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		for (int v = 1; v <= N; ++v) {
			for (int i = 0; i < g[v].size(); ++i) {
				go(v, g[v][i], dp, g);
				//cout << v << " " << g[v][i] << ": " << dp[v][g[v][i]] << endl; 
			}
		}
		int mmin = 0;
		for (int v = 1; v <= N; ++v) {
			int temp = 1;
			int m1 = -1, m2 = -1;
			for (int i = 0; i < g[v].size(); ++i) {
				if (dp[v][g[v][i]] > m2) {
					m1 = m2;
					m2 = dp[v][g[v][i]];
				} else if (dp[v][g[v][i]] > m1) {
					m1 = dp[v][g[v][i]];
				}
			}

			if (m1 > 0 && m2 > 0) temp += m1+m2;
			//cout << v << ":" << temp << endl;
			if (temp > mmin) mmin = temp;
		}
		
		cout << "Case #" << t << ": " << N-mmin << endl;	
	}
}
