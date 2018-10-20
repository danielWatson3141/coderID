#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
long long flows[150];
long long outlets[150];
long long temp[150];

long long readBinary() {
	long long number = 0;
	for (int i = 0; i < L; i++) {
		number = number * 2;

		char c;
		cin >> c;
		number += (c - '0');
	}
	return number;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			flows[i] = readBinary();
		}
		sort(flows, flows+N);

		for (int i = 0; i < N; i++) {
			outlets[i] = readBinary();
		}
		int best = 1000;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				long long candidate = flows[i]^outlets[j];
				long long c = candidate;
				int ones = 0;
				while (c > 0) {
					if (c%2) ones++;
					c /= 2;
				}
				if (ones >= best) continue;

				for (int k = 0; k < N; k++) {
					temp[k] = outlets[k]^candidate;
				}
				sort(temp, temp+N);
				if (equal(flows, flows+N, temp)) best = ones;
			}
		}
		cout << "Case #" << t << ": ";
		if (best < 1000) cout << best;
		else cout << "NOT POSSIBLE";
		cout << '\n';
	}
	return 0;
}
