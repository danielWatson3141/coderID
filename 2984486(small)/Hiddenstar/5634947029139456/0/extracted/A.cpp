#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<string>
using namespace std;
char st[152][50];
char sr[152][50];
int id[152], id2[152];
int n, l;
int ans = INT_MAX;
/*inline void dfs(int dep, int idc, int cnt){
	if (dep < 1) {
		ans = cnt;
		return ;
	}
	if (ans == cnt) return;
	int s1 = 0, s2 = 0, t1 = 0, t2 = 0;
	int flg = true;
	//not to flip
	flg = true
	for (int i = 1; flg && i <= idc; ++ i){	
		s1 = s2 = t1 = 0;
		for (int j = 1; j <= n; ++ j){
			if (id[j] == i){
				++ t1;
				s1 += (st[j][dep] == '1');
			}
			if (id2[j] == i){
				++ t2;
				s2 += (sr[j][dep] == '1');
			}
		}
		if (s1 != s2 || t1 != t2) flg = false;
	}
	if (flg){
		for (int j = 1; j <= n; ++ j){
			if (id[j] == idc){
				if (st[j][dep] == '1') id[j] = idc + 1;
			}
			if (id2[j] == idc){
				if (sr[j][dep] == '1') id2[j] = idc + 1;
			}
		}
		dfs(dep + 1, idc + 1, cnt);
		for (int j = 1; j <= n; ++ j)
			if jd
	}
	//flip
}*/
char c[200][200];
string sb[200], sd[200];;
inline void work(){
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; ++ i)
		scanf(" %s", st[i] + 1);
	for (int i = 1; i <= n; ++ i)
		scanf(" %s", sr[i] + 1);
	/*for (int i = 1; i <= n; ++ i)
		id[i] = id2[i] = 1;
	dfs(n)*/
	for (int j = 1; j <= n; ++ j)
		sd[j] = string(sr[j] + 1);
	sort(sd + 1, sd + n + 1);
	
	int ans = l + 1;
	for (int i = 1; i <= n; ++ i){
		int cnt = 0;
		for (int k = 1; k <= l; ++ k)
			cnt += (st[1][k] != sr[i][k]);
		for (int j = 1; j <= n; ++ j){
			for (int k = 1; k <= l; ++ k)
				c[j][k] = st[j][k] ^ (st[1][k] != sr[i][k]);
		}
		for (int j = 1; j <= n; ++ j)
			c[j][l + 1] = 0;
		for (int j = 1; j <= n; ++ j)
			sb[j] = string(c[j] + 1);
		sort(sb + 1, sb + n + 1);
		for (int j = 1; j <= n; ++ j)
			if (sb[j] != sd[j]) cnt = l + 1;
		ans = min(ans, cnt);
	}
	if (ans == l + 1) puts("NOT POSSIBLE");
	else printf("%d\n", ans);
}
int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
	int T;scanf("%d", &T);
	for (int cs = 1; cs <= T; ++ cs){
		printf("Case #%d: ", cs);
		work();
	}
}
