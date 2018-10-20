#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

long long base = 1e6 + 7;

int nTest;
int n, l;
string outlet[155], device[155];
long long nDevice[155], nOutlet[155];
bool switcher[44];

int main() {

	freopen("A-large.in", "r", stdin);
	freopen("Output.txt", "w", stdout);

	cin >> nTest;
	for (int test = 1; test <= nTest; test++) {
		cin >> n >> l;
		for (int i = 1; i <= n; i++)
			cin >> outlet[i];

		for (int i = 1; i <= n; i++) {
			cin >> device[i];
			nDevice[i] = 0;
			for (int k = 0; k < l; k++)
				nDevice[i] = nDevice[i] * base + device[i][k];
		}
		sort(nDevice + 1, nDevice + 1 + n);

		int ret = 1e9;
		for (int i = 1; i <= 1; i++) {
			for (int j = 1; j <= n; j++) {
				int tret = 0;
				for (int k = 0; k < l; k++) {
					if (outlet[i][k] != device[j][k]) {
						switcher[k] = 1;
						tret++;
					}
					else switcher[k] = 0;
				}
				for (int ii = 1; ii <= n; ii++) {
					nOutlet[ii] = 0;
					for (int k = 0; k < l; k++) {
						char c = outlet[ii][k] - '0';
						c ^= switcher[k];
						c += '0';
						nOutlet[ii] = nOutlet[ii] * base + c;
					}
				}
				sort(nOutlet + 1, nOutlet + 1 + n);

				for (int ii = 1; ii <= n; ii++) {
					if (nOutlet[ii] != nDevice[ii])
						tret = 1e9;
				}
				ret = min(ret, tret);
			}
		}

		cout << "Case #" << test << ": ";
		if (ret <= l) cout << ret << endl;
		else cout << "NOT POSSIBLE" << endl;
	}

	return 0;
}