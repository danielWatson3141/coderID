#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main() {
	int T,N;
	int i,j,k;
	scanf("%d",&T);
	for(i=1;i<=T;i++) {
		scanf("%d",&N);
		while(N--) {
			scanf("%d",&j);
		}
		if(i%2==0)
			printf("Case #%d: GOOD\n",i);
		else
			printf("Case #%d: BAD\n",i);
	}
	return 0;
}
