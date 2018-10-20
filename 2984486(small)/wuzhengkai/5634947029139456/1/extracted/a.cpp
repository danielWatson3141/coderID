#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
#define LL long long

using namespace std;

int tt;
int n,l;
LL f[150],g[150],h[150];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	cin >> tt;
	for (int ii=1;ii<=tt;++ii) {
		cin >> n >> l;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for (int i=0;i<n;++i) {
			string s;
			cin >> s;
			for (int j=0;j<l;++j)
				f[i]=(f[i]<<1)+s[j]-'0';
		}
		for (int i=0;i<n;++i) {
			string s;
			cin >> s;
			for (int j=0;j<l;++j)
				g[i]=(g[i]<<1)+s[j]-'0';
		}
		int res=10000000;
		sort(f,f+n);
		sort(g,g+n);
		for (int i=0;i<n;++i) {
			LL p=g[i]^f[0];
			for (int j=0;j<n;++j)
				h[j]=f[j]^p;
			sort(h,h+n);
			bool flag=true;
			for (int j=0;j<n;++j)
				if (g[j]!=h[j]) flag=false;
			if (flag) res=min(res,__builtin_popcountll(p));
		}
		printf("Case #%d: ",ii);
		if (res<=l) printf("%d\n",res);
		else printf("NOT POSSIBLE\n");
	}
}

