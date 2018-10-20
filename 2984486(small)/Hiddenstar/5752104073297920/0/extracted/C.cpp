#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<vector>
using namespace std;
typedef long long LL;
pair<LL, int> pd[12000];
int d[12000];
int ans[12000];
int n;
int main(){
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
	int T;scanf("%d", &T);
	for (int cs = 1; cs <= T; ++ cs){
		LL mst = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i)
			scanf("%d", &d[i]);
		for (int i = 0; i < n; ++ i){
			if (i != d[i])
				mst += n - d[i];
			else
				mst += d[i];
			//printf("%d,%d ", d[i] - i, d[i]);
		}
		pd[cs] = make_pair(mst, cs);
		//printf("%d\n", mst);
	}
	sort(pd + 1, pd + T + 1);
	for (int i = 1; i <= T / 2; ++ i)
		ans[pd[i].second] = true;
	for (int i = 1; i <= T; ++ i)
		printf(ans[i] ? "Case #%d: GOOD\n" : "Case #%d: BAD\n", i);
}
