
//by allenlyh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <complex>

using namespace std;

typedef long long LL;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define sqr(x) (x)*(x)
#define sign(x) (((x)<-eps)?-1:(x)>eps)
#define foreach(ite,s) for (__typeof(s.begin()) ite=s.begin();ite!=s.end();ite++)
#define lowbit(x) ((x) & (-(x)))
const double eps=1e-9;
const int INF=0x3f3f3f3f;

const int maxn=200;
const int maxl=50;
int n,l;
char st[maxn][maxl];
char ask[maxn][maxl];
bool flag[maxl];
int tot[maxl];
int ctot[maxl];
LL get_a[maxn];
LL che[maxn];
int ans;

void solve(int a, int b) {
	int tmp=0;
	for (int i=0;i<l;i++) {
		if (st[a][i] != ask[b][i]) {
			tmp++;
			flag[i] = 1;
		} else flag[i] = 0;
	}
	for (int i=0;i<n;i++) {
		get_a[i] = 0;
		for (int j=0;j<l;j++) {
			get_a[i] = (get_a[i] * 2) + ((st[i][j] - '0') ^ flag[j]);
		}
	}
	sort(get_a, get_a + n);
	for (int i=0;i<n;i++) {
		if (get_a[i] != che[i]) return;
	}
	ans = min(ans, tmp);
}

void work() {
	scanf("%d%d", &n, &l);
	for (int i=0;i<n;i++) scanf("%s", st[i]);
	for (int i=0;i<n;i++) scanf("%s", ask[i]);
	memset(tot, 0, sizeof(tot));
	for (int i=0;i<n;i++) {
		for (int j=0;j<l;j++) {
			if (st[i][j] == '1') tot[j]++;
		}
	}
	for (int i=0;i<n;i++) {
		che[i] = 0;
		for (int j=0;j<l;j++) {
			che[i] = (che[i] * 2) + (ask[i][j] - '0');
		}
	}
	sort(che, che+n);
	ans = INF;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			solve(i, j);
		}
	}
	if (ans == INF) {
		puts("NOT POSSIBLE");
	} else {
		printf("%d\n", ans);
	}
}

int main() {
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
