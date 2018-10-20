#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long toLL(string str) {
	long long ret = 0;
	for (int i = 0 ; i < str.length(); i++) {
		ret = ret * 2 + str[i] - '0';
	}
	return ret;
}

int popc(long long x) {
	int ret = 0;
	while (x) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

int main() {
	int T; cin >> T;
	for (int No = 1; No <= T; No++) {
		int N, L; cin >> N >> L;
		vector<long long> ini(N), req(N);
		for (int i = 0; i < N; i++) {
			string str; cin >> str;
			ini[i] = toLL(str);
		}
		for (int i = 0; i < N; i++) {
			string str; cin >> str;
			req[i] = toLL(str);
		}

		sort(req.begin(), req.end());

		int ans = L * 2;
		for (int i = 0; i < N; i++) {
			long long diff = ini[0] ^ req[i];
			vector<long long> prod(N);
			for (int j = 0; j < N; j++) {
				prod[j] = ini[j] ^ diff;
			}
			sort(prod.begin(), prod.end());
			if (req == prod) {
				ans = min(ans, popc(diff));
			}
		}

		cout << "Case #" << No << ": ";
		if (ans == L * 2) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
