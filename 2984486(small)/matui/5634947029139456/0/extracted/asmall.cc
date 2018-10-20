#include<stdio.h>
#include<algorithm>
using namespace std;
int T;
int N,L;
char X[10][11];
char Y[10][11];
int mi=50;
int lim=1;
void move(const int& i){
	for(int k=0 ,t=i;k<L;++k){
		if(t%2>0){
			for(int j=0;j<N;++j)
				X[j][k]=(X[j][k]=='0')?'1':'0';
		}
		t/=2;
	}
	/*
	printf("i= %d",i);
	for(int j=0;j<N;++j)
		printf(" %s ",X[j]);
	printf("\n");
	*/
}
bool check(){
	for(int i=0;i<N;++i){
		bool f=0;
		for(int j=0;j<N;++j){
			//printf("%s %s ",X[i],Y[j]);
			bool find=1;
			for(int k=0;k<L;++k){
				if(X[i][k]!=Y[j][k]){
					find=0;
					break;
				}
			}
			if(find){
				f=1;
				break;
			}
		}
		if(f==0)
			return false;
	}
	return true;
}		
main(){
	scanf("%d",&T);
	for(int num=1;num<=T;++num){
		scanf("%d%d",&N,&L);
		for(int i=0;i<N;++i)
			scanf("%s",X[i]);
		for(int i=0;i<N;++i)
			scanf("%s",Y[i]);
		lim=1;mi=50;
		for(int i=0;i<L;++i)
			lim*=2;
		for(int i=0;i<lim;++i){
			move(i);
			if(check()){
				int k=0;
				for(int t=i;t>0;t/=2)
					k+=t%2;
				mi=min(mi,k);
			}
			move(i);
		}
		printf("Case #%d: ",num);
		if(mi>10)
			printf("NOT POSSIBLE\n");
		else 
			printf("%d\n",mi);
	}
} 
