#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ifstream inf("A-large.in");
	ofstream outf("output.txt");

	int m[45];
	string o[160], co[160];
	string d[160];
	int T; inf >> T;
	for (int tc = 1; tc <= T; tc++) {
		outf << "Case #" << tc << ": ";
		int N, L; inf >> N >> L;
		for (int i = 0; i < N; i++) {
			inf >> o[i];
			co[i] = o[i];
		}
		for (int i = 0; i < N; i++) inf >> d[i];
		//for (int i = 0; i < L; i++) m[i] = 0;
		sort(d, d + N);
		int ans = 1000000000;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < L; j++) {
				if (co[0][j] != d[i][j]) m[j] = 1;
				else m[j] = 0;
			}
			int cnt = 0;
			for (int j = 0; j < L; j++) {
				if (m[j] == 0) continue;
				++cnt;
				for (int k = 0; k < N; k++) {
					if (o[k][j] == '0') o[k][j] = '1';
					else o[k][j] = '0';
				}
			}
			sort(o, o + N);
			bool eq = true;
			for (int j = 0; j < N; j++) {
				if (o[j] != d[j]) {
					eq = false;
					break;
				}
			}
			if (eq) ans = min(ans, cnt);
			for (int j = 0; j < L; j++) {
				for (int k = 0; k < N; k++) {
					if (m[j] == 0) continue;
					if (o[k][j] == '0') o[k][j] = '1';
					else o[k][j] = '0';
				}
			}
		}
		/*while (true) {
			int cnt = 0;
			for (int i = 0; i < L; i++) {
				if (m[i] == 0) continue;
				++cnt;
				for (int j = 0; j < N; j++) {								
					if (o[j][i] == '0') o[j][i] = '1';
					else o[j][i] = '0';
				}
			}
			sort(o, o + N);
			bool eq = true;
			for (int i = 0; i < N; i++) {
				if (o[i] != d[i]) {
					eq = false;
					break;
				}
			}
			if (eq) ans = min(ans, cnt);
			for (int i = 0; i < L; i++) {
				for (int j = 0; j < N; j++) {
					if (m[i] == 0) continue;
					if (o[j][i] == '0') o[j][i] = '1';
					else o[j][i] = '0';
				}
			}
			bool fl = false;
			for (int i = 0; i < L; i++) {
				if (m[i] == 0) {
					m[i] = 1;
					fl = true;
					break;
				}
				m[i] = 0;
			}
			if (!fl) break;
		}*/
		if (ans == 1000000000) outf << "NOT POSSIBLE\n";
		else outf << ans << "\n";
	}
}