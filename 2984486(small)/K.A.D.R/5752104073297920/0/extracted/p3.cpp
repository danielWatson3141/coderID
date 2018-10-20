#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

int a, b, c, d, n, m, k, kolt;
VI get_inv(VI &p) {
	VI res(L(p));
	rept(i, L(p)) {
		res[p[i]] = i;
	}
	return res;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &kolt);
	vector<pair<long double, int> > mem;
	rep(hod, kolt) {
		scanf("%d", &n);
		VI perm(n);
		rept(i, n) {
			scanf("%d", &perm[i]);
		}
		VI inv = get_inv(perm);
		long double sum = 0.0;
		rept(i, L(perm)) {
			sum -= pow((long double)abs(i - inv[i]), 1.5) * (i + 1);
		}
		mem.pb(mp(sum, hod - 1));
	}
	VI our(kolt, 1);
	SORT(mem);
	rept(i, kolt / 2) {
		our[mem[i].y] = 0;
	}

	rept(i, kolt) {
		printf("Case #%d: ", i + 1);
		if (!our[i]) printf("GOOD\n"); else
		printf("BAD\n");
	}
}
