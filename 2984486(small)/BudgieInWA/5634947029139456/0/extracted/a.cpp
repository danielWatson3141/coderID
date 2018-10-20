#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		cout << "Case #" << kase << ": ";

		int N, L;
		cin >> N >> L;
		unsigned long flow[N];
		for (int i = 0; i < N; i++) {
			string b;
			cin >> b;
			flow[i] = (unsigned long) strtol(b.c_str(), NULL, 2);
		}
		unsigned long plug[N];
		for (int i = 0; i < N; i++) {
			string b;
			cin >> b;
			plug[i] = (unsigned long) strtol(b.c_str(), NULL, 2);
		}

		int best = 100;
		for (int i = 0; i < N; i++) {
			//cerr << i << endl;
			// figure out how to make the first plug work for the ith fow.
			unsigned long mask = plug[0] ^ flow[i];
			//cerr << mask;

			// test to see if this mask works
			bool outergood = true;
			for (int j = 0; j < N && outergood; j++) {
				//cerr << " checking " << j << endl;
				bool good = false;
				for (int k = 0; k < N && !good; k++) {
					//cerr << "  with " << k << ": " << (plug[j]&mask) << " vs " << flow[k] << endl;
					if ((plug[j] ^ mask) == flow[k]) good = true;
				}
				if (!good) outergood = false;
			}
			//cerr << "done" << endl;

			if (outergood) {
				//calculate cost
				//cerr << "yer" << endl;
				int c = 0;
				for (unsigned long b = 1; b < 2000000000000UL; b *= 2) {
					//cerr << "b " << b << endl;
					//cerr << "l " << (2UL^40) << endl;
					if (mask & b) c++;
					if (b == 0) exit(1);
				}
				if (c < best) best = c;
			}
		}
		if (best == 100) {
			cout << "NOT POSSIBLE";
		} else {
			cout << best;
		}
		cout << endl;
	}
	return 0;
}
