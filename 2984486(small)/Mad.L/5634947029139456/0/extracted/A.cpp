#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

int ans,n,l,Cas;
int c[1000],b[1000],a[1000];

int getnum(){
	int ret = 0,i;
	char s[100];
	scanf("%s",s);
	for(i = 0;i < l;i++)
		if (s[i] == '1') 
			ret += 1<<i;
	return ret; 
}

int OK(int aa[],int bb[]){
	int i;
	for(i = 1;i <= n;i++)
		if (aa[i] != bb[i])
			return 0;
	return 1;
}

void dfs(int k,int t){
	int i;
	if (k > l){
		for(i = 1;i <= n;i++)
			c[i] = a[i];
		sort(c+1,c+n+1);
		if (OK(c,b) && ans > t)
			ans = t;
	}else{
		dfs(k+1,t);
		for(i = 1;i <= n;i++)
			a[i] ^= (1<<(k-1));
		dfs(k+1,t+1);
	}
}

int Work(){
	int i,j;
	ans = 1000;
	scanf("%d%d",&n,&l);
	for(i = 1;i <= n;i++)
		a[i] = getnum();
	for(j = 1;j <= n;j++)
		b[j] = getnum();
	sort(b+1,b+n+1);
	//for(i = 1;i <= n;i++)
	//	printf("%d %d\n",a[i],b[i]);
	dfs(1,0);
	printf("Case #%d: ",Cas);
	if (ans == 1000)
		printf("NOT POSSIBLE\n");
	else printf("%d\n",ans);
	return 0;
}

int main(){
	int T;
	freopen("xx.in","r",stdin);
	freopen("xx.out","w",stdout);
	scanf("%d",&T);
	for(Cas = 1;Cas <= T;Cas++)
		Work();
	return 0;
}