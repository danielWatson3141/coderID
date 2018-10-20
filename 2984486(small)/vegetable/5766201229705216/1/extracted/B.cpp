#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;
vector<int> g[1010];
int f[1010], Q[1010], h[1010];
int N;	

int getAns(int x){
	memset(h, 0, sizeof(h));	
	h[x] = 1; f[x] = -1;
	int H = 0, T = 0;
	Q[0] = x;
	while (H <= T){
		int cur = Q[H];
		for (int j = 0; j < g[cur].size(); j ++)
			if (!h[g[cur][j]]){ 
				Q[++T] = g[cur][j];
				h[g[cur][j]] = 1; 
			}
		H ++;	
	}
	memset(h, 0, sizeof(h));
	for (int i = N - 1; i >= 0; i --){
		int cur = Q[i];
		int max1 = 0, max2 = 0;
		h[cur] = 1;
		for (int j = 0; j < g[cur].size(); j ++){
			int nxt = g[cur][j]; 
			if (!h[nxt]) continue;	
			if (f[nxt] >= max1){
				max2 = max1; max1= f[nxt];	
			}else if (f[nxt] > max2) max2 = f[nxt];
		}	
		if (max2 == 0) f[cur] = 1;
			else f[cur] = max1 + max2 + 1;
	}
	return N - f[x];
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i ++){
		scanf("%d", &N);
		for (int j = 0; j < N; j ++)
			g[j].clear();
		for (int j = 0; j < N - 1; j ++){
			int x, y;
			scanf("%d%d", &x, &y);	
			x --; y --;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans = N;
		for (int j = 0; j < N; j ++){
			int tmp = getAns(j);		
			if (tmp < ans) ans = tmp;
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
}

