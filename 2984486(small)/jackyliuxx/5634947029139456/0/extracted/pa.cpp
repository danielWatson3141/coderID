//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define LL long long
#define NU 99999999

LL out[200],dv[200];
LL n,l;
LL oc1[50],dv1[50];
LL s2ll(char s[]){
	LL r=0;
	int i;
	for(i=0;s[i];i++){
		r*=2;
		r+=s[i]-'0';
	}
	return r;
}

bool ck(LL x){
	LL i;
	for(i=0;i<n;i++)
		if((out[i]>>x)!=(dv[i]>>x))
			return false;
	return true;
}

void rrv(int x){
	LL i;
	for(i=0;i<n;i++)
		out[i]^=(1<<x);
}

LL swh(LL x){
	LL r=NU;
	if(x<0){
		sort(out,out+n);
		if(ck(0))
			return 0;
		else
			return NU;
	}
	r=min(r,swh(x-1));
	rrv(x);
	r=min(r,swh(x-1)+1);
	rrv(x);
	return r;
}




int main () {
	int t,k=1;
	char s[200];
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d",&n,&l);
		LL i;
		for(i=0;i<n;i++){
			scanf("%s",s);
			out[i]=s2ll(s);
		}
		for(i=0;i<n;i++){
			scanf("%s",s);
			dv[i]=s2ll(s);
		}
		sort(dv,dv+n);
		LL j;
		for(i=l-1;i>=0;i--){
			oc1[i]=dv1[i]=0;
			for(j=0;j<n;j++){
				if(out[j] & (1<<i))
					oc1[i]++;
				if(dv[j] & (1<<i))
					dv1[i]++;
			}
		}
		LL ans=swh(l-1);
		printf("Case #%d: ",k++);
		if(ans==NU)
			puts("NOT POSSIBLE");
		else
			printf("%I64d\n",ans);
	}
}
