#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		int n, l;
		scanf("%d %d", &n, &l);

		vector<string> outlet(n);
		for (int it = 0; it < n; it++) {
			cin >> outlet[it];
		}
		string device[n];
		for (int it = 0; it < n; it++) {
			cin >> device[it];
		}

		int ans = -1;
		for (int i = 0; i < n; i++) {
			vector<string> outlet_temp(outlet);
			vector<int> change;

			// check w/ the first device
			for (int j = 0; j < l; j++) {
				if (outlet_temp[0][j] != device[i][j]) {
					change.push_back(j);
				}
			}
			// change all outlet
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < change.size(); k++) {
					if (outlet_temp[j][change[k]] == '0')
						outlet_temp[j][change[k]] = '1';
					else
						outlet_temp[j][change[k]] = '0';
				}
			}

			int count = 0;
			int bit[n];
			memset(bit, 0, 4*n);
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if ((outlet_temp[j] == device[k]) && (!bit[k])) {
						bit[k] = true;
						count++;
						break;
					}
				}
			}
			if ((count == n) && ((ans == -1) || (ans > change.size()))) {
				ans = change.size();
			}
		}
		printf("Case #%d: ", t);
		if (ans == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}
}