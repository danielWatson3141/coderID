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

vector <string> grid, need;
int n, l;

bool ok() {
	set <string> s1, s2;
	for(int i = 0; i < n; i++) s1.insert(grid[i]), s2.insert(need[i]);
	return s1 == s2;
}

int dfs(int j) {
	if(j == l) {
		return ok() ? 0 : (1 << 21);
	}
	int moves = 1 << 21;
	//flip
	for(int i = 0; i < n; i++)
		grid[i][j] = '1' + '0' - grid[i][j];
	moves = min(moves, 1 + dfs(j + 1));
	for(int i = 0; i < n; i++)
		grid[i][j] = '1' + '0' - grid[i][j];
	//not flip
	moves = min(moves, dfs(j + 1));
	return moves;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
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
		int res = dfs(0);
		if(res == (1 << 21))
			cout << "NOT POSSIBLE" << '\n';
		else
			cout << res << '\n';
	}
	return 0;
}