#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
bool used[41];
vector <string> a, b;
int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("outb.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		a.clear();
		b.clear();
		int N, L;
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			string aa;
			cin >> aa;
			a.push_back(aa);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < N; i++) {
			string aa;
			cin >> aa;
			b.push_back(aa);
		}

		int ret = 100;
		for (int i = 0; i < (1<<L); i++) {
			memset(used, 0, sizeof used);

			for (int j = 0; j < L; j++) if (i&(1<<j)) used[j] = true;
			
			for (int j = 0; j < L; j++) {
				if (used[j]) {
					for (int i1 = 0; i1 < N; i1++) {
						if (b[i1][j] == '1') b[i1][j] = '0';
						else b[i1][j] = '1';
					}
				}
			}
			bool same = true;
			sort(b.begin(), b.end());
			for (int i1 = 0; i1 < N; i1++)
				for (int j1 = 0; j1 < L; j1++)
					if (a[i1][j1] != b[i1][j1]) {
						same = false;
						break;
					}
			if (same) ret = min(ret, __builtin_popcount(i));

			for (int j = 0; j < L; j++) {
				if (used[j]) {
					for (int i1 = 0; i1 < N; i1++) {
						if (b[i1][j] == '1') b[i1][j] = '0';
						else b[i1][j] = '1';
					}
				}
			}

		}
		if (ret == 100)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}