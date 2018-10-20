#include<stdio.h>
#include<algorithm>

using namespace std;

#define MAX 200

FILE *input=freopen("input.txt","r",stdin);
FILE *output=freopen("output.txt","w",stdout);

struct xy{
	char st[MAX];
	int gp;
}a[MAX],b[MAX];

bool sort_xy(xy a,xy b){
	if(a.gp>b.gp)
		return 1;
	return 0;
}

int n,l;

int mini=-1;

void dfs(int w,int cnt,int k){
	if(w==l)
	{
		if(mini==-1||mini>cnt)
			mini=cnt;
		return;
	}
	int i;
	bool flag;
	for(i=0;i<n;i++){
		a[i].gp+=(a[i].st[w]-'0')*k;
		b[i].gp+=(b[i].st[w]-'0')*k;
	}
	sort(a,a+n,sort_xy);
	sort(b,b+n,sort_xy);
	flag=1;
	for(i=0;i<n;i++){
		if(a[i].gp!=b[i].gp)
			flag=0;
	}
	if(flag){
		dfs(w+1,cnt,k*2);
	}
	for(i=0;i<n;i++){
		a[i].gp-=(a[i].st[w]-'0')*k;
		b[i].gp-=(b[i].st[w]-'0')*k;
	}
	for(i=0;i<n;i++){
		if(a[i].st[w]=='0')
			a[i].st[w]='1';
		else if(a[i].st[w]=='1')
			a[i].st[w]='0';
	}
	for(i=0;i<n;i++){
		a[i].gp+=(a[i].st[w]-'0')*k;
		b[i].gp+=(b[i].st[w]-'0')*k;
	}
	sort(a,a+n,sort_xy);
	sort(b,b+n,sort_xy);
	flag=1;
	for(i=0;i<n;i++){
		if(a[i].gp!=b[i].gp)
			flag=0;
	}
	if(flag){
		dfs(w+1,cnt+1,k*2);
	}
	
	for(i=0;i<n;i++){
		a[i].gp-=(a[i].st[w]-'0')*k;
		b[i].gp-=(b[i].st[w]-'0')*k;
	}
	for(i=0;i<n;i++){
		if(a[i].st[w]=='0')
			a[i].st[w]='1';
		else if(a[i].st[w]=='1')
			a[i].st[w]='0';
	}
}

int main(){
	int T;

	int i,j;
	int tc=1;

	scanf("%d",&T);

	for(;T>0;T--){
		scanf("%d%d",&n,&l);
		for(i=0;i<n;i++){
			for(j=0;j<l;j++){
				scanf(" %c",&a[i].st[j]);
			}
			a[i].gp=0;
		}
		for(i=0;i<n;i++){
			for(j=0;j<l;j++){
				scanf(" %c",&b[i].st[j]);
			}
			b[i].gp=0;
		}
		mini=-1;
		dfs(0,0,1);
		printf("Case #%d: ",tc++);
		if(mini==-1){
			printf("NOT POSSIBLE\n");
		}
		else
			printf("%d\n",mini);
		for(i=0;i<n;i++){
			for(j=0;j<l;j++){
				a[i].st[j]=0;
				a[i].gp=0;
				b[i].st[j]=0;
				b[i].gp=0;
			}
		}
	}
	return 0;
}