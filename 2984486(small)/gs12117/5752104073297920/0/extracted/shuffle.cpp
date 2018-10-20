#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[1010];
int n=1000;
int tc,tcn;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,q;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		q=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++){
			if(a[i]>i){
				if(a[i]<(i+n)/2)q++;
				else q--;
			}
		}
		if(q>21)printf("Case #%d: BAD\n",tc);
		else printf("Case #%d: GOOD\n",tc);
	}
}