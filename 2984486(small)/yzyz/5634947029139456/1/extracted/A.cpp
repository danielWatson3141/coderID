#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#define MAXN 455
#define MAXL 45

using namespace std;

ofstream fout ("Alarge.out");
ifstream fin ("Alarge.in");

int T;
int n,l;
string a[MAXN],b[MAXN],aa[MAXN];

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
		for (int i = 0; i < n; i++) {
			int ct = 0;
			for (int j = 0; j < l; j++)
				if (a[i][j] != b[0][j]) ct++;
			if (ct >= ans) continue;
			for (int j = 0; j < n; j++) {
				aa[j] = a[j];
				for (int k = 0; k < l; k++) {
					if (a[i][k] != b[0][k]) aa[j][k] = (aa[j][k] == '0' ? '1' : '0');
				}
			}
			sort(aa,aa+n);
			bool works = true;
			for (int j = 0; j < n && works; j++) {
				if (aa[j] != b[j]) works = false;
			}
			if (works) ans = ct;
		}
		fout << "Case #" << tc << ": ";
		if (ans < MAXL) fout << ans << '\n';
		else fout << "NOT POSSIBLE\n";
	}
    return 0;
}