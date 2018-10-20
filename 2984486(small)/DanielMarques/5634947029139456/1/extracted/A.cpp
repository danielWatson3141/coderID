#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int N, L;
map<string, int> mapaAll;
map<string, int> mapaD[200];
char outlet[200][100], device[200][100];
char f[100];

int main() {
	int T;
	scanf(" %d", &T);
	for (int _42=1; _42 <= T; _42++) {
		scanf(" %d %d", &N, &L);

		for (int i = 0; i < N; i++) {
			scanf(" %s", outlet[i]);
		}
		for (int i = 0; i < N; i++) {
			mapaD[i].clear();
			scanf(" %s", device[i]);
		}

		mapaAll.clear();
		string aux = "";
		f[L] = '\0';
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < L; k++) {
					if (device[i][k] != outlet[j][k]) {
						f[k] = '1';
					}
					else {
						f[k] = '0';
					}
				}
				aux = f;
				mapaAll[aux] = 1;
				mapaD[i][aux] = 1;
			}
		}

		int ans = L+1;
		for (map<string, int>::iterator it = mapaAll.begin(); it != mapaAll.end(); it++) {
			aux = it->first;
			bool invalid = false;
			for (int i = 0; i < N; i++) {
				if (mapaD[i].find(aux) == mapaD[i].end()) {
					invalid = true;
					break;
				}
			}
			if (!invalid) {
				int count = 0;
				for (int i = 0; i < L; i++) {
					if (aux[i] == '1') count++;
				}
				ans = min(ans, count);
			}
		}

		if (ans == L+1) {
			printf("Case #%d: NOT POSSIBLE\n", _42);
		}
		else {
			printf("Case #%d: %d\n", _42, ans);
		}
	}
	return 0;
}