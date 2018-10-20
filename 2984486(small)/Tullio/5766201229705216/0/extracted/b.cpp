#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define pii pair<int,int>
#define f first
#define s second
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define db if(1)
#define pb push_back

typedef long long ll;

int n, res;
vector<int> adj[1010];

bool read(){
    if(scanf("%d", &n) == EOF) return false;
	rep(i, n) adj[i].clear();
	
	rep(i, n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
    return true;
}

int cn = 1;

int size(int v, int p) {
	//printf("size: %d %d\n", v, p);
	int cont = 1;
	rep(i, adj[v].size()) {
		if (adj[v][i] != p) {
			cont += size(adj[v][i], v);
		}
	}
	return cont;
}

int search(int v, int p) {
	//printf("search: %d %d\n", v, p);
	int cont = adj[v].size();
	if (p != -1) --cont;
	//printf("%d\n", cont);
	if (cont == 0) {
		return 0;
	}
	if (cont == 1) {
		if (adj[v][0] == p) {
			return size(adj[v][1], v);
		} else {
			return size(adj[v][0], v);
		}
	}
	if (cont == 2) {
		cont = 0;
		rep(i, adj[v].size()) {
			if (adj[v][i] != p) {
				cont += search(adj[v][i], v);
			}
		}
		return cont;
	}
	
	vector<pii> aux;
	rep(i, adj[v].size()) {
		if (adj[v][i] != p) {
			aux.pb(pii(size(adj[v][i], v), adj[v][i]));
		}
	}
	sort(aux.begin(), aux.end());

	cont = 0;
	fr(i, 0, aux.size()-2) {
		cont += aux[i].f;
	}
	cont += search(aux[aux.size()-1].s, v);
	cont += search(aux[aux.size()-2].s, v);
	return cont;
}

void process(){
	res = n;
	rep(i, n) {
		res = min(res, search(i, -1));
	}
	
	
	printf("Case #%d: %d\n", cn++, res);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
