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

using namespace std;

#define FOR(i,N) for (int i = 0; i < (N); i++)
#define FORI(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, b, a) for (int i = (b) - 1; i >= a; i--)
#define DP(arg...) fprintf(stderr, ## arg) //COMPILER SPECIFIC!!!


typedef long long ll;

int t, T, N, L;


int tab[100000000];

int Q[2000];
int P[2000];

int FAC, GEN;

void generate_table() {
	int p = 0;
	while (p <= L) {
		GEN++;
		FOR(n,L) P[n] = n;
		FOR(n,L)
			swap(P[n], P[Q[n]]);
		bool carry = true;

		int code = 0;
		FOR(n,L) {
			code += P[n];
			code *= 10;
		}
		code /= 10;

		tab[code]++;
		
		for (p = 0; p <= L && carry; p++) {
			if (carry) Q[p]++;
			if (Q[p] == L) {
				Q[p] = 0; carry = true;
			}
			else carry = false;
		}
	}
}

int TT[2000];
int NN[2000];

void solve() {
	bool good;

	FOR(l,L) { TT[l] = P[l]; }

	sort(TT,TT+L);
	FOR(l,L) {
		FOR(n,L) {
			if (P[n] == TT[l])
				NN[n] = l;
		}
	}

	/*int k = 0;
	FOR(n,N) {
		if (P[n] < L) {
			NN[k++] = P[n];
		}
	}*/

	int code = 0;
	FOR(n,L) {
		code += NN[n];
		code *= 10;
	}
	code /= 10;

	double p1 = (double)1/(double)FAC;
	double p2 = (double)tab[code]/(double)GEN;

	double myrand = ((double)rand()/(double)RAND_MAX);

	/*if ((p1 + p2) * myrand < p1)
		good = true;
	else
		good = false;*/
	
	if (p1 < p2)
		good = false;
	else
		good = true;


	if (good)
		printf("Case #%d: GOOD\n", t);
	else
		printf("Case #%d: BAD\n", t);
}

int main() {
	srand(22031993);
	L = 7;
	generate_table();
	FOR(n,10000000)
		if (tab[n] != 0) {
			FAC++;
		}
	
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		FOR(n,N)
			scanf("%d", &P[n]);
		solve();
	}
	return 0;
}
