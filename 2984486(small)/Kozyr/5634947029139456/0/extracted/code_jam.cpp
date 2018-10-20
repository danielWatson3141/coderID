#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

unsigned long long s2b(string s, int L) {
	unsigned long long r = 0;

	for (int i=0; i<L; i++) {
		r = (r<<1) | (s[i] == '1');
	}

	return r;
}

unsigned long long count_bits(unsigned long long n) {
	unsigned long long c;
	for (c = 0; n; c++)
		n &= n - 1;
	return c;
}

int main() {
	int T, t;

	vector<int > res;
	vector<int>::iterator it;

	unsigned long long o[150];
	unsigned long long d[150];
	unsigned long long w[150];

	cin >> T;
	for (t=0; t<T; t++) {
		int N, L;
		cin >> N >> L;

		int i;
		string s;

		//unsigned long long x, x1=0, x2=0;
		unsigned long long x;

		for (i=0; i<N; i++) {
			cin >> s;
			o[i] = s2b(s, L);
			//x1 ^= o[i];
		}
		sort(o,o+N);
		for (i=0; i<N; i++) {
			cin >> s;
			d[i] = s2b(s, L);
			//x2 ^= d[i];
		}

		/*
		x = x1 ^ x2;
		for (i=0; i<N; i++) {
			d[i] ^= x;
		}
		sort(d,d+N);

		bool ok = true;
		for (i=0; i<N; i++) {
			ok &= (d[i] == o[i]);
		}

		if (ok) {
			res.push_back(count_bits(x));
		}
		else {
			res.push_back(-1);
		}
		*/

		bool ok;

		for (x=0; x<(unsigned long long)(1<<L); x++) {
			for (i=0; i<N; i++) {
				w[i] = (d[i] ^ x);
			}
			sort(w,w+N);
			ok = true;
			for (i=0; i<N; i++) {
				ok &= (w[i] == o[i]);
			}
			if (ok) {
				res.push_back(count_bits(x));
				break;
			}
		}
		if (!ok) {
			res.push_back(-1);
		}
	}

	t = 1;
	for (it = res.begin(); it<res.end(); it++, t++) {
		cout << "Case #" << t << ": ";
		if (*it == -1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << (*it) << endl;
			//cout << count_bits(*it) << " " << (bitset<10>) (*it)<< endl;
	}

	return 0;
}
