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
	char ss[45];
	long long s;
	void read(int len){
		scanf(" %s",ss);
		s = 0;
		for(int i=0;i<len;i++)
			if(ss[i]=='1')
				s |= (1<<i);
	}
}AA;
AA a[45],b[45];
long long c[45],d[45];

bool cmp(AA cc,AA dd){
	return cc.s < dd.s;
}
long long get_mask(int i,int j,int L){
	long long ret = 0;
	for(int k=0;k<L;k++)
		if(a[i].ss[k]!=b[j].ss[k])
			ret |= ((long long)1<<k);
	return ret;
}

int main()
{
    freopen("A-large.in","r",stdin);
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
		int ans = 1005;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				long long mk = get_mask(i,j,L);
				for(int k=0;k<N;k++)
					c[k] = a[k].s, d[k] = b[k].s;
				for(int k=0;k<N;k++)
					c[k] ^= mk;
				sort(c,c+N);
				sort(d,d+N);
				int re = 1;
				for(int k=0;k<N;k++)
					if(c[k]!=d[k])
						re = 0;
				if(re==1){
					int tmp = 0;
					for(int k=0;k<L;k++)
						if((mk & ((long long)1<<k)) > 0)
							tmp++;
					ans = min(ans,tmp);
				}
			}
		}
		if(ans==1005)	printf("Case #%d: NOT POSSIBLE\n",t+1);
		else	printf("Case #%d: %d\n",t+1,ans);
	}
    
    return 0;
}