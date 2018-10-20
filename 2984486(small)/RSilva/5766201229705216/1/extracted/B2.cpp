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
			x = dfs(von, u);
			
			tudo[u] += tudo[von];
			prole[u] += tudo[von];
			filho++;
			
			if(x -tudo[von] < low1){
				low2 = low1; low1 = x-tudo[von];
				id2 = id1; id1 = von;
			}
			else if(x -tudo[von] < low2){
				low2 = x-tudo[von];
				id2 = von;
			}
		}
	}
	if(filho == 0) return 0;
	if(filho == 1) return tudo[von];
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
			a = dfs(i, -1);
			res = min(a, res);
		}
		printf("Case #%d: %d\n", inst, res);
	}
	return 0;
}
