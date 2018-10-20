//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

vector <string> grid, need, tgrid;
int n, l;

bool ok() {
	set <string> s1, s2;
	for(int i = 0; i < n; i++) s1.insert(grid[i]), s2.insert(need[i]);
	return s1 == s2;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int t, cas = 1; cin >> t;
	while(t--) {
		cout << "Case #" << cas++ << ": ";
		cin >> n >> l;
		grid.resize(n); need.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> grid[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> need[i];
		}
		tgrid = grid;
		int flips = 1 << 30;
		for(int i = 0; i < 1; i++) {
			for(int j = 0; j < n; j++) {
				int count = 0;
				for(int k = 0; k < l; k++)
					if(grid[i][k] != need[j][k]) {
						for(int m = 0; m < n; m++)
							grid[m][k] = '1' + '0' - grid[m][k];
						++count;
					}
				if(ok()) flips = min(flips, count);
				grid = tgrid;
			}
		}
		if(flips == (1 << 30)) cout << "NOT POSSIBLE" << '\n';
		else cout << flips << '\n';
	}
	return 0;
}