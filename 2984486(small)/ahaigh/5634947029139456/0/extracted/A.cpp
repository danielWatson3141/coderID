#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <cassert>
#include <cstring>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
#define REPR(i,a,b) for (int i = a; i <= b; i++)

const int N = 200, L = 200;
char in[N][L], out[N][L];
bool branch[L];
int n, l;

int bt(int i, int x) {
	if (i == l) {
		bool fail = false;
			//try and solve
			REP(i,n) {
				bool ok = false;
				REP(j,n) if (!ok && !strcmp(in[i], out[j])) {
					out[j][0] = 'x'; // use this one
					ok = true;
				}
				if (!ok) fail = true;
			}
		if (!fail) return x;
		return 1<<27;
	} else {
		if (branch[i]) {
			int ans = 1<<27;
			ans = min(ans, bt(i+1, x));
			REP(j,n) out[j][i] = out[j][i] == '1' ? '0' : '1';
			ans = min(ans, bt(i+1, x+1));
			REP(j,n) out[j][i] = out[j][i] == '1' ? '0' : '1';
			return ans;
		} else {
			return bt(i+1, x);
		}
	}
}

int main() {
	int t;
	cin >> t;
	REP(qqq,t) {

		cin >> n >> l;
		REP(i,n) {
			cin >> out[i];
		}
		REP(i,n) {
			cin >> in[i];
		}

		int count = 0;
		bool fail = false;
		REP(i,l) {
			int ans = 0;
			REP(j,n) ans += in[j][i] == '1';

			int have = 0;
			REP(j,n) have += out[j][i] == '1';

			branch[i] = false;
			if (ans == have && (n%2==0 && ans == n/2)) {
//				cout << "branch" << endl;
				branch[i] = true;
			} else if (ans == have) {
				//ok
//				cout << "yes" << endl;
			} else if (ans == n - have) {
//				cout << "flip" << endl;
				//flip
				count++;
				REP(j,n) out[j][i] = out[j][i] == '1' ? '0' : '1';
			} else {
//				cout << "no" << endl;
				fail = true;
			}
		}

		cout << "Case #" << (qqq+1) << ": ";
		if (!fail) {
			int z = bt(0, 0);
			if (z < 1<<27)
				count = count + z;
			else
				fail = true;
/*
*/
		}
		if (fail) {
			cout << "NOT POSSIBLE";
		} else {
			cout << count;
		}
		cout << endl;
	}
}
