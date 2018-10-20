#include<stdio.h>
#include<algorithm>
using namespace std;
char c[200][100];
char d[200][100];
long long e[200];
long long f[200];
int val[100];
int ans[100];
long long s[100];
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)scanf("%s",c[i]);
		for(int i=0;i<a;i++)scanf("%s",d[i]);
		for(int i=0;i<a;i++){
			e[i]=f[i]=0LL;
			for(int j=0;j<b;j++){
				e[i]*=2;
				if(c[i][j]=='1')e[i]++;
				f[i]*=2;
				if(d[i][j]=='1')f[i]++;
			}
		}
		std::sort(e,e+a);
		std::sort(f,f+a);
		int ret=99999999;
		for(int i=0;i<(1<<b);i++){
			for(int j=0;j<a;j++){
				s[j]=e[j]^i;
			}
			std::sort(s,s+a);
			bool ok=true;
			for(int j=0;j<a;j++)if(s[j]!=f[j])ok=false;
			if(ok){
				ret=min(ret,__builtin_popcount(i));
			}
		}
		printf("Case #%d: ",t+1);
		if(ret==99999999)printf("NOT POSSIBLE\n");
		else printf("%d\n",ret);
	}
}