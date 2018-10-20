#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");

	int T;
	in >> T;
	for (int i = 0; i < T; ++i) {
		int N, L;
		in >> N >> L;
		vector<string> outlets, devices;
		for (int j = 0; j < N; ++j) {
			string x;
			in >> x;
			outlets.push_back(x);
		}
		for (int j = 0; j < N; ++j) {
			string x;
			in >> x;
			devices.push_back(x);
		}

		out << "Case #" << i + 1 << ": ";

		sort(devices.begin(), devices.end());
		int best = L + 1;
		for (int j = 0; j < N; ++j) { //0th device goes to jth outlet
			vector<string> newOut;
			int flipped = 0;
			for (int k = 0; k < N; ++k) {
				newOut.push_back(outlets[k]);
			}
			for (int k = 0; k < L; ++k) {
				if (devices[0][k] != newOut[j][k]) {
					++flipped;
					for (int m = 0; m < N; ++m) {
						newOut[m][k] = (newOut[m][k] == '1') ? '0' : '1';
					}
				}
			}
			sort(newOut.begin(), newOut.end());
			bool good = true;
			for (int k = 0; k < N; ++k) {
				if (devices[k] != newOut[k]) {
					good = false;
				}
			}

			if (good) {
				best = min(best, flipped);
			}
		}

		if (best <= L) {
			out << best << endl;
		}
		else {
			out << "NOT POSSIBLE" << endl;
		}
	}

	return 0;
}