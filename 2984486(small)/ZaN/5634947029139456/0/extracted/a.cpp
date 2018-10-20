#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n, l;
		cin >> n >> l;
		vector<string> d(n), o(n);
		for (int i = 0; i < n; ++i) {
			cin >> o[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}

		int fbest = l + 1;
		vector<char> s(l);
		for (int i = 0; i < n; ++i) {
			int nf = 0;
			vector<char> f(l);
			for (int j = 0; j < l; ++j) {
				f[j] = (d[0][j] != o[i][j]);
				if (f[j]) {
					++nf;
				}
			}
			bool match = true;
			for (int k = 1; k < n && match; ++k) {
				match = false;
				for (int m = 0; m < n && !match; ++m) {
					match = true;
					for (int j = 0; j < l && match; ++j) {
						if (f[j] != (d[k][j] != o[m][j])) {
							match = false;
						}
					}
				}
			}
			if (match && nf < fbest) {
				fbest = nf;
			}
		}
		cout << "Case #" << test << ": ";
		if (fbest > l) {
			cout << "NOT POSSIBLE";
		} else {
			cout << fbest;
		}
		cout << endl;
	}
}
