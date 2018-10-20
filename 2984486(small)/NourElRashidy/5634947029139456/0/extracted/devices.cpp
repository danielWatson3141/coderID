#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <sstream>

#define oo 1e9
using namespace std;

int res = oo;
int n, l;

void solve(int tmp, int tmpr, vector<string>flow, vector<string>dev) {
	sort(flow.begin(), flow.end());
	sort(dev.begin(), dev.end());
	if(flow == dev) {
		res = min(res, tmpr);
		return;
	}
	if(tmp == l) return;
	solve(tmp + 1, tmpr, flow, dev);
	for(int i = 0; i < flow.size(); i++) flow[i][tmp] == '1' ? flow[i][tmp] = '0' : flow[i][tmp] = '1';
	solve(tmp + 1, tmpr + 1, flow, dev);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> l;
		res = oo;
		vector<string>flow(n), dev(n);
		for(int i = 0; i < n; cin >> flow[i++]);
		for(int i = 0; i < n; cin >> dev[i++]);
		solve(0, 0, flow, dev);
		cout << "Case #" << tc << ": ";
		res == oo ? cout << "NOT POSSIBLE" << endl : cout << res << endl;
	}
	return 0;
}
