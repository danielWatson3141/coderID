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
#define INF 1024
int N, L;

string outs[MAX];
string devices[MAX];
int trocou[MAX];

string A[MAX], B[MAX];

char flip(char c) {
	if (c == '0') return '1';
	return '0';
}

int solve_ok() {
	FOR(i, N) {
		A[i] = string(L, ' ');
		FOR(j, L) {
			A[i][j] = outs[i][j];
			if (trocou[j]) {
				A[i][j] = flip(A[i][j]);
			}
		}
	}
	FOR(i, N) {
		B[i] = devices[i];
	}
	sort(A, A+N); sort(B, B+N);
	FOR(i, N) {
		if (A[i] != B[i]) return 0;
	}
	return 1;
}

void solve() {
	cin >> N >> L;
	FOR(i, N) {
		cin >> outs[i];
	}
	FOR(i, N) {
		cin >> devices[i];
	}
	int ans = INF;
	FOR(i, N) {
		FOR(j, N) {
			int trocas = 0;
			FOR(k, L) {
				trocou[k] = 0;
				if (outs[i][k] != devices[j][k]) {
					trocas++;
					trocou[k] = 1;
				}
			}
			if (solve_ok()) {
				ans = min(ans, trocas);
			}
		}
	}
	if (ans == INF) {
		cout << "NOT POSSIBLE" << endl;
	} else {
		cout << ans << endl;
	}
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
