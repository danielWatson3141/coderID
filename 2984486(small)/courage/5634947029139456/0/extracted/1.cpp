#include <cstdio>
#include <cstring>
#include <algorithm>
int te,n,l,x,ans;
bool flag;
struct rec{char s[50];};
rec s[160],t[160];
bool cmp(rec a,rec b){
	return strcmp(a.s,b.s) < 0;
}
void change(int x){
	for (int i = 1;i <= n;i++) t[i].s[x] = '0' + '1' - t[i].s[x];
}
int f(int x){
	int ans = 0;
	while (x){
		ans += (x & 1);
		x >>= 1;
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&te);
	for (int T = 1;T <= te;T++){
		scanf("%d%d",&n,&l);
		for (int i = 1;i <= n;i++) scanf("%s",s[i].s);
		for (int i = 1;i <= n;i++) scanf("%s",t[i].s);
		std::sort(s + 1,s + n + 1,cmp);
		ans = 1e6;
		flag = 0;
		for (int i = 0;i < (1 << l);i++){
			for (int j = 0;j < l;j++) if ((i >> j) & 1) change(j);
			std::sort(t + 1,t + n + 1,cmp);
			bool p = 1;
			for (int j = 1;j <= n;j++) if (strcmp(s[j].s,t[j].s) != 0) p = 0;
			if (p && f(i) < ans){
				ans = f(i);
				flag = 1;
			}
			for (int j = 0;j < l;j++) if ((i >> j) & 1) change(j);
		}
		printf("Case #%d: ",T);
		if (flag) printf("%d\n",ans);else printf("NOT POSSIBLE\n");
	}
}
