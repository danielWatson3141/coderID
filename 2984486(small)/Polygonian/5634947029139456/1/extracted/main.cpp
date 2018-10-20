#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum { MAX = 200 };

int N, L;
vector<string> S;  // switches;
vector<string> D;  // devices;
vector<string> Stemp;  // devices;
vector<string> Dtemp;  // devices;

void solve(int CASE) {
	S.clear();
	D.clear();
	Stemp.clear();
	Dtemp.clear();

	char ss[MAX];
	scanf("%d%d", &N, &L);

	for (int i = 0; i < N; i++) {
		scanf("%s", ss);
		S.push_back(ss);
		
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", ss);
		D.push_back(ss);
	}
	sort(S.begin(), S.end());
	sort(D.begin(), D.end());

	int best = -1;
	for (int m = 0; m < N; m++) {
		Dtemp = D;  // copy;
		Stemp = S;  // copy;

		string modelSwitch = S[m];
		string modelDevice = D[0];
		
		int switchCount = 0;
		for (int l = 0; l < L; l++) {

			char c = modelDevice[l];
			if (c == modelSwitch[l]) {
				;
			} else {
				switchCount++;
				for (int n = 0; n < N; n++)
					Stemp[n][l] = Stemp[n][l] == '0' ? '1' : '0';
			}
		}

		sort(Dtemp.begin(), Dtemp.end());
		sort(Stemp.begin(), Stemp.end());
		if (Dtemp == Stemp) {
			if (best == -1 || switchCount < best) best = switchCount;
		}
	}

	if (best == -1) {
		printf("Case #%d: NOT POSSIBLE\n", CASE);
	} else {
		printf("Case #%d: %d\n", CASE, best);
	}
}

int main(void) {
	int Q;
	scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
		solve(q + 1);
	}
	return 0;
}
