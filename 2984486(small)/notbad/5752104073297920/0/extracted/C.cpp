#include <iostream>
#include <vector>

using namespace std;

int main () {
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("c.txt", "w", stdout);

	int N;
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<int> vi(N);
		for (int i = 0; i < N; ++i) {
			cin >> vi[i];
		}
		int cnt = 0;
		int tt = N*(N-1)/2;
		for (int i = 0; i < N; ++i) {
			for (int j = i+1; j < N; ++j) {
				if (vi[i] > vi[j]) ++cnt;
			}
		}
		//cout << cnt - tt/2 << endl;
		cout << "Case #" << t << ": ";
		if (abs(cnt - tt/2) >= tt / 72) {
			cout << "BAD" << endl;
		} else {
			cout << "GOOD" << endl;
		}		
	}		
}
