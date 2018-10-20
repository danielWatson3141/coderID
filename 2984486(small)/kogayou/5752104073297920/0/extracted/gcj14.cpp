#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
int casenum,T;
int a[1100];
bool v[1100];
int n;

void dfs(int cur) {
	v[cur] = true;
	if (!v[a[cur]])
		dfs(a[cur]);
}

int main() {
	freopen("gcj14.in","r",stdin);
	freopen("gcj14.out","w",stdout);
	cin >> T;
	for (casenum = 1; casenum <= T; casenum++) {
		cout << "Case #" << casenum << ": ";
		memset(v, 0, sizeof(v));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!v[i]) {
				dfs(i);
				cnt ++;
			}
		}
		if (cnt % 2 == 0) cout << "BAD";
		else cout << "GOOD";
		cout << endl;
	}
	return 0;
}
