#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct A{
	char ss[15];
	int s;
	void read(int len){
		scanf(" %s",ss);
		s = 0;
		for(int i=0;i<len;i++)
			if(ss[i]=='1')
				s |= (1<<i);
	}
}AA;
AA a[12],b[12];
int c[12],is[12];

bool cmp(AA cc,AA dd){
	return cc.s < dd.s;
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	scanf(" %d",&T);
	for(int t=0;t<T;t++){
		int N,L;
		scanf(" %d %d",&N,&L);
		for(int i=0;i<N;i++)
			a[i].read(L);
		for(int i=0;i<N;i++)
			b[i].read(L);
		sort(b,b+N,cmp);
		/*for(int i=0;i<N;i++){
			printf("%d %d\n",a[i].s,b[i].s);
		}*/
		int mask = (1<<L),ans = 1005;
		for(int i=0;i<mask;i++){
			//printf("-----------\n");
			//printf("i = %d\n",i);
			for(int j=0;j<N;j++){
				c[j] = a[j].s;
				for(int k=0;k<L;k++){
					if((i & (1<<k)) > 0)
						c[j] ^= (1<<k);
				}
				is[j] = 0;
			}
			sort(c,c+N);
			/*printf("---\n");
			for(int j=0;j<N;j++)
				printf("%d ",c[j]);
			printf("\n");*/
			int re = 1;
			for(int j=0;j<N;j++)
				if(c[j]!=b[j].s)
					re = 0;
			if(re==1){
				int tmp = 0;
				for(int j=0;j<L;j++)
					if((i & (1<<j)) > 0)
						tmp++;
				ans = min(ans,tmp);
			}
		}
		if(ans==1005)	printf("Case #%d: NOT POSSIBLE\n",t+1);
		else	printf("Case #%d: %d\n",t+1,ans);
	}
    
    return 0;
}