#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

bool num1[200][200], num2[200][200];
bool numaux[200][200];
bool inv[200];
int t, n, l;
char aux[100];
int co = 1;

long long toBin (bool nu[200][200], int i) {
	long long numtemp = 0;
	for (int j = 0; j < l; j++) {
		numtemp *= 2;
		if (nu[i][j]) numtemp += 1;
	}
	return numtemp;
}

int main () {

	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &l);

		for (int i = 0; i < n; i++) {
			scanf("%s", aux);
			for (int j = 0; j < l; j++) {
				if (aux[j] == '0') num1[i][j] = 0;
				else num1[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			scanf("%s", aux);
			for (int j = 0; j < l; j++) {
				if (aux[j] == '0') num2[i][j] = 0;
				else num2[i][j] = 1;
			}
		}

		// long long xOR2 = xORN(num2);
		set <long long> S1, S2;
		for (int i = 0; i < n; i++) {
			S2.insert(toBin(num2, i));
		}
		int ANS = 99999, nINV;
		for (int i = 0; i < n; i++) {
			nINV = 0;
			S1.clear();
			for (int j = 0; j < l; j++) {
				if (num1[0][j] == num2[i][j]) inv[j] = 0;
				else {inv[j] = 1; nINV++;}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < l; j++) {
					if (inv[j] == 0) numaux[i][j] = num1[i][j];
					else numaux[i][j] = !num1[i][j];
				}
			}

			for (int i = 0; i < n; i++) {
				S1.insert(toBin(numaux, i));
			}

			// long long xOR1 = xORN(numaux);
			if (S1 == S2) {
				ANS = min (nINV, ANS);
			}
		}
		if (ANS == 99999)
			printf("Case #%d: NOT POSSIBLE\n",co++);
		else
			printf("Case #%d: %d\n",co++, ANS);
	}

	return 0;
}