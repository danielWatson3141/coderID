#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100;
int outlets[MAXN], devices[MAXN], outletsf[MAXN];

int countbit(int x) {
	if (x <= 0) return 0;
	return 1 + countbit(x & (x - 1));
}

int main() {
	int cases; cin >> cases;
	for (int tc = 1; tc <= cases; tc ++ ) {
		cout <<"Case #" << tc <<": ";
		int N, L;
		cin >> N >> L;
		fill(outlets, outlets+N, 0);
		fill(devices, devices+N, 0);
		for (int i = 0; i < N; i ++) {
			string word;
			cin >> word;
			for (int k = 0; k < word.size(); k++) outlets[i] |= ((word[k] - '0') << k);
		}	
		for (int i = 0; i < N; i ++) {
			string word;
			cin >> word;
			for (int k = 0; k < word.size(); k++) devices[i] |= ((word[k] - '0') << k);
		}

		int ret = INT_MAX;
		sort(devices, devices + N);
		int limit = 1 << L;
		for (int i = 0; i < limit; i ++) {
			bool f = true;
			for (int k = 0; k < N; k ++) outletsf[k] = (outlets[k] ^ i);
			sort(outletsf, outletsf + N);
			for (int k = 0; k < N; k ++)
				if (devices[k] != outletsf[k]) {
					f = false;
					break;
				}
			if (f) {
				ret = min(ret, countbit(i));
			}
		}
		if (ret == INT_MAX) cout << "NOT POSSIBLE" << endl;
		else cout << ret << endl;

	}
}
