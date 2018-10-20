#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10000
typedef long long LL;
int t;
int n, l;
char a[155][44];
char b[155][44];
int sumb[155];
int suma[155];
int f[155];
int ca[155];
int cb[155];
int cc[155];
int ans;
void res(int x){
	for(int i = 0; i < n; i++){
		ca[i] ^= (1 << x);
	}
}
void dfs(int c, int sum){
	if(c == l){
		for(int i = 0; i < n; i++){
			cc[i] = ca[i];
		}
		sort(cc, cc + n);
		int ff = 0;
		for(int i = 0; i < n; i++){
			if(cc[i] != cb[i]){
				ff = 1;
				break;
			}
		}
		if(ff)return ;
		if(sum < ans)ans = sum;
		return ;
	}
	if(suma[c] != sumb[c]){
		res(c);
		dfs(c + 1, sum + 1);
		res(c);
	}
	else {
		if((suma[c] << 1) == n){
			dfs(c + 1, sum);
			res(c);
			dfs(c + 1, sum + 1);
			res(c);
		}
		else {
			dfs(c + 1, sum);
		}
	}


}
int main(){
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
	scanf("%d", &t);
	int num = 1;
	while(t--){
		ans = 10000;
		scanf("%d%d", &n, &l);
		memset(suma, 0, sizeof(suma));
		for(int i = 0; i < n; i++){
			scanf("%s", a[i]);
			for(int j = 0; j < l; j++){
				suma[j] += (a[i][j] - '0');
			}
		}
		memset(sumb, 0, sizeof(sumb));
		for(int i = 0; i < n; i++){
			scanf("%s", b[i]);
			for(int j = 0; j < l; j++){
				sumb[j] += (b[i][j] - '0');
			}
		}
		int flag = 0;
		for(int i = 0; i < l; i++){
			if(suma[i] != sumb[i] && suma[i] + sumb[i] != n){
				flag = 1;break;
			}
		}
		printf("Case #%d: ", num++);
		if(flag){
			printf("NOT POSSIBLE\n");
			continue;
		}
		memset(ca, 0, sizeof(ca));
		memset(cb, 0, sizeof(cb));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < l; j++){
				ca[i] |= ((a[i][j] - '0') << j);
				cb[i] |= ((b[i][j] - '0') << j);
			}
		}
		sort(cb, cb + n);
		dfs(0, 0);
		if(ans == 10000)printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
