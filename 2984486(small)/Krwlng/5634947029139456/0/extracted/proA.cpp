#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<map>
using namespace std;

#define N 1100
char str[N];
long long a[N], b[N], c[N];
int n, m;

inline int getmin(int x, int y) { return x<y?x:y; }

void conduct() {
	int i, j, k, l, ans;
	long long tmp;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; ++i) {
		scanf("%s", str);
		for (a[i]=j=0; j<m; ++j) if (str[j]=='1') a[i]|=(1LL<<j);
	}
	for (i=0; i<n; ++i) {
		scanf("%s", str);
		for (b[i]=j=0; j<m; ++j) if (str[j]=='1') b[i]|=(1LL<<j);
	}
	sort(a, a+n);
	for (ans=m+1, i=0; i<n; ++i) for (j=0; j<n; ++j) {
		tmp=a[i]^b[j];
		for (k=0; k<n; ++k) c[k]=b[k]^tmp;
		sort(c, c+n);
		for (k=0; k<n; ++k) if (c[k]!=a[k]) break;
		if (k<n) continue;
		for (k=l=0; k<m; ++k) if (tmp&(1LL<<k)) l++;
		ans=getmin(l, ans);
	}
	if (ans==m+1) printf("NOT POSSIBLE\n");
	else printf("%d\n", ans);
}

int main() {
	int time; scanf("%d", &time);
	for (int i=1; i<=time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	}
	return 0;
}
