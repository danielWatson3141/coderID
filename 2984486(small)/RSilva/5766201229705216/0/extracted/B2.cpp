#include<cstdio>
#include<algorithm>
#include<vector>

#define MAX 1024
#define INF 1<<28

using namespace std;
int n, res, casos, tudo[MAX], prole[MAX];
vector <int> ar[MAX];
int cnt;

int dfs(int u, int pai){
	int x, filho, low1, id1, low2, id2, von;
	
	prole[u] = 0;
	filho = 0;
	low1 = low2 = 1;
	id1 = id2 = n;
	tudo[u] = 1;
	for(int i=0;i<ar[u].size();i++){
		if(ar[u][i] != pai){
			von = ar[u][i];
			x = dfs(ar[u][i], u);
			
			tudo[u] += tudo[ar[u][i]];
			prole[u] += tudo[ar[u][i]];
			filho++;
			
			if(x -tudo[ar[u][i]] < low1){
				low2 = low1; low1 = x-tudo[ar[u][i]];
				id2 = id1; id1 = ar[u][i];
			}
			else if(x -tudo[ar[u][i]] < low2){
				low2 = x-tudo[ar[u][i]];
				id2 = ar[u][i];
			}
		}
	}
	if(cnt){
		printf("%d -> %d tem %d filhos retorna ", pai, u, filho);
		if(filho == 0) printf("0\n");
		if(filho == 1) printf("tudo[%d] = %d\n", von, tudo[von]);
		if(filho>=2) printf("%d +%d +%d = %d\n", prole[u], low1, low2, prole[u]+low1+low2);
	}
	if(filho == 0) return 0;
	if(filho == 1) return tudo[von];
	// if(filho == 2) return ;
	//filho > 2
	return prole[u] +low1 +low2;
}

int main(){
	int a, b;
	cnt = 0;
	scanf(" %d", &casos);
	for(int inst=1;inst<=casos;inst++){
		scanf(" %d", &n);
		for(int i=0;i<n;i++){
			tudo[i] = prole[i] = 0;
			ar[i].clear();
		}
		for(int i=0;i<n-1;i++){
			scanf(" %d %d", &a, &b); a--; b--;
			ar[a].push_back(b); ar[b].push_back(a);
		}
		
		res = INF;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) tudo[j] = prole[j] = 0;
			
			// if(inst == 2 && i == 1) cnt = 1;
			// else cnt = 0;
			
			a = dfs(i, -1);
			// printf("%d DFS -> %d\n", i, a);
			res = min(a, res);
		}
		printf("Case #%d: %d\n", inst, res);
		// while(1);
	}
	return 0;
}
