#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

#define MAX 1024
int N;
vector<int> ar[MAX];

int ja[MAX];

int nfilhos[MAX];
int best[MAX];


void dfs(int v) {
	ja[v] = 1;
	nfilhos[v] = 1;
	vector<int> custos;
	int tot = 0;
	FOREACH(it, ar[v]) {
		if (!ja[*it]) {
			dfs(*it);
			tot += nfilhos[*it];
			custos.pb(best[*it] - nfilhos[*it]);
			nfilhos[v] += nfilhos[*it];
		}
	}
	sort(all(custos));
	if (sz(custos) <= 1) {
		best[v] = tot;
	} else {
		best[v] = tot + custos[0] + custos[1];
	}
}

void solve() {
	cin >> N;
	FOR(i, N) ar[i].clear();
	FOR(i, N-1) {
		int a,b;
		cin >> a >> b;
		a--; b--;
		ar[a].pb(b);
		ar[b].pb(a);
	}

	int ans = N;
	FOR(i, N) {
		FOR(j, N) ja[j] = 0;
		dfs(i);
		ans = min(ans, best[i]);
	}
	cout << ans << endl;
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
