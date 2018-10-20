#include<stdio.h>
#include<algorithm>
using namespace std;
char c[200][100];
char d[200][100];
long long e[200];
long long f[200];
int val[200];
int ans[200];
long long s[200];
long long t[200];
int ret=99999999;
int n,m;
void solve(int a,long long now){
	if(a==m){
		ret=min(ret,__builtin_popcountll(now));
		return;
	}
	for(int i=0;i<n;i++)s[i]=(e[i]^now)%(1LL<<(a+1));
	for(int i=0;i<n;i++)t[i]=f[i]%(1LL<<(a+1));
	std::sort(s,s+n);std::sort(t,t+n);
	bool ok=true;
	for(int i=0;i<n;i++)if(s[i]!=t[i])ok=false;
	if(ok)solve(a+1,now);
	
	for(int i=0;i<n;i++)s[i]=(e[i]^(now+(1LL<<a)))%(1LL<<(a+1));
	for(int i=0;i<n;i++)t[i]=f[i]%(1LL<<(a+1));
	std::sort(s,s+n);std::sort(t,t+n);
	ok=true;
	for(int i=0;i<n;i++)if(s[i]!=t[i])ok=false;
	if(ok)solve(a+1,now+(1LL<<a));
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		int a,b;
		
		scanf("%d%d",&a,&b);
		n=a;m=b;
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
		ret=99999999;
		solve(0,0);

		printf("Case #%d: ",t+1);
		if(ret==99999999)printf("NOT POSSIBLE\n");
		else printf("%d\n",ret);
	}
}