#pragma region includes
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip> // out << setprecision(n) << fixed; // set to show n decimal places
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
#pragma endregion

// Problem A. Charging Chaos

#pragma region files
//string infile = "sample.txt";
string infile = "A-small-attempt1.in";
//string infile = "A-large.in";
string outfile = "output.txt";

ifstream in(infile);
ofstream out(outfile);
#pragma endregion

int main() {
	
	int T;
	in >> T;
	for (int test = 1; test <= T; ++test) {
		out << "Case #" << test << ": ";
		int N, L;
		in >> N >> L;

		unordered_set<string> outlet;
		for (int i = 0; i < N; ++i) {
			string s;
			in >> s;
			outlet.insert(s);
		}

		vector<string> device;
		for (int i = 0; i < N; ++i) {
			string s;
			in >> s;
			device.push_back(s);
		}
		
		bool good;
		vector<int> valid;
		for (auto it = outlet.begin(); it != outlet.end(); ++it) {
			good = true;
			vector<bool> mask;
			int bits = 0;
			for (int j = 0; j < L; ++j) {
				bool same = device[0][j] == (*it)[j];
				mask.push_back(same);
				if (!same) {
					++bits;
				}
			}
			for (int i = 1; i < N; ++i) {
				string s;
				for (int j = 0; j < L; ++j) {
					if (mask[j]) {
						s += device[i][j];
					} else {
						s += '0' + '1' - device[i][j];
					}
				}
				if (outlet.find(s) == outlet.end()) {
					good = false;
					break;
				}
			}
			if (good) {
				valid.push_back(bits);
			}
		}

		if (valid.size() > 0) {
			sort(valid.begin(), valid.end());
			out << *valid.begin() << endl;
		} else {
			out << "NOT POSSIBLE" << endl;;
		}
	}

	return 0;
}