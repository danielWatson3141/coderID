#pragma comment(linker, "/STACK:128777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>
#include <windows.h>

typedef long long i64;
typedef unsigned int u32;
const int null = 0;

using namespace std;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T abs(const T &a) {
	return (a < 0? -a: a);
}
template<class T> T sqr(const T &a) {
	return a * a;
}

#define all(a) a.begin(),a.end()

i64 a[300], b[300];
char s[50];
bool was[300];
void scan(i64* a, int n) {
	for (int i = 0; i < n; i++) {
		i64 t = 0;
		scanf("%s", s);
		for (int j = 0; s[j]; j++) {
			if (s[j] == '1') {
				t |= (1LL << j);
			}
		}
		a[i] = t;
	}
}
int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		int n, m;
		cin >> n >> m;
		scan(a, n);
		scan(b, n);
		int res = 128;
		for (int i = 0; i < n; i++) {
			i64 mask = a[0] ^ b[i];
			memset(was, 0, sizeof(was));
			bool good = true;
			for (int i = 0; i < n; i++) {
				bool g = false;
				i64 t = a[i] ^ mask;
				for (int j = 0; j < n; j++) {
					if (!was[j] && t == b[j]) {
						was[j] = true;
						g = true;
						break;
					}
				}
				if (!g) {
					good = false;
					break;
				}
			}
			if (good) {
				int sw = 0;
				for (int j = 0; j < m; j++) {
					if (mask & (1LL << j)) {
						sw++;
					}
				}
				res = min(res, sw);
			}
		}
		printf("Case #%d: ", iTest);
		if (res == 128) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << res << endl;
		}
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}