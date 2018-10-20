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
int visited[1000];
int idx;
int N;

int childsize[1000];

int find_size(int u) {
	int i,v;

	visited[u] = idx;
	childsize[u] = 1;
	
	Fi(sz(edges[u])) {
		v = edges[u][i];
		if(visited[v] == idx) continue;

		childsize[u] += find_size(v);
	}
	//cerr << "size:" << u << ":" << childsize[u] << endl;
	return childsize[u];
}

int min_remove(int u) {
	int i;
	int c,m;
	int sum = 0;
	int p,q;

	p = q = 1;

	visited[u] = idx;

	Fi(sz(edges[u])) {
		int v = edges[u][i];
		if(visited[v] == idx) continue;
		c = childsize[v];
		m = min_remove(v);
		sum += c;
		int r = m - c;
		
		if(r < p) {
			q = p;
			p = r;
		} else if(r < q) {
			q = r;
		}
	}

	//cerr << "remove " << u << " " << p << " " << q << " " << sum << endl;

	if(p <= 0 && q <= 0) {
		sum += p + q;
	}

	//cerr << "remove " << u << " removed " << sum << endl;

	return sum;
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
		memset(visited,0,sizeof(visited));
		idx = 1;
		int r = N,c;

		Fi(N) {
			//cerr << "root " << i << endl;
			find_size(i);
			idx++;
			c = min_remove(i);
			idx++;

			//cerr << "root " << i << " removed " << c << endl;

			if(c < r) r = c;

			//if(i == 1) exit(0);
		}

		printf("Case #%d: %d\n",cs,r);
	}
	return 0;
}
