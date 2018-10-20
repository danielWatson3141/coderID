#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	int T;
	in >> T;
	int perm[1001];
	for (int i = 0; i < T; ++i) {
		int N;
		in >> N;
		for (int j = 0; j < N; ++j) {
			in >> perm[j];
		}
		int lower = 0;
		for (int k = 0; k < N; ++k) {
			if (perm[k] < k) {
				++lower;
			}
		}
		out << "Case #" << (i + 1) << ": ";
		if (45 * N / 100 <= lower && lower <= 49 * N / 100) {
			out << "BAD" << endl;
		}
		else {
			out << "GOOD" << endl;
		}
	}
	return 0;
}