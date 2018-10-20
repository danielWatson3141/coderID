#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
using namespace std;

#define rep(i,N) for((i) = 0; (i) < (N); (i)++)
#define rab(i,a,b) for((i) = (a); (i) <= (b); (i)++)
#define Fi(N) rep(i,N)
#define Fj(N) rep(j,N)
#define Fk(N) rep(k,N)
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()

vector <long long> outlets, devices;
int L;

long long toLL(string x) {
	long long v = 0;

	for(int i = 0; i < x.length(); i++) {
		v <<= 1;
		if(x[i] == '1') v |= 1;
	}
	return v;
}

int bit_count(long long x) {
	int c = 0;

	while(x) {
		if(x & 1) c++;
		x >>= 1;
	}
	return c;
}

int main() {
	int T,cs;
	int N;
	int i,j;
	string s;

	cin >> T;

	rab(cs,1,T) {
		cin >> N >> L;

		outlets.clear();
		devices.clear();

		Fi(N) {
			cin >> s;
			outlets.push_back(toLL(s));
		}

		Fi(N) {
			cin >> s;
			devices.push_back(toLL(s));
		}

		sort(all(devices));

		vector <long long> temp;
		int min_switch = 1 << 30;

		Fi(sz(devices)) {
			long long x = devices[i] ^ outlets[0];
			temp.clear();

			Fj(sz(outlets)) temp.push_back(outlets[j] ^ x);
			sort(all(temp));

			if(temp == devices) {
				int c = bit_count(x);
				if(c < min_switch) min_switch = c;
			}
		}

		printf("Case #%d: ",cs);

		if(min_switch >= (1 << 30)) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n",min_switch);
		}

	}
	return 0;
}
