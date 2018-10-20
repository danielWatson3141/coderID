#include <cstdio>
#include <cstdlib>

int comp(const void * a, const void * b) {
	return *(int *)a - *(int *)b;
}

int N, L;
int outlets[150], devices[150], temp[150];

int main() {
	FILE * fin = fopen("A.in", "r"), * fout = fopen("A.out", "w");
	int T, t, i, j, k, a, ans;
	fscanf(fin, "%d", &T);
	for (t = 1; t <= T; ++t) {
		fscanf(fin, "%d%d", &N, &L);
		ans = L + 1;
		for (i = 0; i < N; ++i) {
			getc(fin);
			outlets[i] = 0;
			for (j = 0; j < L; ++j) {
				k = getc(fin) - '0';
				outlets[i] ^= (k << j);
			}
		}
		for (i = 0; i < N; ++i) {
			getc(fin);
			devices[i] = 0;
			for (j = 0; j < L; ++j) {
				k = getc(fin) - '0';
				devices[i] ^= (k << j);
			}
		}
		qsort(devices, N, 4, comp);
		for (k = 0; k < (1 << L); ++k) {
			for (i = 0; i < N; ++i) {
				temp[i] = outlets[i] ^ k;
			}
			qsort(temp, N, 4, comp);
			for (i = 0; i < N; ++i) {
				if (temp[i] != devices[i]) {
					break;
				}
			}
			if (i == N) {
				a = 0;
				for (j = 0; j < L; ++j) {
					if (k & (1 << j)) {
						++a;
					}
				}
				if (a < ans) {
					ans = a;
				}
			}
		}
		if (ans == L + 1) {
			fprintf(fout, "Case #%d: NOT POSSIBLE\n", t);
		} else {
			fprintf(fout, "Case #%d: %d\n", t, ans);
		}
	}
	return 0;
}