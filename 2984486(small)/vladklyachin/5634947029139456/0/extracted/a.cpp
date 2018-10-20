#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int pop(unsigned x) {
   x = x - ((x >> 1) & 0x55555555);
   x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
   x = (x + (x >> 4)) & 0x0f0f0f0f;
   x = x + (x >> 8);
   x = x + (x >> 16);
   return x & 0x0000003f;
}

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	int T;
	fi >> T;
	for (int t = 1; t <= T; ++t) {
		int N, L;
		fi >> N >> L;
		string s;
		vector<unsigned> fr(N), to(N), fr2(N);
		for (int i = 0; i < N; ++i) {
			fi >> s;
			unsigned n = 0;
			for (int b = 0; b < L; ++b) {
				n = (n << 1) | (s[b] == '0');
			}
			fr[i] = n;
		}
		for (int i = 0; i < N; ++i) {
			fi >> s;
			unsigned n = 0;
			for (int b = 0; b < L; ++b) {
				n = (n << 1) | (s[b] == '0');
			}
			to[i] = n;
		}
		sort(to.begin(), to.end());
		unsigned count = 99;
		for (unsigned i = 0; i < (1 << L); ++i) {
			unsigned bits = pop(i);
			if (bits >= count) continue;
			for (int j = 0; j < N; ++j) {
				fr2[j] = fr[j] ^ i;
			}
			sort(fr2.begin(), fr2.end());
			if (equal(fr2.begin(), fr2.end(), to.begin())) {
				count = bits;
			}
		}
		if (count == 99) {
			fo << "Case #" << t << ": NOT POSSIBLE\n";
		} else {
			fo << "Case #" << t << ": " << count << "\n";
		}
	}
}

/* vim: set ts=4 sw=4 noet: */
