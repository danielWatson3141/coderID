#include<stdio.h>
#include<algorithm>
//#define DEBUG
#ifdef DEBUG
#define CASET printf("Case #%d: \n",T)
#define eprintf(...) printf(__VA_ARGS__)
#else
#define CASET printf("Case #%d: ",T)
#define eprintf(...) 
#endif
int adj[1001][1001],cnt[1001],used[1001],sum[1001];
void stat(int p){
	int i,j,k,deg=0;
	for(i=0;i<cnt[p];i++){
		int to=adj[p][i];
		if(!used[to]){
			used[to]=1;
			stat(to);
			sum[p]+=sum[to];
			used[to]=0;
		}
	}
	sum[p]++;
}
int go(int p){
	int i,j,k=0,deg=0,r[1001],z[1001],zr[1001];
	for(i=0;i<cnt[p];i++){
		int to=adj[p][i];
		if(!used[to]){
			used[to]=1;
			z[deg]=go(to);
			r[deg]=sum[to];
			zr[deg]=z[deg]-r[deg];
			deg++;
			used[to]=0;
		}
	}
	if(!deg)return 0;
	else if(deg==1)return r[0];
	else if(deg==2)return z[0]+z[1];
	
	std::sort(zr,zr+deg);
	k=0;
	for(i=0;i<deg;i++)
		k+=r[i];
	k+=zr[0]+zr[1];
	return k;
}
int solve(){
	int i,j,k;
	int n,m;
	int ret=1000000;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cnt[i]=0;
	}
	m=n-1;
	for(i=0;i<m;i++){
		scanf("%d%d",&j,&k);
		j--;
		k--;
		adj[j][cnt[j]++]=k;
		adj[k][cnt[k]++]=j;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)used[j]=sum[j]=0;
		used[i]=1;
		stat(i);
		k=go(i);
		eprintf("Root: %d, ans: %d\n",k);
		if(ret>k)ret=k;
	}
	return ret;
	
}
int main(){
	int T,TN=1000000;
#ifndef DEBUG
	scanf("%d",&TN);
#endif
	for(T=1;T<=TN;T++){
		CASET;
		int k=solve();
		if(k==-1){
			puts("NOT POSSIBLE");
		} else {
			printf("%d\n",k);
		}
	}
}
