#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

ifstream fin ("A-small-attempt7.in");
ofstream fout ("a.out");

#define cin fin
#define cout fout
// #define NDEBUG

int main() {
	int T, N, L;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> L;
		vector<bitset<40>> outlets (N), devices(N);
		set<unsigned long> deviceHash;
		for (int n = 0; n < N; n++) {
			bitset<40> outlet (L);
			string input;
			cin >> input;
			for (int l = 0; l < L; l++) {
				outlet.set(l, input[l] == '1');
			}
			outlets[n] = outlet;
		}
		for (int n = 0; n < N; n++) {
			bitset<40> device (L);
			string input;
			cin >> input;
			for (int l = 0; l < L; l++) {
				device.set(l, input[l] == '1');
			}
			devices[n] = device;
			deviceHash.insert(device.to_ulong());
		}
		int nswaps = 0;
		bool swaps[40] = {false};
		for (int i = 0; i < L; i++) {
			int d0 = 0, d1 = 0, out0 = 0, out1 = 0;
			for (int n = 0; n < N; n++) {
				if (devices[n][i]) d1++;
				else d0++;
				if (outlets[n][i]) out1++;
				else out0++;
			}
			if (d0 != out0 && d0 != out1) {
				cout << "Case #" << t << ": " << "NOT POSSIBLE" << '\n';
				goto endOfCase;
			}
			else if (d0 != out0) {
				swaps[i] = true;
				nswaps++;
			}
		}
		for (int i = 0; i < L; i++) {
			if (!swaps[i]) continue;
			else {
				for (int n = 0; n < N; n++) {
					outlets[n].flip(i);
				}
			}
		}
		for (int n = 0; n < N; n++) {
			auto it = deviceHash.find(outlets[n].to_ulong());
			if (it == deviceHash.end()) {
				cout << "Case #" << t << ": " << "NOT POSSIBLE" << '\n';
				goto endOfCase;
			}
			else deviceHash.erase(it);
		}
		cout << "Case #" << t << ": " << nswaps << '\n';
		endOfCase: continue;
	}
	return 0;
}