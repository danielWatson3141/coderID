#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long toNum(string s) {
	long long res = 0;
	for (int i = 0; i < s.size(); i++) {
		res = res * 2LL + (s[i] - '0');
	}
	return res;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w+", stdout);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N = 0, L = 0;

		map <long long, long long> occur;
		vector <long long> swit;
		
		string s;
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> s;
			long long num = toNum(s);
			occur[num] = -1;
		}

		for (int i = 0; i < N; i++) {
			cin >> s;
			long long num = toNum(s);
			swit.push_back(num);
		}

		int res = -1;
		for (auto iter = occur.begin(); iter != occur.end(); iter++) {
			for (auto next = swit.begin(); next != swit.end(); next++) {
				long long mask = (iter->first) ^ (*next);

				int remain = N;
				for (int i = 0; i < N; i++) {
					long long num = mask ^ swit[i];
					if (occur.count(num) > 0) {
						remain --;
					}
				}

				if (remain == 0) {
					int t = mask;
					int bits = 0;
					while (t) {
						if (t & 1) {
							bits++;
						}

						t /= 2;
					}

					if (res == -1 || res > bits) {
						res = bits;
					}
				}
			}
		}

		if (res == -1) {
			cout << "Case #" << cas << ": NOT POSSIBLE" << endl;
		} else {
			cout << "Case #" << cas << ": " << res << endl;
		}
	}
    return 0;
}
