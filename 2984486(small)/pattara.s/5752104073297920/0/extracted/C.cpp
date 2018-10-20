#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1010];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; ++ i )scanf("%d",&a[i]);
	int INV=999*1000/2;
	int ctr=0;
	for(int i = 0 ; i < n ; ++ i ){
		for(int j = i + 1 ; j < n ; ++ j )
			if(a[j]<a[i])ctr++;
	}
	//printf("ctr = %d\n",ctr);
	if(ctr<=245000)printf("BAD\n");
	else printf("GOOD\n");
}
int main(){
	int t;
	scanf("%d ",&t);
	for(int i = 1;  i <= t ; ++ i ){
		printf("Case #%d: ",i);
		solve();
	}
}
