// Ilya Shakirov

#pragma comment(linker, "/STACK:836777216")

#define INF (long long)1e18
#define EPS 1e-15
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <memory.h>

using namespace std;

const int MAX_N = 150;
const int MAX_L = 40;

int tests;
int n, l;
long long outlets[MAX_N], devices[MAX_N], outlets_new[MAX_N];
string tmp_s;

long long convert_to_ll(string s) {
	long long res = 0;
	for (int i = 0; i < s.length(); i++) {
		res = (res << 1ll) | (s[i] - '0');
	}
	return res;
}

void change_bits(long long in) {
	for (int i = 0; i < n; i++) {
		outlets_new[i] = outlets[i] ^ in;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			cin >> tmp_s;
			outlets[i] = convert_to_ll(tmp_s);
		}
		for (int i = 0; i < n; i++) {
			cin >> tmp_s;
			devices[i] = convert_to_ll(tmp_s);
		}
		int mask = -1;
		for (int i = 0; i < 1024; i++) {
			change_bits(i);
			sort(outlets_new, outlets_new + n);
			int flag = 1;
			for (int j = 0; j < n; j++) {
				if (!binary_search(outlets_new, outlets_new + n, devices[j])) {
					flag = 0;
				}
			}
			if (flag) {
				mask = i;
				break;
			}
		}
		if (mask >= 0) {
			int ans = 0;
			for (int j = 0; j < l; j++) {
				if (((mask >> j) & 1) == 1) {
					ans++;
				}
			}
			cout << "Case #" << test << ": " << ans << '\n';
		} else {
			cout << "Case #" << test << ": " << "NOT POSSIBLE" << '\n';
		}
	}
	return 0;
}