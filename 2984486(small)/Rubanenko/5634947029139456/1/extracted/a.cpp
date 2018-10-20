#pragma comment(linker, "/STACK:64000000")
#include <algorithm>
#include <memory.h>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;
#define prev privet1
#define next privet2
#define y1 privet3
#define rank privet4
#define left privet5
#define right privet6
#define y0 privet7

const double pi = 3.141592653589793238;

void ensureLimit(long long n, long long l, long long r)
{
	assert(l <= n && n <= r);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	string outlet[222], device[222];
	for (int tcc = 1; tcc <= tc; tcc++) {
		printf("Case #%d: ", tcc);
		int n, len;
		cin >> n >> len;
		for (int i = 1; i <= n; i++) {
			cin >> outlet[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> device[i];
		}
		bool ok = true;
		int ans = len + 1;
		string a[222], b[222];
		string s;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				s = "";
				int res = 0;
				for (int u = 0; u < len; u++)
					if (outlet[i][u] == device[j][u]) s += '0';
					else s += '1', res++;
				if (res >= ans) continue;
				for (int u = 1; u <= n; u++) {
					a[u] = device[u];
					b[u] = outlet[u];
					for (int k = 0; k < len; k++) 
						if (s[k] == '1') b[u][k] = b[u][k] ^ 1;
				}
				sort(a + 1, a + n + 1);
				sort(b + 1, b + n + 1);
				ok = true;
				for (int u = 1; u <= n; u++) {
					if (a[u] != b[u]) {
						ok = false;
						break;
					}
				}
				if (ok) ans = res;
			}
		}
		if (ans == len + 1) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
}
