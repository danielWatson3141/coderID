/*
 * 2014-04-26  Token  <token@token-HP-ENVY-14-SPECTRE-Notebook-PC>

 * 
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++ i)

const int MaxiN = 1005;

int N;
bool IsGood;
int A[MaxiN], B[MaxiN];
double LnF[2][MaxiN][MaxiN];

void Import() {
	scanf("%d", &N);
	rep (i, N)
		scanf("%d", A + i);
}

void Export(int T) {
	printf("Case #%d: %s\n", T, (IsGood ? "GOOD" : "BAD"));
}

void Solve() {
	rep (i, N)
		B[i + 1] = A[i] + 1;
	double good = 0;
	for (int i = 1; i <= N; ++ i)
		good -= log(N);
	double bad = 0;
	for (int i = 1; i <= N; ++ i)
		bad += LnF[N & 1][B[i]][i];
	cerr << good << " " << bad << endl;
	int inpos = 0;
	for (int i = 1; i <= N; ++ i)
		if (B[i] == i)
			++ inpos;
	IsGood = (good > bad);
}

void Inc(double &a, double b) {
	if (fabs(a - b) > 40)
		a = max(a, b);
	else {
		a += log(1.0 + exp(b - a));
	}
}

void Prework() {
	for (int x = 1; x <= N; ++ x)
		for (int p = 1; p <= N; ++ p) {
			if (x == p)
				LnF[0][x][p] = 0;
			else
				LnF[0][x][p] = INT_MIN;
		}
	double lN = log(N);
	double lN1 = log(N - 1);
	for (int x = 1; x <= N; ++ x)
		for (int i = 1; i <= N; ++ i) {
			for (int p = 1; p <= N; ++ p) {
				if (i == p)
					LnF[i & 1][x][p] = - lN;
				else {
					LnF[i & 1][x][p] = LnF[(i - 1) & 1][x][p] + lN1 - lN;
					Inc(LnF[i & 1][x][p], LnF[(i - 1) & 1][x][i] - lN);
				}
			}
		}
}

int main() {
	int TestCase = 0;
	N = 1000; ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Prework();
	cerr << "!!!" << endl;
	scanf("%d", &TestCase);
	for (int T = 1; T <= TestCase; ++ T) {
		Import();
		Solve();
		Export(T);
	}
}
