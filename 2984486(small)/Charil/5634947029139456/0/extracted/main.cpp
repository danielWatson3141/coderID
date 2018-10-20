#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ifstream inf("A-small-attempt0.in");
	ofstream outf("output.txt");

	int m[45];
	string o[160];
	string d[160];
	int T; inf >> T;
	for (int tc = 1; tc <= T; tc++) {
		outf << "Case #" << tc << ": ";
		int N, L; inf >> N >> L;
		for (int i = 0; i < N; i++) inf >> o[i];
		for (int i = 0; i < N; i++) inf >> d[i];
		for (int i = 0; i < L; i++) m[i] = 0;
		sort(d, d + N);
		int ans = 1000000000;
		while (true) {
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
		}
		if (ans == 1000000000) outf << "NOT POSSIBLE\n";
		else outf << ans << "\n";
	}
}