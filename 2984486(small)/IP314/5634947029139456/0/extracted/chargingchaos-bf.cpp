#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class chargingchaos
{
	private:
		int n, l;

		vector<string> outlets;

		vector<string> devices;

		void invertbits(int m) {
			for (int i = 0; i < l; ++i) {
				if (((1 << i) & m) > 0) {
					for (int j = 0; j < n; ++j) {
						outlets.at(j).at(i) = '0' + (1 - (outlets.at(j).at(i) - '0'));
					}
				}
			}
		}

		unsigned int countbits(unsigned int m) {
			int sol = 0;
			while (m > 0) {
				sol += (m & 1);
				m >>= 1;
			}
			return sol;
		}

	public:
		chargingchaos() {}

		void input() {
			cin >> n >> l;
			outlets.resize(n);
			for (int f = 0; f < n; ++f) {
				cin >> outlets.at(f);
			}
			devices.resize(n);
			for (int f = 0; f < n; ++f) {
				cin >> devices.at(f);
			}
		}

		string solve() {
			ostringstream oss;
			sort(devices.begin(), devices.end());
			unsigned int minbits = l + 1;
			for (int m = (1 << l) - 1; m >= 0; --m) {
				invertbits(m);
				sort(outlets.begin(), outlets.end());
				if (devices == outlets) {
					minbits = min(minbits, countbits(m));
				}
				invertbits(m);
			}
			if (minbits > (unsigned int)l) {
				oss << "NOT POSSIBLE";
			} else {
				oss << minbits;
			}
			return oss.str();
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		chargingchaos task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
