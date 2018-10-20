#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define FOR(i,l,r) for(int i=l; i<=r; i++)
#define N 121
typedef long long LL;
int T,n,l;
LL a[N],b[N];
int use[N];
LL val(){
	LL ret = 0; char s[N];
	scanf("%s",s);
	FOR(i,0,l-1) if(s[i] == '1') 
		ret += 1<<(l-i-1);
	return ret;
}
bool check(){
	sort(b+1,b+n+1);
	FOR(i,1,n) if(a[i] != b[i]) return false;
	return true;
}
int calc(int x){
	int ret = 0;
	while(x != 0){
		if( (x&1) == 1 ) ret++;
		x >>= 1;
	}
	return ret;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	FOR(cas,1,T){
		scanf("%d%d",&n,&l);
		FOR(i,1,n) a[i] = val();
		FOR(i,1,n) b[i] = val();
		sort(a+1,a+n+1);
		int ans = 100;
		FOR(i,0,(1<<l)-1)
		if(calc(i) < ans){
			FOR(j,1,n) b[j] ^= i;
			if(check()) ans = min(ans, calc(i));
			FOR(j,1,n) b[j] ^= i;
		}
		printf("Case #%d: ",cas);
		if(ans != 100) printf("%d\n",ans);
		else puts("NOT POSSIBLE");
	}
	return 0;
}
