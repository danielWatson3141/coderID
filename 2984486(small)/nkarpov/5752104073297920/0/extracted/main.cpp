#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define sz(c) (int)(c).size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
const int maxn = 1 << 10;
int p[maxn], was[maxn];

int dfs(int s) {
	if (was[s]) return 0;
	was[s] = 1;
	return 1 + dfs(p[s]);
}

void solve(int test) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		was[i] = 0;
	}
	vector<int> lens;
	int ave = 0.;
	for (int i = 0; i < n; i++) {
		if (!was[i]) {
			lens.pb(dfs(i));
			//eprintf("%d ", lens[sz(lens) - 1]);
			ave += lens[sz(lens) - 1];
		}
	}
	//eprintf("\n");
	//eprintf("total = %d\n", ave);
	//printf("%d\n", sz(lens));
	//sort(all(lens));
	//reverse(all(lens));
	printf("%lf\n", 1. * ave / sz(lens));
}

int main() {
	int T; scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		solve(test);
	}
}
