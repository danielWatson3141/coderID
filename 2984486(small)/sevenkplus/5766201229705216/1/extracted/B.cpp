#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 1010
int n, he[N], ad[N*2], ne[N*2], t, f[N], s[N]; 
void addE(int x, int y) {
	++t, ne[t] = he[x], he[x] = t, ad[t] = y; 
	++t, ne[t] = he[y], he[y] = t, ad[t] = x; 
}

void ff(int x, int y) {
	int f0 = 0, f1 = N, f2 = N; 
	for (int p = he[x]; p; p = ne[p])
		if (ad[p] != y) {
			ff(ad[p], x); 
			f2 = min(f2+s[ad[p]], f1+f[ad[p]]); 
			f1 = min(f1+s[ad[p]], f0+f[ad[p]]); 
			f0 = f0 + s[ad[p]]; 
		}
	if (f2 >= N) f[x] = f0; 
	else f[x] = min(f0, f2); 
}

void gg(int x, int y) {
	s[x] = 1; 
	for (int p = he[x]; p; p = ne[p])
		if (ad[p] != y) {
			gg(ad[p], x); 
			s[x] += s[ad[p]]; 
		}
}

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
		memset(he, 0, sizeof he); 
		t = 0; 
		cin >> n; 
		for (int i = 0; i < n-1; i ++) {
			int x, y; 
			cin >> x >> y;
			--x, --y; 
			addE(x, y); 
		}
		int S = n-1; 
		for (int i = 0; i < n; i ++) {
			memset(f, 0, sizeof f); 
			memset(s, 0, sizeof s); 
			gg(i, -1); 
			ff(i, -1); 
			S = min(S, f[i]); 
		}
		printf ("Case #%d: %d\n", __, S); 
	}
	return 0; 
}