#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
using namespace std;

#define rep(i,N) for((i) = 0; (i) < (N); (i)++)
#define rab(i,a,b) for((i) = (a); (i) <= (b); (i)++)
#define Fi(N) rep(i,N)
#define Fj(N) rep(j,N)
#define Fk(N) rep(k,N)
#define sz(v) (v).size()
#define all(v) (v).begin(),(v).end()

vector <int> edges[1000];
bool visited[1000];
bool av[1000];
int deg[1000];
int idx;
int N;

bool dfs(int u) {
	int i,v;

	visited[u] = true;
	deg[u] = 0;
	//cout << "dfs: " << u << endl;

	Fi(sz(edges[u])) {
		v = edges[u][i];
		if(!av[v]) continue;
		if(visited[v]) continue;

		deg[u]++;
		if(!dfs(v)) return false;
	}
	//cout << u << ":" << deg[u] << endl;
	return (deg[u] == 0 || deg[u] == 2);
}


int main() {
	int T,cs;
	int X,Y,i;

	cin >> T;

	rab(cs,1,T) {
		cin >> N;

		Fi(N) edges[i].clear();

		Fi(N-1) {
			cin >> X >> Y;
			edges[X-1].push_back(Y-1);
			edges[Y-1].push_back(X-1);
		}

		int r = N;

		Fi(1 << N) {
			int j,c = 0;

			Fj(N) {
				av[j] = (i & (1 << j));
				if(!av[j]) c++;
			}

			bool s = false;
			//cout << "state:" << i << endl;

			Fj(N) {
				if(!av[j]) continue;
				memset(visited,0,sizeof(visited));
				if(dfs(j)) {
					//cout << "dfs with root " << j << endl;
					int k;

					Fk(N) if(visited[k] != av[k]) { //cout << k << endl;
						break; }
					//cout << k << " " << N << endl;
					if(k >= N) s = true;
					//if(s) cout << "s:" << i << ":" << j << ":" << c << endl;
					break;
				}
				
				//cout << "-" << endl;
			}
			if(s == true) {
				if(c < r) r = c;
			}
		}
			
		printf("Case #%d: %d\n",cs,r);
	}
	return 0;
}
