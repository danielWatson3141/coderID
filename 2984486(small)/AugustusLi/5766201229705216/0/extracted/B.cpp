#include<iostream>

using namespace std;

const int N= 1004;
const int INF= 0x3fffffff;

bool mk[N];
int ed[N][N];
int child[N];

void addEdge(int u, int v){
	int t= ++ed[u][0];
	ed[u][t]= v;
	t= ++ed[v][0];
	ed[v][t]= u;
}

void clearEdges(int n){
	for(int i= 1; i <= n; i++)
		ed[i][0]= 0;
}

int search(int n, int u, int r){
	int sum= 0;
	int max2[2];
	int ind2[2];
	int cnt= 0;
	for(int i= 1; i <= ed[u][0]; i++){
		int v= ed[u][i];
		if(v == r) continue;
		else cnt++;
	}
	if(cnt < 2) return 1;
	for(int i= 1; i <= ed[u][0]; i++){
		int v= ed[u][i];
		if(v == r) continue;
		else child[i]= search(n, v, u);
	}
	max2[0]= 0;
	for(int i= 1; i <= ed[u][0]; i++){
		int v= ed[u][i];
		if(v == r) continue;
		if(child[i] > max2[0]){
			max2[0]= child[i];
			ind2[0]= i;
		}
	}
	max2[1]= 0;
	for(int i= 1; i <= ed[u][0]; i++){
		int v= ed[u][i];
		if(v == r) continue;
		if(i == ind2[0]) continue;
		if(child[i] < max2[1]) continue;
		max2[1]= child[i];
		ind2[1]= i;
	}
	mk[ed[u][ind2[0]]]= true; 
	mk[ed[u][ind2[1]]]= true;
	return sum= 1+max2[0]+max2[1];
}


int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int cas= 1; cas <= t; cas++){
		int n, m;
		scanf("%d", &n);
		m= n-1;
		clearEdges(n);
		
		for(int i= 1; i <= m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(u, v);
		}
		int maxx= 0;
		for(int i= 1; i <= n; i++){
			memset(mk, 0, sizeof(mk));
			mk[i]= true;
			search(n, i, -1);
			int cnt= 0;
			for(int j= 1; j <= n; j++)
				if(mk[j]) cnt++;
			if(cnt > maxx)
				maxx= cnt;
		}
		printf("Case #%d: %d\n", cas, n-maxx);
	}

	return 0;
}