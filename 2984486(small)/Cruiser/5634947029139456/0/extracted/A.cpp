#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

int a[300001], d[300001], mx[300101];

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	forn(tt, t) {
		int n, l;
		cin >> n >> l;
		string s[12], t[12];
		forn(i, n)
			cin >> s[i];
		forn(i, n)
			cin >> t[i];
		int res = 1000;
		sort(t, t + n);
		forn(m, (1 << l)) {
			string ss[12];
			int bits = 0;
			forn(i, n) {
				ss[i] = s[i];
				forn(j, l) {
					if (m & (1 << j)) {
						bits += i ? 0 : 1;
						ss[i][j] = (s[i][j] == '0') ? '1' : '0';
					}
				}
			}
			sort(ss, ss + n);
			bool ok = 1;
			forn(i, n) {
				if (ss[i] != t[i]){
					ok = 0;
					break;
				}
			}
			if (ok) {
				res = min(res, bits);
			}
		}
		cout << "Case #" << (tt+1) << ": ";
		if (res == 1000)
			puts("NOT POSSIBLE");
		else
			cout << res << endl;
	}

}