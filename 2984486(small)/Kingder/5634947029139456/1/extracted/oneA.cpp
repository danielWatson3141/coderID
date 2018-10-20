#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

typedef long long LL;

using namespace std;

const int MAXN = 150 + 10;
LL outlets[MAXN], devices[MAXN], outletsf[MAXN];

int countbit(LL x) {
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
			for (int k = 0; k < word.size(); k++) if (word[k] == '1') outlets[i] |= 1LL << k;
		}	
		for (int i = 0; i < N; i ++) {
			string word;
			cin >> word;
			for (int k = 0; k < word.size(); k++) if (word[k] == '1') devices[i] |= 1LL << k;
		}
		
		vector<LL> VI;
		for (int i = 0; i < N; i ++)
			for (int j = 0; j < N; j ++)
				VI.push_back(outlets[i] ^ devices[j]);
		sort(VI.begin(), VI.end());
		VI.erase(unique(VI.begin(), VI.end()),VI.end());
		
		int ret = INT_MAX;
		sort(devices, devices + N);
		for (int i = 0; i < VI.size(); i ++) {
			bool f = true;
			for (int k = 0; k < N; k ++) outletsf[k] = (outlets[k] ^ VI[i]);
			sort(outletsf, outletsf + N);
			for (int k = 0; k < N; k ++)
				if (devices[k] != outletsf[k]) {
					f = false;
					break;
				}
			if (f) {
				ret = min(ret, countbit(VI[i]));
			}
		}
		if (ret == INT_MAX) cout << "NOT POSSIBLE" << endl;
		else cout << ret << endl;

	}
}
