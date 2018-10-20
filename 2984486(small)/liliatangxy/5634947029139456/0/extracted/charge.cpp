#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#define MAX_N 150

using namespace std;

int t, n, l;

int main() {
	//ifstream fin ("charge.in");
	ifstream fin ("A-small-attempt0.in");
	ofstream fout ("charge.out");
	fin >> t;
	for (int i = 1; i <= t; i++) {
		fin >> n >> l;
		string ch[n];
		string fh[n];
		string f[n];
		for (int j = 0; j < n; j++) {
			fin >> ch[j];
		}
		for (int j = 0; j < n; j++) {
			fin >> fh[j];
		}

		sort(fh, fh+n);
		int ans = MAX_N + 1;
		do {
			int temp = 0;
			int same = 0;
			for (int j = 0; j < l; j++) {
				bool all_same = true;
				bool all_dif = true;
				for (int k = 0; k < n; k++) {
					//cout << k << " " << j << " ";
					//cout << ch[k] << " " << fh[k] << endl;
					if (ch[k][j] == fh[k][j]) {
						//cout << "same" << endl;
						all_dif = false;
					}
					else {
						//cout << "dif" << endl;
						all_same = false;
					}
				}
				if (all_dif) {
					temp++;
					//cout << "all dif" << endl;
				}
				if (all_same) {
					same++;
					//cout  << "all same" << endl;
				}
			}
			if (ans > temp && same == (l - temp)) {
				ans = temp;
			}
		} while (next_permutation(fh, fh+n));
		if (ans == MAX_N + 1)
			fout << "Case #" << i << ": " << "NOT POSSIBLE" << endl;
		else
			fout << "Case #" << i << ": " << ans << endl;
	}
}
