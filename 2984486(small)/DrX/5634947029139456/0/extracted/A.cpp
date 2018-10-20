#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int cnt(int x) {
	int ans = 0;
	while(x) {
		ans += x % 2;
		x /= 2;
	}
	return ans;
}

int main() {
	int i, j, k, ca, T;
	int n, L;

	freopen("A-small-attempt1.in", "r", stdin);
	freopen("a1out-attempt1.txt", "w", stdout);
	cin >> T;
	for (ca = 1; ca <= T; ++ca) {
		cin >> n >> L;
		vector<string>src, des;
		string s;
		for (i = 0; i < n; ++i) {
			cin >> s;
			src.push_back(s);
		}
		for (i = 0; i < n; ++i) {
			cin >> s;
			des.push_back(s);
		}
		sort(des.begin(), des.end());

		int ans = 2 *L;
		for (int mask = 0; mask < (1<<L); ++mask) {
			vector<string>tmp(src);
			for (j = 0; j < L; ++j) if (mask & (1<<j)) {
				for (i = 0; i < n; ++i) tmp[i][j] = src[i][j] == '1'? '0' : '1';
			}
			sort(tmp.begin(), tmp.end());
			for (i = 0; i < n; ++i) if (tmp[i] != des[i]) break;
			if (i == n) ans = min(ans, cnt(mask));
		}
		cout << "Case #" << ca << ": ";
		if (ans == 2*L)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}

}
