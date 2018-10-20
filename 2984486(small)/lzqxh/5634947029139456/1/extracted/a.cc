//By Lin
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<cctype>
#include<cmath>

#define eps 1e-9
#define sqr(x) ((x)*(x))
#define Rep(i,n) for(int i = 0; i<n; i++)
#define foreach(i,n) for( __typeof(n.begin()) i = n.begin(); i!=n.end(); i++)
#define X first
#define Y second
#define mp(x,y) make_pair(x,y)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define N 100010

int n, L;
LL data[3][160];
char str[50];
bool check(int &x, int y) {
	if (x == -1 || x > y) x = y;
}
int count(LL x) {
	int ret = 0;
	while (x) {
		ret += x & 1ll;
		x >>= 1;
	}
	return ret;
}

int		main(){
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d%d", &n, &L);
		Rep(k, 2) Rep(i, n) {
			scanf("%s", str);
			data[k][i] = 0;
			Rep(j, L) if (str[j] == '1') data[k][i] ^= 1ll<<j;
		}
		sort(data[1], data[1] + n);
		int ans = -1;
		Rep(i, n) 
			Rep(j, n) {
				LL tmp = data[0][i] ^ data[1][j];
				if (ans != -1 && count(tmp) >= ans) continue;
				Rep(k, n) {
					data[2][k] = data[0][k] ^ tmp;
				}
				sort(data[2], data[2] + n);
				bool flag = true;
				Rep(k, n) 
					if (data[2][k] != data[1][k]) flag = false;
				if (flag) check(ans, count(tmp));
			}
		printf("Case #%d: ", ++tt);
		if (ans == -1) puts("NOT POSSIBLE");
		else printf("%d\n", ans);

	}
	return 0;
}
