#pragma warning(disable:4996)
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstring>
#include <map>
#include <random>
using namespace std;

std::random_device rd;
std::mt19937 gen(rd());
const int max_n=100;
int n[max_n];
int hit[max_n][max_n];
void tst(){
	memset(hit,0,sizeof(hit));
	for(int nn=0;nn<max_n*max_n*10000;nn++){
		for(int i=0;i<max_n;i++)
			n[i]=i;
		for(int k=0;k<max_n;k++){
			int p=gen()%max_n;
			//int p=gen()%(max_n-k)+k;
			swap(n[k],n[p]);
		}
		for(int i=0;i<max_n;i++){
			hit[i][n[i]]++;
		}
	}
}
int main(){
	/*
	tst();
	for(int i=0;i<max_n;i++){
		for(int j=0;j<max_n;j++){
			printf("%8d",hit[i][j]);
		}
		printf("\n");
	}*/

	int tt;
	int num[1111],pos[1111];
	scanf("%d",&tt);
	for(int cc=1;cc<=tt;cc++){
		int n;
		int y=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
			pos[num[i]]=i;
		}
		for(int i=0;i<n;i++)
			if(pos[i]>i)
				y+=n/2-pos[i];
		if(y>-n)
			printf("Case #%d: GOOD\n",cc);
		else
			printf("Case #%d: BAD\n",cc);
	}
	return 0;
}
