#include<cstdlib>
#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>
#define V_MAX 1010
using namespace std;
typedef pair<int, int> pp;

vector<int> gra[V_MAX];
int V;

pp dfs(int v, int pre){
	int all = 1, cut = 0;
	for(int i = 0; i < gra[v].size(); i++){
		if(gra[v][i] != pre){
			pp tmp = dfs(gra[v][i], v);
			all += tmp.first;
			cut += tmp.second;
		}
	}
	if(pre == -1){
		if(gra[v].size() != 2) return make_pair(all, all - 1);
		else return make_pair(all, cut);
	} else if(gra[v].size() != 3) return make_pair(all, all - 1);
	else return make_pair(all, cut);
}

int main(){
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("pB_sm.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cnt = 1; cnt <= T; cnt++){
		printf("Case #%d: ", cnt);
		for(int i = 0; i < V_MAX; i++) gra[i].clear();
		scanf("%d", &V);
		for(int i = 0; i < V - 1; i++){
			int st, ed;
			scanf("%d%d", &st, &ed);
			gra[st].push_back(ed);
			gra[ed].push_back(st);
		}
		int ans = 7122;
		for(int i = 1; i <= V; i++) ans = min(dfs(i, -1).second, ans);
		printf("%d\n", ans);
	}
	return 0;
}
