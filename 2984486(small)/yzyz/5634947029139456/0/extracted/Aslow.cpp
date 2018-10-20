#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#define MAXL 11

using namespace std;

ofstream fout ("Asmall.out");
ifstream fin ("Asmall.in");

int T;
int n,l;
string a[MAXL],b[MAXL],aa[MAXL];

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fin >> n >> l;
		for (int i = 0; i < n; i++) {
			fin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			fin >> b[i];
		}
		sort(b,b+n);
		int ans = MAXL;
		for (int i = 0; i < (1<<l); i++) {
			if (__builtin_popcount(i) >= ans) continue;
			for (int j = 0; j < n; j++) {
				aa[j] = a[j];
				for (int k = 0; k < l; k++) {
					if ((i>>k)&1) aa[j][k] = (aa[j][k] == '0' ? '1' : '0');
				}
			}
			sort(aa,aa+n);
			bool works = true;
			for (int j = 0; j < n && works; j++) {
				if (aa[j] != b[j]) works = false;
			}
			if (works) ans = __builtin_popcount(i);
		}
		fout << "Case #" << tc << ": ";
		if (ans < MAXL) fout << ans << '\n';
		else fout << "NOT POSSIBLE\n";
	}
    return 0;
}