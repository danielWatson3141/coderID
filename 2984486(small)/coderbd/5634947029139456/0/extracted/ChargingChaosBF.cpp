#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

int t, n, l;
string s;

ll device[200], outlet[200];
int c1[2000], c2[2000];

ll to_int(const string& s) {
	ll ret = 0ll;
	for (int i = 0; i < l; i++) {
		if (s[i] == '1')
			ret |= 1ll << i;
	}
	return ret;
}

int count_bit(ll n) {
	int ret = 0;
	while (n) {
		if (n & 1ll)
			ret++;
		n >>= 1;
	}
	return ret;
}

int main() {
	ll masks;

	ios::sync_with_stdio(0);
	cin >> t;
	for (int case_no = 1; case_no <= t; case_no++) {
		cin >> n >> l;
		masks = (1ll << l) - 1ll;
		for (int i = 0; i < n; i++) {
			cin >> s;
			outlet[i] = to_int(s);
		}
		for (int i = 0; i < n; i++) {
			cin >> s;
			device[i] = to_int(s);
		}

		int ans = 0x7fffffff;
		for (ll bitmask = 0ll; bitmask <= masks; bitmask++) {
			bool ok = true;
			memset(c1, 0, sizeof c1);
			memset(c2, 0, sizeof c2);
			for (int i = 0; i < n; i++)
				c1[outlet[i]^bitmask]++;
			for (int i = 0; i < n; i++)
				c2[device[i]]++;
			for (int i = 0; i <= masks; i++)
				if (c1[i] != c2[i]) {
					ok = false;
					break;
				}
			if (ok)
				ans = min(ans, count_bit(bitmask));
		}

		if (ans == 0x7fffffff)
			cout << "Case #" << case_no << ": NOT POSSIBLE" << endl;
		else
			cout << "Case #" << case_no << ": " << ans << endl;
	}

	return 0;
}