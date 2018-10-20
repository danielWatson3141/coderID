#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

#define list List
int n;
vector <int> g[1100];
int f[1100], a1, a2, bl[1100], len, list[1100], c;

void dfs(int a)
{
//	cout << "!" << a << endl;
	bl[a] = ++c;
	for (int i = 0; i < g[a].size(); i++){
//		cout << "ff " << g[a][i] << endl;
		if (!bl[g[a][i]]) 
			dfs(g[a][i]);
		}
	len++;
	list[len] = a;
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			f[i] = 1;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &a1, &a2);
			g[a1].push_back(a2);
			g[a2].push_back(a1);
		}
		int now = 0, ans = 1;
		for (int s = 1; s <= n; s++) {
			now++;
			vector <int> all;
			len = 0;
			c = 0;
			memset(bl, 0, sizeof bl);
			dfs(s);
			for (int i = 1; i <= n; i++) {
				f[i] = 1;
			}
//			cout << len << endl;
			for (int i = 1; i <= n; i++) {
				all.clear();
//				cout << list[i] << endl;
				for (int j = 0; j < g[list[i]].size(); j++) {
					if (bl[list[i]] < bl[g[list[i]][j]])
						all.push_back(f[g[list[i]][j]]);
				}
//					if s == 
				if (all.size() >= 2) {
					sort(all.begin(), all.end());
					f[list[i]] = max(f[list[i]], all[all.size() - 1] + all[all.size() - 2] + 1);
					ans = max(ans, f[list[i]]);
				}
			}
		}
		printf("Case #%d: %d\n", ++ca, n - ans);
	}
}
