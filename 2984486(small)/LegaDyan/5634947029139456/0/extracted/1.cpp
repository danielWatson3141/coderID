#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,l;
int ans=1000;
struct N{
	char c[50];
	bool operator < (const N &now) const{
		for (int i=0;i<l;i++){
			if (c[i]==now.c[i]) continue;
			return c[i]<now.c[i];
		}
		return c[0]<now.c[0];
	}
}a[160],b[160],c[160];
bool f[50];
int check(int x){
	memset(f,0,sizeof(f));
	int res=0;
	for (int i=0;i<l;i++)
		if (a[0].c[i]!=b[x].c[i]){
			f[i]=1;res++;
		}
	if (res>ans) return 1000;
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
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
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
		ans=1000;
		for (int i=0;i<n;i++)
			ans=min(ans,check(i));
		printf("Case #%d: ",t);
		if (ans==1000) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}
