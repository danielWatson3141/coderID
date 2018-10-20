#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
#define NN 168
char tmp1[NN][NN], tmp2[NN][NN];

bool cmp(char *a, char *b)
{
	if (strcmp(a,b)<0) return true;
	return false;
}

bool ok(const char a[][NN], const char b[][NN], int c[], int n, int m)
{
	char *ap[NN], *bp[NN];
	int i;
	for (i=0; i<n; i++)
	{
		strcpy(tmp1[i], a[i]);
		strcpy(tmp2[i], b[i]);
		ap[i]=tmp1[i];
		bp[i]=tmp2[i];
	}
	int k;
	for (k=0; k<m; k++) if (c[k])
	{
		for (i=0; i<n; i++) {
			if (ap[i][k]=='1') ap[i][k]='0';
			else ap[i][k]='1';
		}
	}
	sort(ap, ap+n, cmp);
	sort(bp, bp+n, cmp);
	for (i=0; i<n; i++) if (strcmp(ap[i], bp[i])) return false;
	return true;
}

int cal_f(char out[][NN], char d[][NN], int n, int m)
{
	int i=0;
	int minf=-1;
	int change[NN];
	for (i=0; i<n; i++)
	{
		int j, cn=0;
		for (j=0; j<m; j++) {
			if (out[i][j]!=d[0][j]) change[j]=1;
			else change[j]=0;
			cn += change[j];
		}
		if (ok(out, d, change, n, m) && (minf==-1 || cn<minf)) minf=cn;
	}
	return minf;
}

int main()
{
	int t, i, j;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);
	for (int cas=1; cas<=t; cas++)
	{
		int n,l;
		char out[NN][NN], d[NN][NN];
		char *op[NN], *dp[NN];
		scanf("%d%d",&n,&l);
		for (i=0; i<n; i++) scanf("%s", out[i]);
		for (i=0; i<n; i++) scanf("%s", d[i]);
		int res=cal_f(out, d, n, l);
		if (res<0) printf("Case #%d: NOT POSSIBLE\n", cas);
		else printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}

