#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[1002];
int d[1002];
int c[1002];

int child(int s, int n) {
	int r = 1;
	for (int i=0; i<d[n]; i++) {
		if (v[n][i] != s)
			r += child(n, v[n][i]);
	}
	return c[n] = r;
}


int dfs(int s, int n) {
	//cout << " dfs" << s << " " << n << endl;
	if (d[n] == 1 && s != 0) return 0;
	if (d[n] == 1 && s == 0) return c[n]-1;
	if (d[n] == 2 && s != 0) return c[n]-1;
	int r = 0, max1=-1, max2=-1;
	for (int i=0; i<d[n]; i++) {
		if (v[n][i] == s) continue;
		int x = c[v[n][i]] - dfs(n, v[n][i]);
		if (x >= max1) {
			max2 = max1;
			max1 = x;
		}
		else if (x > max2) {
			max2 = x;
		}
	}
	return c[n]-max1-max2-1;
}

int main() {
	int T, n;
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		scanf("%d", &n);
		for (int j=1; j<=n; j++) v[j].clear();
		for (int j=1; j<n; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}	
		int out = n;
		for (int j=1; j<=n; j++) d[j] = v[j].size();
		for (int j=1; j<=n; j++) {
			child(0, j);
			int t = dfs(0, j);
			if (t < out) out = t;
		}
		printf("Case #%d: %d\n", i, out);
	}
	return 0;
}
