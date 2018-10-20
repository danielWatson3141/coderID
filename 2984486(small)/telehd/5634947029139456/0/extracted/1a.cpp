#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	int N, L;
	int i, j, k, l, p;
	vector<string> devices(200);
	vector<string> outlets(200);
	string test;
	bool switches[40];
	int minSwitchCount = 1000;
	int switchCount;
	bool possible;
	cin >> T;
	for (i=0; i<T; i++) {
		cin >> N >> L;
		for (j=0; j<N; j++) {
			cin >> outlets[j];
		}
		for (j=0; j<N; j++) {
			cin >> devices[j];
		}
		sort(devices.begin(), devices.begin()+N);
		minSwitchCount = 1000;
		possible = false;
		for (l=0; l<N; l++) {
			switchCount = 0;
			for (j=0; j<L; j++) {
				if (outlets[0][j] != devices[l][j]) {
					switches[j] = true;
					switchCount++;
				}
				else {
					switches[j] = false;
				}
			}

			if (switchCount < minSwitchCount) {
				bool good = true;
				for (k = 1; k < N && good; k++) {
					test = outlets[k];
					for (p = 0; p < L; p++) {
						if (switches[p]) {
							test[p] = (test[p] == '0')? '1' : '0';
						}
					}
					if (!binary_search(devices.begin(), devices.begin()+N, test)) {
						good = false;
					}
				}
				if (good) {
					possible = true;
					minSwitchCount = switchCount;
				}
			}
		}
		cout << "Case #" << i+1 << ": ";
		if (possible) {
			cout << minSwitchCount;
		}
		else {
			cout << "NOT POSSIBLE";
		}
		cout << endl;
	}

	return 0;
}
