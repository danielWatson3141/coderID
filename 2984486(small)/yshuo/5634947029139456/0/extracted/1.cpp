#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, l;
		cin >> n >> l;

		vector<long long> a, b;
		for (int j = 0; j < n; j++) {
			string temp;

			cin >> temp;

			long long r = 0;
			for (int k = 0; k < temp.length(); k++) {
				r = r * 2 + (temp[k] - '0');
			}
			a.push_back(r);
		}
		for (int j = 0; j < n; j++) {
			string temp;
			cin >> temp;
			long long r = 0;
			for (int k = 0; k < temp.length(); k++) {
				r = r * 2 + (temp[k] - '0');
			}
			b.push_back(r);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		bool f = true;

		for (int j = 0; j < n; j++) {
			if (a[j] != b[j]) {
				f = false;
			}
		}

		if (f) {
			cout << "Case #" << i+1 << ": 0" << endl;
			continue;
		}
		f = false;
		long long cur = a[0];
		int result = 41;

		for (int j = 0; j < n; j++) {
			long long diff = cur ^ b[j];
			for (int k = 0; k < n; k++) {
				a[k] ^= diff;
				
			}
			sort(a.begin(), a.end());
			bool ff = true;
			for (int j = 0; j < n; j++) {
				if (a[j] != b[j]) {
					ff = false;
				}
			}
			if (ff) {
				int count = 0;
				while (diff != 0) {
					if (diff % 2 == 1) 
						count++;
					diff /= 2;
				}
				f = true;
				if (result > count )
					result = count;
			}
			for (int k = 0; k < n; k++) {
				a[k] ^= diff;
			}
		}
		
		if (f) {
			cout << "Case #" << i+1 << ": " << result << endl;
		} else {
			cout << "Case #" << i+1 << ": NOT POSSIBLE\n";
		}
	}
}