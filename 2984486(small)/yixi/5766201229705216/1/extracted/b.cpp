#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int TT,n,d[2000],b[2000][2000],c[2000][2000],a[2000][2000],e[2000],num[2000],cost[2000],x,y,best,cnt;
bool v[2000];


void check(int x){
	v[x]=true;
	num[x]=1;
	cost[x]=0;
	int numc=0;
	for (int j=0; j<e[x]; j++){
		int y = a[x][j];
		if (v[y]) continue;
		check(y);
		b[x][numc]=num[y];
		c[x][numc]=cost[y];
		cost[x]+=cost[y];
		num[x]+=num[y];
		numc++;
		
	}
	if (numc==1){
		cost[x]=num[x]-1;
	}else if (numc>2){
		for (int j=0; j<numc; j++){
			d[j]=c[x][j]-b[x][j];
		}
		sort(d,d+numc);
		cost[x]=num[x]-1;
		for (int j=0; j<2; j++)
			cost[x]+=d[j];
	}
}


int main(){
	scanf("%d",&TT);
	for (int TTT=1; TTT<=TT; TTT++){
		printf("Case #%d: ",TTT);
		scanf("%d",&n);
		for (int i=0; i<n; i++) e[i]=0;
		for (int i=1; i<n; i++){
			scanf("%d%d",&x,&y);
			x--; y--;
			a[x][e[x]]=y; e[x]++;
			a[y][e[y]]=x; e[y]++;
		}
		
		best = n;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++) v[j]=false;
			check(i);
			cnt=cost[i];
			if (cnt<best) best=cnt;
			//cout <<i<<" "<<cnt<<endl;
		}
		printf("%d\n",best);
	}
}