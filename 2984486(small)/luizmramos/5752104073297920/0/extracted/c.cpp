#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
int n;
int v[2000];
int main(){
	srand(time(NULL));
	int t;
	scanf("%d",&t);
	for(int xxx=0;xxx<t;xxx++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&v[i]);
		}
		int c=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v[j-1]>v[j]){
					std::swap(v[j-1],v[j]);
					c++;
				}
			}
		}
		bool resposta = rand()%2==0;
		int k=0;
		for(int i=0;i<n;i++){
			if(v[i]==i || v[i]==999-i)k++;
		}
		if(k>3)resposta=true;
		if(c>185000)resposta=true;
		if(c<180000)resposta=false;
		
		printf("Case #%d: %s\n",xxx+1,resposta?"GOOD":"BAD");
	}
}