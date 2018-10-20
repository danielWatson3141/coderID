#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib> 
using namespace std;
int n,l;
int daan=1000,res=50;
struct N{
	char c[50];
	bool operator < (const N &now) const
	{
		for (int i=0;i<l;i++)
		{
			if (c[i]==now.c[i]) continue;
			return c[i]<now.c[i];
		}
		return c[0]<now.c[0];
	}
}a[160],b[160],c[160];
bool f[50];
void ST(){
	int p[100][20],prt[100];
	memset(p,-1,sizeof(p));
	for (int i=1;i<=n;i++) p[i][0]=prt[i];
	int k;
	for (int i=1;i<=18;i++)
	 if (n>=(1<<i-1)&&n<(1<<i)) k=i-1;
	for (int j=1;j<=k;j++)
	 for (int i=1;i<=n;i++)
	  if (p[i][j-1]!=-1) p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int a,int b){
	int d[1000],p[100][20];
	if (d[a]<d[b]) {int t=a;a=b;b=t;}
	int k;
	for (int i=1;i<=18;i++)
	 if (d[a]>=(1<<i-1)&&d[a]<(1<<i)) k=i-1;
	for (int i=k;i>=0;i--)
	  if (d[a]-(1<<i)>=d[b]) a=p[a][i];
	if (a==b) return (a);
	for (int i=k;i>=0;i--)
	 if (p[a][i]!=-1&&p[a][i]!=p[b][i])
	   {  a=p[a][i];b=p[b][i];}
    return(p[a][0]);
}
int check(int x){
	memset(f,0,sizeof(f));
	int res=0;
	for (int i=0;i<l;i++)
		if (a[0].c[i]!=b[x].c[i]){
			f[i]=1;res++;
		}
	if (res>daan) return 1000;
	for (int i=0;i<n;i++)
		for (int j=0;j<l;j++){
			if (f[j]==1) c[i].c[j]=b[i].c[j]=='0'?'1':'0';
			else c[i].c[j]=b[i].c[j];
		}
	sort(c,c+n);
	for (int i=0;i<n;i++)
		for (int j=0;j<l;j++)
			if (a[i].c[j]!=c[i].c[j])
				return 1000;
	return res;
}
int main(){
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-attempt0.out","w",stdout);
	int T;
	res++;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		scanf("%d%d",&n,&l);
		for (int i=0;i<n;i++){
			getchar();
			for (int j=0;j<l;j++)
				scanf("%c",&a[i].c[j]);
		}
		for (int i=0;i<n;i++){
			getchar();
			for (int j=0;j<l;j++)
				scanf("%c",&b[i].c[j]);
		}
		sort(a,a+n);
		sort(b,b+n);
		daan=1000;
		for (int i=0;i<n;i++)
			daan=min(daan,check(i));
		printf("Case #%d: ",t);
		if (daan==1000) 
		   printf("NOT POSSIBLE\n");
		else printf("%d\n",daan);
	}
	return 0;
}



