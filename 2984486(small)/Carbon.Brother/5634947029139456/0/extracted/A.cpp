
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int T,ans,n,l;
int in[256];
int out[256];
int bak[256];
char s[64];

int trans(char s[],int l) {
	int ans=0;
	for (int i=0;i<l;i++) {
		ans=ans*2+s[i]-48;
	}
	return ans;
}

bool check(int c) {
	bool flag=true;
	for (int i=1;i<=n;i++) in[i]^=c;
	sort(in+1,in+1+n);
	for (int i=1;i<=n;i++) if (in[i]!=out[i]) flag=false;
	memcpy(in,bak,sizeof(bak));
	return flag;
}

int bitcnt(int num) {
	int ans=0;
	while (num>0) {
		ans+=num&1;
		num>>=1;
	}
	return ans;
}

int main() {
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for (int ww=1;ww<=T;ww++) {
		ans=10000;
		scanf("%d%d",&n,&l);
		for (int i=1;i<=n;i++) scanf("%s",s),in[i]=trans(s,l);
		for (int i=1;i<=n;i++) scanf("%s",s),out[i]=trans(s,l);
		sort(out+1,out+1+n);
		memcpy(bak,in,sizeof(bak));
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++)
				if (check(in[i]^out[j])) {
					ans=min(ans,bitcnt(in[i]^out[j]));
				}
		}
		if (ans<=l) printf("Case #%d: %d\n",ww,ans);
		else printf("Case #%d: NOT POSSIBLE\n",ww);
	}
	return 0;
}
