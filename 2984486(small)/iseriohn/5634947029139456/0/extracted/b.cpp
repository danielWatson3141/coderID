#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

const int maxn=200;

long long a[maxn],b[maxn],c[maxn*maxn];
char st[maxn];

int main() {
	int cases;
	scanf("%d",&cases);
	for (int o=0; o<cases; ++o) {
		int n,m; 
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; ++i) {
			scanf("%s",st);
			a[i]=0ll;
			for (int j=0; j<m; ++j) {
				a[i]=a[i]*2ll+(long long)(st[j]-'0');
			}
		}
		for (int i=0; i<n; ++i) {
			scanf("%s",st);
			b[i]=0ll;
			for (int j=0; j<m; ++j) {
				b[i]=b[i]*2ll+(long long)(st[j]-'0');
			}
		}
		int tot=0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				c[tot]=(b[j]^a[i]);
				++tot;
			}
		}
		sort(c,c+tot);
		int s=0,ans=maxn;
		c[tot]=-c[tot-1];
		for (int i=1; i<=tot; ++i) {
			if (c[i]!=c[i-1]) {
				if (i-s==n) {
					long long sum=c[s];
					int num=0;
					while (sum) {
						if ((sum&1)==1) ++num;
						sum>>=1;
					}
					ans=min(ans,num);
				}
				s=i;
			}
		}
		if (ans<maxn) {
			printf("Case #%d: %d\n",o+1,ans);
		} else {
			printf("Case #%d: NOT POSSIBLE\n",o+1);
		}
	}
	return 0;
}

