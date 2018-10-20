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

void dfs(int v) {
	if (ja[v]) return;
	ja[v] = 1;
	int f1 = -1, f2 = -1;
	FOREACH(it, ar[v]) {
		if (!ja[*it]) {
			if (f1 == -1) {
				f1 = *it;
			} else if (f2 == -1) {
				f2 = *it;
			} else {
				return;
			}
		}
	}
	if(f1 == -1 || f2 == -1) {
		return;
	}
	dfs(f1); dfs(f2);
}

int tenta(int bits) {
	FOR(i, N) {
		int ans = 0;
		FOR(j, N) {
			ja[j] = 0;
			if (bits & (1<<j)) {
				ans++;
				ja[j] = 1;
			}
		}
		dfs(i);
		int ok = 1;
		FOR(j, N) {
			if (!ja[j]) ok = 0;
		}
		if (ok) {
			return ans;
		}
	}
	return N;
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
	FOR(i, (1<<N)) {
		int aux = tenta(i);
		ans = min(ans, aux);
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
