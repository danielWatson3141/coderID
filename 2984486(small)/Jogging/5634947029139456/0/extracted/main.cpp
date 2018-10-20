#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 154;
const int maxl = 44;
FILE *in, *out;
int cs;
int n, L, cnt, ans;
long long a[maxn], b[maxn], c[maxn];
char s[maxl];
stack<int> st[maxn];

void solve() {
	ans = L+1;
	sort(b, b+n);
	for (int i=0; i < n; i++) {
		cnt = 0;
		long long mrk = 0;
		long long bit = 1;
		for (int j=0; j < L; j++) {
			//printf("test %lld\n", (a[0]^b[i])&bit);
			if ((a[0]^b[i])&bit) { mrk = mrk | bit; cnt++; }
			bit = bit << 1;
			//printf("mrk %lld\n", mrk);
			//printf("bit %lld\n", bit);
		}
		//system("pause");
		memcpy(c, a, sizeof(a));
		for (int j=0; j < n; j++) c[j] ^= mrk;
		sort(c, c+n);
		bool yes = true;
		for (int j=0; j < n; j++) if (c[j] != b[j]) {
			yes = false;
			break;
		}
		if (yes && ans > cnt) { ans = cnt; }
	}
	if (ans == L+1) fprintf(out, "NOT POSSIBLE\n");
	else fprintf(out, "%d\n", ans);
}

void convert(long long &v) {
	v = 0;
	for (int i=0; i < L; i++) {
		v = v*2 + s[i]-'0';
	}
}

int main()
{
	int T;
	in = fopen("in.txt", "r");
	out = fopen("out.txt", "w");
	fscanf(in, "%d", &T);
	for (cs=1; cs <= T; cs++) {
		fscanf(in, "%d%d", &n, &L);
		for (int i=0; i < n; i++) {
			fscanf(in, "%s", s);
			convert(a[i]);
		}
		for (int i=0; i < n; i++) {
			fscanf(in, "%s", s);
			convert(b[i]);
		}
		//printf("a[0] %lld\n", a[0]);
		//printf("b[0] %lld\n", b[0]);
		fprintf(out, "Case #%d: ", cs);
		solve();
	}
	return 0;
}
