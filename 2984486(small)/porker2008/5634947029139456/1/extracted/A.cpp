#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long outlets[150];
long long device[150];
long long new_outlets[150];

long long str2ll(string input) {
	long long ans = 0;
	for(int i=0;i<input.size();i++) {
		ans <<= 1;
		if(input[i] == '1') {
			ans += 1;
		}
	}
	return ans;
}

int ll2bit(long long input) {
	int ans = 0;
	while(input) {
		ans += input % 2;
		input>>=1;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		int N, L;
		cin >> N >> L;
		string input;
		for(int i = 0; i < N; i++) {
			cin >> input;
			outlets[i] = str2ll(input);
		}
		for(int i = 0; i < N; i++) {
			cin >> input;
			device[i] = str2ll(input);
		}
		sort(device,device+N);
		sort(outlets,outlets+N);
		long long ans = -1;
		for(int i = 0; i < N; i++) {
			long long temp = outlets[i] ^ device[0];
			if(ans >= 0 && ll2bit(temp) >= ans) continue;
			for(int j = 0; j < N; j++) {
				new_outlets[j] = outlets[j] ^ temp;
			}
			sort(new_outlets, new_outlets+N);
			bool ok = true;
			for(int j = 0; j < N; j++) {
				if(new_outlets[j] != device[j]) {
					ok = false;
					break;
				}
			}
			if(ok) {
				ans = ll2bit(temp);
			}
		}
		cout << "Case #" << c << ": ";
		if(ans >= 0) cout << ans << endl;
		else cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}