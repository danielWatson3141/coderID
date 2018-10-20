#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 1004;
FILE *in, *out;
int cs;
int n;
int a[maxn];

void solve() {
	for (int i=0; i < n; i++) if (a[i] == 0) {
		if (i >= 2*n/3) fprintf(out, "GOOD\n");
		else fprintf(out, "BAD\n");
		break;
	}
}

int main()
{
	int T, x, y;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &T);
	for (cs=1; cs <= T; cs++) {
		fscanf(in, "%d", &n);
		for (int i=0; i < n; i++) fscanf(in, "%d", &a[i]);
		fprintf(out, "Case #%d: ", cs);
		solve();
	}
	return 0;
}
