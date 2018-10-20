#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAX 1010

using namespace std;

int N;
int pai[MAX];
vector <int> l[MAX];
int vis[MAX];

int dfs(int x, int mask){
	vis[x] = 1;
	int cnt = 0;
	int r = 1;
	for(int i = 0; i < (int)l[x].size(); i++)
		if(vis[l[x][i]] == -1 && (mask & (1<<l[x][i]))){
			r = min(r, dfs(l[x][i], mask));
			cnt++;
		}
	if(cnt != 0 && cnt != 2) r = 0;
	return r;
}

int testa(int mask){
	int r = 99;
	for(int k = 0; k < N; k++){
		int tmp = 0;
		for(int i = 0; i < N; i++){
			pai[i] = vis[i] = -1;
			if(((1<<i) & mask) == 0)
				tmp++;
		}
		if((mask & (1<<k)) == 0) continue;
		int a = dfs(k, mask);
		for(int i = 0; i < N; i++)
			if(vis[i] == -1 && ((1<<i)&mask) > 0)
				tmp = 99;
		if(a == 0) tmp = 99;
		r = min(r, tmp);
	}
	return r;
}


int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);

		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			l[i].clear();

		for(int i = 0; i < N-1; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			x--; y--;
			l[x].push_back(y);
			l[y].push_back(x);
		}

		int r = 99;
		for(int i = 1; i < (1<<N); i++)
			r = min(r, testa(i));

		printf("%d\n", r);
	}
	return 0;
}
