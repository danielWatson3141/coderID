#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

vector<int> g[1007];
int deleted;

int DFS(int v, int p) {
	int mx1 = -1, mx2 = -1, cnt = 0, sum = 0;
	FOR(i,0,g[v].size()) {
		int u = g[v][i];
		if(u == p) continue;
		int a = DFS(u,v);
		sum += a;
		cnt++;
		if(a > mx1) {
			mx2 = mx1;
			mx1 = a;
		} else if(a > mx2) {
			mx2 = a;
		}
	}
	if(cnt == 0) return 1;
	if(cnt == 1) {
		deleted += sum;
		return 1;
	}
	if(cnt == 2) {
		return 1 + sum;
	}
	deleted += sum - mx1 - mx2;
	return 1 + mx1 + mx2;
}

int main ()
{
  DRI(T);
  FOR(t,0,T) {
  	DRI(N);
  	FOR(i,0,N) g[i+1].clear();
  	FOR(i,1,N) {
  		DRII(a,b);
  		g[a].PB(b);
  		g[b].PB(a);
  	}
  	int best = N+1;
  	FOR(i,0,N) {
  		deleted = 0;
  		DFS(i+1,-1);
  		best = min(best,deleted);
  	}
  	printf("Case #%d: %d\n", t+1, best);
  }
  return 0;
}














