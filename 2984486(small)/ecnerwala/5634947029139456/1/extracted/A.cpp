#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vi;

int dsum(int v) {
	return v ? (dsum(v & (v - 1)) + 1) : 0;
}

bool works(int n, vi outlets, vi devices, int v) {
	for(int i = 0; i < outlets.size(); i++) {
		outlets[i] ^= v;
	}
	sort(outlets.begin(), outlets.end());
	return outlets == devices;
}

int toInt(string s) {
	int res = 0;
	for(int i = 0; i < s.size(); i++) {
		res *= 2;
		res += s[i] - '0';
	}
	return res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int n, l; cin >> n >> l;
		vi outlets;
		vi devices;
		for(int i = 0; i < n; i++) {
			string s; cin >> s;
			outlets.push_back(toInt(s));
		}
		for(int i = 0; i < n; i++) {
			string s; cin >> s;
			devices.push_back(toInt(s));
		}
		sort(devices.begin(), devices.end());
		int res = l + 1;
		for(int i = 0; i < n; i++) {
			int v = outlets[0] ^ devices[i];
			int d = dsum(v);
			if(d >= res) continue;
			if(works(n, outlets, devices, v)) res = d;
		}
		cout << "Case #" << t << ": ";
		if(res == l + 1) cout << "NOT POSSIBLE";
		else cout << res;
		cout << '\n';
	}
	return 0;
}
