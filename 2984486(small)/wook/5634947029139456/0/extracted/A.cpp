#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)

int n, m;
vector<long long> a, want;

long long fetch() {
	string x; cin >> x;
	long long s = 0, r = 1;
	for(char ch : x) {
		s += (ch - '0') * r;
		r *= 2;
	}
	return s;
}

int bitcount(long long s) {
	int z = 0;
	while(s > 0) {
		if(s & 1) z ++;
		s /= 2;
	}
	return z;
}

int go() {
	cin >> n >> m;
	a = vector<long long>(n);
	want = vector<long long>(n);

	for(int i = 0; i < n; ++ i) a[i] = fetch();
	for(int i = 0; i < n; ++ i) want[i] = fetch();

	// 2^ 10~40
	int ans = 987987987;
	for(long long s = 0; s < (1<<m); ++ s) {
		vector<long long> b = a;
		int cnt = bitcount(s);

		for(long long &x : b) {
			x ^= s;
		}

		unsigned hit = 0;
		for(long long w : want) {
			if(find(b.begin(), b.end(), w) != b.end())
				hit ++;
		}
		if(hit == want.size())
			ans = min(ans, cnt);
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t) {
		int ans = go();
		if(ans < 987987987)
			printf("Case #%d: %d\n", t, ans);
		else
			printf("Case #%d: NOT POSSIBLE\n", t);
	}
	return 0;
}
