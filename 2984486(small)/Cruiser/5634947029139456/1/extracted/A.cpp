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

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	forn(tt, t) {
		int n, l;
		cin >> n >> l;
		string s[162], t[162];
		forn(i, n)
			cin >> s[i];
		forn(i, n)
			cin >> t[i];
		int res = 1000;
		sort(t, t + n);
		forn(j, n) {
			string m = s[0];
			int bits = 0;
			forn(i, l) {
				m[i] = (m[i] == t[j][i]) ? '0' : '1';
				bits += (m[i] == '1');
			}
			bool ok = 1;
			forn(i, n) {
				if (i) {
					string x = s[i];
					forn(k, l)
						x[k] = m[k] == x[k] ? '0' : '1';
					if (!binary_search(t, t + n, x)) {
						ok = 0;
						break;
					}
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