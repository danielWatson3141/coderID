// Compiler: g++-4.8 (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
// Flags: -O2 -Wall -g -std=c++0x
// Aina häviää

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

uint64_t readBitstring(const string& src) {
	uint64_t ret = 0;
	for(char c : src) {
		ret <<= 1;
		if(c == '1') ret |= 1;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(false);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; ++t) {
		int N, L;
		cin >> N >> L;
		
		vector<uint64_t> outlets(N);
		vector<uint64_t> devices(N);
		
		for(int i = 0; i < N; ++i) {
			string S;
			cin >> S;
			outlets[i] = readBitstring(S);
		}
		for(int i = 0; i < N; ++i) {
			string S;
			cin >> S;
			devices[i] = readBitstring(S);
		}
		sort(devices.begin(), devices.end());
		
		int best = INT_MAX;
		for(int for_out1 = 0; for_out1 < N; ++for_out1) {
			uint64_t flip = outlets[0] ^ devices[for_out1];
			vector<uint64_t> flipped_outlets(N);
			for(int i = 0; i < N; ++i) {
				flipped_outlets[i] = outlets[i] ^ flip;
			}
			sort(flipped_outlets.begin(), flipped_outlets.end());
			
			if(equal(devices.begin(), devices.end(), flipped_outlets.begin())) {
				best = min(best, __builtin_popcountll(flip));
			}
		}
		
		cout << "Case #" << t + 1 << ": ";
		if(best == INT_MAX) {
			cout << "NOT POSSIBLE\n";
		} else {
			cout << best << "\n";
		}
	}
	
	return 0;
}
