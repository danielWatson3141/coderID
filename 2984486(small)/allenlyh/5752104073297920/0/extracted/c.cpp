
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
const double eps=0.01;
const int INF=0x3f3f3f3f;

const int maxn=1000+10;
int n;
int a[maxn];
double f[2][maxn][maxn];
double aim = 1e-3;

void pre() {
	FILE *f1;
//	freopen("out1", "r", f1);
	f1 = fopen("out1","r");
	FILE *f2;
//	freopen("out2", "r", f2);
	f2 = fopen("out2","r");
	for (int i=0;i<1000;i++)
		for (int j=0;j<1000;j++) {
			fscanf(f1,"%lf",&f[0][i][j]);
			fscanf(f2,"%lf",&f[1][i][j]);
		}
}

void work() {
	scanf("%d", &n);
	for (int i=0;i<n;i++) scanf("%d", &a[i]);
//	int t1=0,t2=0;
	double t1 = 1,t2 = 1;
	for (int i=0;i<n;i++) {
		t1 *= f[0][i][a[i]]*1000.0;
		t2 *= f[1][i][a[i]]*1000.0;
//		if (sign(f[0][i][a[i]] - aim) != 0) t1++;
//		if (sign(f[1][i][a[i]] - aim) != 0) t2++;
	}
	if (sign(t1 - t2) > 0) puts("BAD"); else puts("GOOD");
}

int main() {
	pre();
	int T;
	int cas=0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++cas);
		work();
	}
	return 0;
}
