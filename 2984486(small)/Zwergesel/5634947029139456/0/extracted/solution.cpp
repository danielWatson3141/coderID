#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, l;
string a[150], b[150];
int a1[40], b1[40];

void flip(int j) {
	for (int i=0; i<n; i++) {
		a[i][j] = '1' + '0' - a[i][j];
	}
}

bool prefix(int k) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<=k; j++) {
			if (a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}

int rsolve(int j) {
	if (j == l) return prefix(j-1) ? 0 : -1;
	//cout << a1[j] << " " << b1[j] << "\n";
	if (a1[j] == b1[j]) {
		//cout << "Bit " << j << " is good\n";
		sort(a, a+n);
		sort(b, b+n);
		bool flipable = n % 2 == 0 && a1[j] == n / 2;
		if (flipable) {
			//cout << "Flipable, try both\n";
			int s1 = prefix(j) ? rsolve(j+1) : -1;
			flip(j);
			sort(a, a+n);
			sort(b, b+n);
			int s2 = prefix(j) ? rsolve(j+1) : -1;
			if (s2 >= 0) s2++;
			flip(j);
			if (s1 < 0) return s2;
			if (s2 < 0) return s1;
			return min(s1, s2);
		} else if (prefix(j)) {
			//cout << "Prefix is good\n";
			return rsolve(j+1);
		} else {
			//cout << "Prefix is wrong and not flipable\n";
			return -1;
		}
	} else if (n - a1[j] == b1[j]) {
		//cout << "Bit " << j << " is force-flip\n";
		flip(j);
		sort(a, a+n);
		sort(b, b+n);
		if (!prefix(j)) {
			flip(j);
			return -1;
		} else {
			int s = rsolve(j+1);
			if (s >= 0) s++;
			flip(j);
			return s;
		}
	} else {
		//cout << "Bit " << j << " is wrong\n";
		return -1;
	}
}

int solve() {
	cin >> n >> l;
	// Reset & Read
	fill_n(a1, l, 0);
	fill_n(b1, l, 0);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<l; j++) {
			if (a[i][j] == '1') a1[j]++;
		}
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
		for (int j=0; j<l; j++) {
			if (b[i][j] == '1') b1[j]++;
		}
	}
	// Process
	return rsolve(0);
}

int main() {
	int t;
	cin >> t;
	for (int casenum=1; casenum<=t; casenum++) {
		cout << "Case #" << casenum << ": ";
		int solution = solve();
		if (solution >= 0) {
			cout << solution << "\n";
		} else {
			cout << "NOT POSSIBLE\n";
		}
	}
	return 0;
}