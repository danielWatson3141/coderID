#include <iostream>
#include <string>
#include <cassert>
#include <set>
#include <cstring>

using namespace std;

const int IMPOSSIBLE = 400;

int N, L;
long long A[150], B[150];
long long d[150][150];

long long parse(string s) {
	assert((int) s.size() == L);
	long long ret = 0;
	for (int i = 0; i < L; i++) {
		assert(s[i] == '0' || s[i] == '1');
		ret <<= 1;
		ret += (s[i] - '0');
	}
	return ret;
}

int telbits(long long x) {
	int ret = 0;
	while (x) {
		ret += (x % 2);
		x >>= 1;
	}
	return ret;
}

int match[150];

bool dfs(int cur, int bitmask) {
	for (int b = 0; b < N; b++) {
		if (d[cur][b] != bitmask) continue;
		if (match[b] == -1) {
			match[b] = cur;
			return true;
		}
		if (match[b] == cur) continue;
		if (dfs(match[b], bitmask)) {
			match[b] = cur;
			return true;
		}
	}
	return false;
}

bool tryMatching(long long bitmask) {
	memset(match, -1, sizeof match);
	for (int i = 0; i < N; i++) {
		if (!dfs(i, bitmask)) return false;
	}
	return true;
}

int solve() {
	cin >> N >> L;
	assert(N >= 1 && N <= 150);
	assert(L >= 2 && L <= 40);
	for (int i = 0; i < N; i++) {
		string outlet;
		cin >> outlet;
		A[i] = parse(outlet);
	}
	for (int i = 0; i < N; i++) {
		string device;
		cin >> device;
		B[i] = parse(device);
	}
	set<long long> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			d[i][j] = A[i] ^ B[j];
			s.insert(d[i][j]);
		}
	}
	int best = IMPOSSIBLE;
	for (set<long long>::iterator it = s.begin(); it != s.end(); it++) {
		int b = telbits(*it);
		if (b >= best) continue;
		if (tryMatching(*it)) best = b;
	}
	return best;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i+1 << ": ";
		int r = solve();
		if (r == IMPOSSIBLE)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << r << endl;
	}
	return 0;
}
