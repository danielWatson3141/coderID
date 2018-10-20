#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define BIG 1000000000
#define LL long long
#define MAXN 1010
using namespace std;

int ntest, n;
int size[MAXN], f[MAXN];
vector<int> e[MAXN];

void checkmin(int &a, int b) {
	if (b < a) a = b;
}

int go(int u, int parent) {
	size[u] = 1;
	vector<int> child;
	for (int k = 0; k < e[u].size(); k++) {
		int v = e[u][k];
		if (v == parent) continue;
		child.push_back(v);
		go(v, u);
		size[u] += size[v];
	}
	int numChild = child.size();
	if (numChild == 0) {
		f[u] = 0;
		return 0;
	}
	if (numChild == 1) {
		f[u] = size[u] - 1;
		return size[u] - 1;
	}

	int g[numChild][3];
	
	for (int i = 0; i < numChild; i++)
		for (int j = 0; j < 3; j++) g[i][j] = BIG;

	g[0][0] = size[child[0]];
	g[0][1] = f[child[0]];
	//cout << u << '-' << g[0][1] << endl;
	for (int i = 0; i < numChild - 1; i++)
		for (int j = 0; j < 3; j++) 
			if (g[i][j] != BIG) {
				checkmin(g[i + 1][j], g[i][j] + size[child[i + 1]]);
				if (j + 1 <= 2)
					checkmin(g[i + 1][j + 1], g[i][j] + f[child[i + 1]]);
			}
	f[u] = g[numChild - 1][2];
	return f[u];
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> ntest;
	for (int test = 1; test <= ntest; test++) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans = BIG;
		for (int i = 1; i <= n; i++) {
			memset(size, 0, sizeof(size));
			memset(f, 0, sizeof(f));
			ans = min(ans, go(i, -1));
			//for (int j = 1; j <= n; j++) cout << j << ' ' << f[j] << endl;
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
}

