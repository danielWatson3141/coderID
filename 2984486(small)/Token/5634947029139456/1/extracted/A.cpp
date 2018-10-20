/*
 * 2014-04-26  Token  <token@token-HP-ENVY-14-SPECTRE-Notebook-PC>

 * 
 */
#include <algorithm>
#include <iostream>
#include <fstream>
#include <climits>
#include <string>

using namespace std;

const int MaxiN = 205;
const int MaxiL = 205;

int N, L, Ans;
bool Able;
string S1[MaxiN], S2[MaxiN], S3[MaxiN];
bool Need[MaxiL];

void Solve() {
	Able = 0;
	Ans = INT_MAX;
	sort(S1, S1 + N);
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < L; ++ j)
			Need[j] = (S1[0][j] != S2[i][j]);
		for (int k = 0; k < N; ++ k) {
			S3[k] = S2[k];
			for (int j = 0; j < L; ++ j)
				if (Need[j])
					S3[k][j] = (int) '0' + (int) '1' - (int) S3[k][j];
		}
		sort(S3, S3 + N);
		bool Flag = 1;
		for (int k = 0; k < N; ++ k)
			if (S1[k] != S3[k])
				Flag = 0;
		if (Flag) {
			Able = 1;
			int Cnt = 0;
			for (int j = 0; j < L; ++ j)
				if (Need[j])
					++ Cnt;
			if (Cnt < Ans)
				Ans = Cnt;
		}
	}
}

int main() {
	int TestCase = 0;
	cin >> TestCase;
	for (int T = 1; T <= TestCase; ++ T) {
		cin >> N >> L;
		for (int k = 0; k < N; ++ k)
			cin >> S1[k];
		for (int k = 0; k < N; ++ k)
			cin >> S2[k];
		Solve();
		printf("Case #%d: ", T);
		if (!Able)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", Ans);
	}
	return 0;
}
