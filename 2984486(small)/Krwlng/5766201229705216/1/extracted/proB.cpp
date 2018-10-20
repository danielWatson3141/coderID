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

struct edge { int nxt, des; };
#define N 11000
edge e[N];
int hd[N];
int n, m, cnt;

inline int getmax(int x, int y) { return x>y?x:y; }

void insert(int x, int y) {
	++cnt; e[cnt].nxt=hd[x]; e[cnt].des=y; hd[x]=cnt;
}

int dfs(int x, int pa) {
	int i, a, b, c, tmp;
	a=-1; b=-1;
	for (i=hd[x]; i; i=e[i].nxt) if (e[i].des!=pa) {
		tmp=dfs(e[i].des, x);
		if (tmp>a) { c=tmp; tmp=a; a=c; }
		if (tmp>b) { c=tmp; tmp=b; b=c; }
	}
	if (a==-1 || b==-1) return 1;
	else return a+b+1;
}

void conduct() {
	int i, j, k, ans;
	scanf("%d", &n);
	memset(hd, 0, sizeof(hd)); cnt=0;
	for (i=1; i<n; ++i) {
		scanf("%d%d", &j, &k); --j; --k;
		insert(j, k); insert(k, j);
	}
	for (ans=i=0; i<n; ++i) ans=getmax(ans, dfs(i, -1));
	printf("%d\n", n-ans);
}

int main() {
	int time; scanf("%d", &time);
	for (int i=1; i<=time; ++i) {
		printf("Case #%d: ", i);
		conduct();
	}
	return 0;
}
