#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define LD long double

using namespace std;

int n;
int tt;
int a[1010];
LD ff[1010][1010];
LD f[1010][1010];

void solve(int x) {
	memset(f,0,sizeof(f));
	f[0][x]=1;
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j)
			if (j!=i) {
				f[i+1][j]+=f[i][j]*(n-1)/n;
				f[i+1][i]+=f[i][j]/n;
				f[i+1][j]+=f[i][i]/n;
			}
		f[i+1][i]+=f[i][i]/n;
	}
	for (int i=0;i<n;++i)
		ff[x][i]=log(f[n][i]);
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);

	n=1000;
	for (int i=0;i<n;++i)
		solve(i);

	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d: ",ii);
		scanf("%d",&n);

		double hh=-(n-1)*log(n),gg=0;
		for (int i=0;i<n;++i) scanf("%d",&a[i]);
		for (int i=0;i<n-1;++i) gg+=ff[a[i]][i];
		//printf("%.10lf %.10lf ",(double)hh,(double)gg);
		if (hh>gg) puts("GOOD");
		else puts("BAD");
	}
}
