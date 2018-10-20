#include <stdio.h>
int main(){
	int cases,p;
	scanf("%d", &cases);
	for(p=1;p<=cases;p++){
		int n;
		scanf("%d", &n);
		int i;
		int dd=0;
		double exp = 0;
		for(i=0;i<n;i++){
			int x;
			scanf("%d", &x);
			int tmp=x-i;
			if(tmp<0)
				tmp=-tmp;
			dd+=tmp;
			if(i>0)
				exp += i*(i+1)/2;
			if(i<n-1)
				exp += (n-i-1)*(n-i)/2;
			//printf("%lf\n", exp);
		}
		double var=(double)dd/(double)n;
		exp=exp/(double)(n*n);
		//printf("%lf %lf\n", var, exp);
		if(var/exp < 0.99)
			printf("Case #%d: BAD\n", p);
		else
			printf("Case #%d: GOOD\n", p);
	}
	return 0;

}
