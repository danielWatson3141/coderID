#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

uint32_t to_mask(string &s)
{
	uint32_t m = 0;
	for (auto &i : s) {
		m <<= 1;
		m |= (i == '1');
	}
	return m;
}

string to_string(uint32_t m, size_t len)
{
	string res;
	while (m) {
		res += (m & 1) ? '1' : '0';
		m >>= 1;
	}
	while (res.size() < len)
		res += '0';
	
	reverse(res.begin(), res.end());

	return res;
}

int bits(uint32_t m)
{
	int cnt = 0;
	while (m) {
		cnt += (m & 1);
		m >>= 1;
	}
	return cnt;
}

int main()
{
	int test_total;
	cin >> test_total;

	for (int test = 0; test < test_total; ++test) {
		int N, L;
		string s;
		cin >> N >> L;
		vector<uint32_t> outlets, devices;
		for (int i = 0; i < N; ++i) {
			cin >> s;
			outlets.push_back(to_mask(s));
		}
		for (int i = 0; i < N; ++i) {
			cin >> s;
			devices.push_back(to_mask(s));
		}
		sort(devices.begin(), devices.end());
		int ans = L + 1;
		for (uint32_t m = 0; m < (1u << L); ++m) {
			int local = bits(m);
			if (local >= ans)
				continue;
			auto out = outlets;
			for (auto &i : out)
				i ^= m;
			sort(out.begin(), out.end());
			if (devices == out)
				ans = local;
		}
		cout << "Case #" << test + 1 << ": ";
		if (ans == L + 1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}

	return 0;
}