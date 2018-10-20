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

int read_num() {
	scanf("%s", s);
	int value = 0;
	for(int i=0; i<l; ++i) {
		value = value * 2;
		if (s[i] == '1') value++;
	}
	return value;
}

int main(){
	int tc;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%i", &tc);
	for(int tt=1; tt<=tc; ++tt) {
		scanf("%i %i", &n, &l);
		int best = MAXN;
		for(int i=0; i<n; ++i) a[i] = read_num();
		for(int i=0; i<n; ++i) b[i] = read_num();
		sort(b, b + n);
		for(int i=0; i<(1<<l); ++i) {
			int tek = 0;
			for(int j=0; j<l; ++j) if ((i >> j) & 1) tek++;
			for(int j=0; j<n; ++j) c[j] = a[j] ^ i;
			sort(c, c + n);

			bool ok = true;
			for(int j=0; j<n; ++j) ok = ok && b[j]==c[j];
			if (ok && tek < best) best = tek;
		}
		printf("Case #%i: ", tt);
		if (best==MAXN) printf("NOT POSSIBLE\n"); else printf("%i\n", best);
	}

	return 0;
}

