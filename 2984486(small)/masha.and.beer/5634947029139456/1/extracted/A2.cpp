// A.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 160

int a[MAXN];
int b[MAXN];
int c[MAXN];
int n, l;
char s[MAXN];
int q[MAXN][MAXN];
int py[MAXN];
int nn[MAXN];

int read_num() {
	scanf("%s", s);
	int value = 0;
	for(int i=0; i<l; ++i) {
		value = value * 2;
		if (s[i] == '1') value++;
	}
	return value;
}

bool rec(int x) {
	if (nn[x]) return x;
	nn[x] = true;
	for(int i=0; i<n; ++i) if (q[x][i]) {
		if (py[i] == -1 || rec(py[i])) {
			py[i] = x;
			return true;
		}
	}
	return false;
}

int pairs() {
	int cnt = 0;
	memset(py, 0xFF, sizeof(py));
	for(int i=0; i<n; ++i) {
		memset(nn, 0, sizeof(nn));
		if (rec(i)) cnt++;
	}

	/*
	printf("cnt=%i\n", cnt);
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) printf("%i ", q[i][j]);
		printf("\n");
	}
	for(int i=0; i<n; ++i) printf("%i %i\n", py[i], i);
	*/
	return cnt;
}

int main(){
	int tc;
	freopen("A-large.in", "r", stdin);
	//freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%i", &tc);
	for(int tt=1; tt<=tc; ++tt) {
		scanf("%i %i", &n, &l);
		int best = MAXN;
		for(int i=0; i<n; ++i) a[i] = read_num();
		for(int i=0; i<n; ++i) b[i] = read_num();

		for(int i=0; i<n; ++i) {			
			int x = a[0] ^ b[i];
			for(int j=0; j<n; ++j)
				for(int z=0; z<n; ++z)
					if ((a[j] ^ x) == b[z]) q[j][z] = 1; else q[j][z] = 0;
			if (pairs() == n) {
				int tmp = 0;
				for(int j=0; j<l; ++j) if ((x >> j)&1) tmp++;
				if (tmp < best) best = tmp;
			}
		}
		printf("Case #%i: ", tt);
		if (best==MAXN) printf("NOT POSSIBLE\n"); else printf("%i\n", best);
	}

	return 0;
}

