#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

using namespace std;

typedef long long ll;

const int N = 150;

ll s2i(string s) {
	ll a = 0;
	ll k = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1') {
			a += k;
		}
		k *= 2;
	}
	return a;
}

int nb(ll x) {
	int s = 0;
	ll k = 1;
	while (k <= x) {
		k *= 2;
	}
	k /= 2;
	while (k > 0) {
		if (x >= k) {
			s++;
			x -= k;
		}
		k /= 2;
	}
	return s;
}

int main() {
	int ntc;
	cin >> ntc;
	for (int tc = 1; tc <= ntc; tc++) {
		int n, l;
		cin >> n >> l;
		ll a[N], b[N];
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			a[i] = s2i(s);
		}
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			b[i] = s2i(s);
		}
		cout << "Case #" << tc << ": ";
		int s = l + 1;
		for (int i = 0; i < n; i++) {
			ll c[N];
			ll x = a[i] ^ b[0];
			for (int j = 0; j < n; j++) {
				c[j] = a[j] ^ x;
			}
			bool f = true;
			for (int j = 0; j < n; j++) {
				f = false;
				for (int k = 0; k < n; k++) {
					if (b[j] == c[k]) {
						f = true;
						break;
					}
				}
				if (!f) {
					break;
				}
			}
			if (f) {
				int t = nb(x);
				if (t < s) {
					s = t;
				}
			}
		}
		if (s <= l) {
			cout << s;
		} else {
			cout << "NOT POSSIBLE";
		}
		cout << endl;
	}
	return 0;
}

