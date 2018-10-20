#include<stdio.h> 
#include<stdlib.h>
#include<algorithm>
using namespace std; 
int n,l;
struct sss{
	char cc[50];
};
int cmp(const sss &a,const sss& b){
	int i;
	for(i=0;i<l;i++){
	  if(a.cc[i]<b.cc[i]) return 1;
	  else if(a.cc[i]>b.cc[i]) return 0;
	}
	return 0;
}
int ok;
void dfs(int now,sss a[],sss b[],int c){
	int i,j;
	if(now==l){
	/*	printf("dd%d\n",c);
		for(i=0;i<n;i++)
		  printf("%s\n",a[i].cc);
		printf("\n");
		for(i=0;i<n;i++)
		  printf("%s\n",b[i].cc);
		printf("\n");   */
		sort(a,a+n,cmp);
		for(i=0;i<n;i++)
		   for(j=0;j<l;j++)
		     if(a[i].cc[j]!=b[i].cc[j])  
		       return ;
		if(ok>c) ok=c;
		return ;
	}
	sss aa[150];
	for(i=0;i<n;i++)
	  for(j=0;j<l;j++)
	    aa[i].cc[j]=a[i].cc[j];
	for(i=0;i<n;i++){
		aa[i].cc[now]='1'-a[i].cc[now]+'0';
	//	printf("[%s]",aa[i].cc);
	}
	    
	dfs(now+1,aa,b,c+1);    
	for(i=0;i<n;i++)
	  for(j=0;j<l;j++)
	    aa[i].cc[j]=a[i].cc[j];
	for(i=0;i<n;i++)
	    aa[i].cc[now]=a[i].cc[now];
	dfs(now+1,aa,b,c);
} 
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		scanf("%d %d",&n,&l);
		sss a[150],b[150];
		int i;
		for(i=0;i<n;i++)
		  scanf("%s",a[i].cc);
		for(i=0;i<n;i++)
		  scanf("%s",b[i].cc);
		sort(b,b+n,cmp);
		ok=1000;
		dfs(0,a,b,0);
		if(ok==1000) printf("Case #%d: NOT POSSIBLE\n",hh);
		else printf("Case #%d: %d\n",hh,ok);
	}
	return 0;
}
