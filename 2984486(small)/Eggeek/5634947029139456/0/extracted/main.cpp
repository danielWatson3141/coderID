#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long llong;
#define maxn 200
#define maxl 50
int n,l;
char s[maxn][maxl], s2[maxn][maxl];
llong num[maxn],num2[maxn];


int cntb(int msk) {
	int res = 0;
	while (msk) {
		if (msk&1) res++;
		msk>>=1;
	}
	return res;
}

int getans(int msk) {
	memset(num,0,sizeof(num));
	for (int i=0 ; i<n ; i++ ) {
		llong x = 1;
		for (int j=0 ; j<l ; j++, x<<=1 ) {
			int t = (msk>>j)&1;
			if (s[i][j]=='1' && t==0) num[i] |= x;
			if (s[i][j]=='0' && t==1) num[i] |= x;
		}
	}
//	printf("msk:%d\n", msk);
//	for (int i=0 ; i<n ; i++ ) printf("%I64d\n",num[i]);

	sort(num,num+n);
	for (int i=0 ; i<n ; i++ ) if (num[i] != num2[i]) return -1;
	return cntb(msk);
}

void work() {
	memset(num2,0,sizeof(num2));
	scanf("%d%d",&n,&l);
	for (int i=0 ; i<n ; i++ ) scanf("%s",s[i]);
	for (int i=0 ; i<n ; i++ ) scanf("%s",s2[i]);
	
	for (int i=0 ; i<n ; i++ ) {
		llong x = 1;
		for (int j=0 ; j<l ; j++,x<<=1 ) {
			if (s2[i][j]=='1') num2[i] |= x;
		}
	}

	sort(num2,num2+n);

	int ans = 2*l;
	for (int x=0 ; x<(1<<l) ; x++ ) {
		int tmp = getans(x);
		if (tmp!=-1)
		ans = min(ans,tmp);
	}
	if (ans>l) printf("NOT POSSIBLE\n");
	else printf("%d\n", ans);
}

int main() {
	int cas;
	freopen("test.txt", "r", stdin);
	freopen("ans.txt", "w", stdout);
	scanf("%d",&cas);
	for (int t=1 ; t<=cas ; t++ ) {
		printf("Case #%d: ",t);
		work();
	}
	return 0;
}