#include <bits/stdc++.h>
using namespace std;

int doTheCase();

int main() {
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int mn = doTheCase();
		if (mn == 100)
			cout << "Case #" << i + 1 << ": NOT POSSIBLE\n";
		else
			cout << "Case #" << i + 1 << ": " << mn << "\n";
	}
	return 0;
}

int doTheCase() {
	int mn = 100;
	int N, L;
	long long home[200] = {0}, devices[200] = {0};
	long long tempHome[200], tempDevices[200];
	string h[200], d[200];
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
		cin >> h[i];
	for (int i = 0; i < N; ++i)
		cin >> d[i];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < L; ++j) {
			if (h[i][j] == '1')
				home[i] |= (1 << j);
			if (d[i][j] == '1')
				devices[i] |= (1 << j);
		}

	int temp = 1 << L;
	for (int mask = 0; mask < temp; ++mask) {
		for (int i = 0; i < N; ++i) {
			tempHome[i] = home[i], tempDevices[i] = devices[i];
			for (int j = 0; j < L; ++j)
				if (mask & (1 << j))
					tempHome[i] ^= (1 << j);
		}
		bool correct = 1;
		bool taken[200] = {0};

		for (int i = 0; i < N && correct; ++i) {
			int j = 0;
			for (; j < N; ++j)
				if (!taken[j] && tempDevices[i] == tempHome[j])
					break;
			if (j == N)
				correct = 0;
			else
				taken[j] = 1;
		}

		if (correct)
			mn = min(mn, __builtin_popcount(mask));
	}

	return mn;
}
