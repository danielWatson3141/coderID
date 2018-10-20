#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cfloat>

#include<iostream>
#include<string>
#include<limits>
#include<sstream>

#include<utility>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;
typedef long long LL;
int n, l;
char outlets[160][50];
char devices[160][50];
vector<LL> f;
int res;

inline int solve(vector<string> flow, vector<string> require, int n, int l) {
	vector<LL> f(l), r(l);
	for (int i = 0; i < l; i++) {

		f[i] = 0;
		r[i] = 0;
		for (int j = 0; j < n; j++) {
			f[i] <<= 1;
			f[i] += flow[j][i] == '1';

			r[i] <<= 1;
			r[i] += require[j][i] == '1';
		}
	}

	int a = 0;
	int b = 0;
	for (int i = 0; i < l; i++) {
		if (f[i] == r[i]) {
			a++;
		} else if ((f[i] + r[i]) == (1 << (n + 1) - 1)) {
			b++;
		}
	}

	if ((a + b) == l) {
		return b;
	} else {
		return -1;
	}
}

inline int solve2(vector<LL>& r) {

	LL result = r[0] ^ f[0];
	for (int i = 1, size = r.size(); i < size; i++) {
		LL x = r[i] ^ f[i];
		if (x != result) {
			return -1;
		}
	}

	int c = 0;
	while (result > 0) {
		if ((result & 1) == 1)
			++c;
		result >>= 1;
	}
	return c;
}

inline void Permutation(int start, int end, vector<LL> list, LL lastr) {
	int i;
	if (start >= end) {
		int tt = solve2(list);

		if (tt >= 0 && tt < res) {
			res = tt;
		}
		return;
	}

	for (i = start; i < end; i++) {
		swap(list[i], list[start]);
		LL result = f[start] ^ list[start];
		if (lastr <= 0 || lastr == result) {
			Permutation(start + 1, end, list, result);
		}
		swap(list[i], list[start]);
	}
}
int main() {
	int caseNum;
	char dummy; //read the '\n' after the caseNum
	scanf("%d%c", &caseNum, &dummy);
	for (int caseCount = 1; caseCount <= caseNum; caseCount++) {
		scanf("%d%d", &n, &l);
		memset(outlets, 0, sizeof(outlets));
		memset(devices, 0, sizeof(devices));
		res = 200;
		int i;
		for (i = 0; i < n; i++) {
			scanf("%s", outlets[i]);
		}
		for (i = 0; i < n; i++) {
			scanf("%s", devices[i]);
		}

		vector<LL> r(n);
		f = vector<LL>(n);
		for (i = 0; i < n; i++) {
			f[i] = 0;
			r[i] = 0;
			for (int j = 0; j < l; j++) {
				f[i] <<= 1;
				if (outlets[i][j] == '1')
					f[i] += 1;
				r[i] <<= 1;
				if (devices[i][j] == '1')
					r[i] += 1;
			}
		}
		Permutation(0, n, r, -1);

		if (res == 200) {
			printf("Case #%d: NOT POSSIBLE\n", caseCount);
		} else {
			printf("Case #%d: %d\n", caseCount, res);
		}
	}
	return 0;
}
