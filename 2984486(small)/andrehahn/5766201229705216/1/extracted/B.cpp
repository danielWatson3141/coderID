#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAX 1050

using namespace std;

int N;
int pai[MAX];
vector <int> l[MAX];
int ch[MAX];
int dp[MAX];

int count_children(int x){
	ch[x] = 0;
	for(int i = 0; i < (int)l[x].size(); i++){
		if(l[x][i] != pai[x]){
			pai[l[x][i]] = x;
			ch[x] += count_children(l[x][i]);
		}
	}
	ch[x]++;
	return ch[x];
}

int f(int x){
	if(dp[x] != -1)
		return dp[x];

	int &r = dp[x];
	r = ch[x] - 1; // delete all children

	//or choose 2 children
	int cnt = 0;
	for(int i = 0; i < (int)l[x].size(); i++)
		if(l[x][i] != pai[x]) cnt++;
	if(cnt < 2)
		return r;
	for(int i = 0; i < (int)l[x].size(); i++)
		for(int j = i + 1; j < (int)l[x].size(); j++){
			if(l[x][i] == pai[x] || l[x][j] == pai[x]) continue;
			int del = ch[x] - 1 - ch[l[x][i]] - ch[l[x][j]];
			del += f(l[x][i]);
			del += f(l[x][j]);
			if(del < r)
				r = del;
		}

	return r;
}




int testa(int root){
	for(int i = 0; i < MAX; i++)
		dp[i] = pai[i] = ch[i] = -1;

	int r = N-1;
	count_children(root);
	r = f(root);

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

		int r = MAX;
		for(int i = 0; i < N; i++)
			r = min(r, testa(i));

		printf("%d\n", r);
	}
	return 0;
}
