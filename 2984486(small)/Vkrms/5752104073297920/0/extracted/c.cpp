#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<ctime> 
int a[1005];
int stat(){
	int ret=0;
	for(int i=0;i<1000;i++)
	    for(int j=i+1;j<1000;j++) if (a[i]>a[j]) ret++;
	return ret;
}
void work1(int Q){
	printf("Case #%d: BAD\n",Q);
}
void work2(int Q){
	printf("Case #%d: GOOD\n",Q);
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T,Q=0;
	srand(time(0));
	scanf("%d",&T);
	while(T--){
		Q++;
		int M;
		scanf("%d",&M);
		for(int i=0;i<1000;i++) scanf("%d",&a[i]);
		int q=stat();
		int r;
		if (q<234000) work1(Q);
		else if (q<236000){
			r=rand()%1007;
			if (r<966) work1(Q);else work2(Q);
		}
		else if (q<238000){
			r=rand()%1342;
			if (r<1230) work1(Q);else work2(Q);
		}
		else if (q<240000){
			r=rand()%1699;
			if (r<1463) work1(Q);else work2(Q);
		}
		else if (q<242000){
			r=rand()%1904;
			if (r<1455)work1(Q);else work2(Q);
		}
		else if (q<244000){
			r=rand()%2058;
			if (r<1296) work1(Q);else work2(Q);
		}
		else if (q<245000){
			r=rand()%2031;
			if (r<972) work2(Q);else work1(Q);
		} 
		else if (q<246000){
			r=rand()%2031;
			if(r<972)work1(Q);else work2(Q);
		}
		else if (q<248000){
			r=rand()%2019;
			if (r<639) work1(Q);else work2(Q);
		}
		else if (q<250000){
			r=rand()%1883;
			if(r<375) work1(Q);else work2(Q);
		}
		else if (q<252000){
			r=rand()%1583;
			if (r<171) work1(Q);else work2(Q);
		}
		else work2(Q);
	} 
	return 0;
}
