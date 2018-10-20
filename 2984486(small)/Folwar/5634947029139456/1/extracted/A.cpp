#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

#include<algorithm>
#include<utility>
#include<string>

#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include <iostream>

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;

int t, T, N, L, X;

string A[200], AA[200], B[200], C[200];
bool F[200];

void solve() {
	printf("Case #%d: ", t);

	int minR = -1;

	FOR(n,N) AA[n] = B[n];
	FOR(n,N) C[n] = A[n];
	sort(AA, AA+N, less<string>());

	FOR(a,N) {
		int R = 0;
		FOR(l,L) {
			if (A[0][l] != B[a][l]) { R++; F[l] = true; }
			else F[l] = false;
		}
		FOR(n,N) {
			FOR(l,L) {
				if (F[l] && A[n][l] == '0')
					C[n][l] = '1';
				if (F[l] && A[n][l] == '1')
					C[n][l] = '0';
				if (!F[l] && A[n][l] == '0')
					C[n][l] = '0';
				if (!F[l] && A[n][l] == '1')
					C[n][l] = '1';
			}
		}
		sort(C, C+N, less<string>());
		FOR(n,N)
			if (C[n] != AA[n]) goto fail;
		if (minR == -1) minR = R;
		else minR = min(R, minR);
		fail:
		X = 0;
	}
	if (minR == -1)
		printf("NOT POSSIBLE\n");
	else
		printf("%d\n", minR);
}

int main() {
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d%d", &N, &L);
		FOR(n,N)
			cin >> A[n];
		FOR(n,N)
			cin >> B[n];
		solve();
	}
	return 0;
}
