#include <cstdio>
#include <cstdlib>

typedef unsigned long long data;

data outlets[150];
data goal[150];
data tmp[150];
int T, N, L;

int cmp(const void *x, const void *y) {
	data u = *(const data *)x;
	data v = *(const data *)y;
	if (u < v) return -1;
	if (u > v) return 1;
	return 0;
}

int check(data sw) {
	for (int i = 0; i < N; ++i)
		tmp[i] = (outlets[i] ^ sw);
	qsort(tmp, N, sizeof(data), cmp);
	for (int i = 0; i < N; ++i)
		if (tmp[i] != goal[i]) return 9999;
	int num = 0;
	do {
		num += (sw & 1);
		sw >>= 1;
	} while (sw != 0);
	return num;
}

int main() {
	FILE *fin = fopen("A-small-attempt1.in", "r");
	FILE *fout = fopen("out.txt", "w"); 
	fscanf(fin, "%d", &T);
	for (int t = 0; t < T; ++t) {
		fprintf(fout, "Case #%d: ", t + 1);
		fscanf(fin, "%d%d", &N, &L);
		for (int i = 0; i < N; ++i) {
			char tmp[50];
			fscanf(fin, "%s", tmp);
			outlets[i] = 0;
			for (int j = 0; j < L; ++j)
				outlets[i] = ((outlets[i] << 1) | (tmp[j] - '0'));
		}
		for (int i = 0; i < N; ++i) {
			char tmp[50];
			fscanf(fin, "%s", tmp);
			goal[i] = 0;
			for (int j = 0; j < L; ++j)
				goal[i] = ((goal[i] << 1) | (tmp[j] - '0'));
		}
		qsort(goal, N, sizeof(data), cmp);
		int ans = 9999;
		for (int i = 0; i < N; ++i) {
			data sw = (goal[i] ^ outlets[0]);
			int num = check(sw);
			if (num < ans) ans = num;
		}
		if (ans == 9999) fprintf(fout, "NOT POSSIBLE\n");
		else fprintf(fout, "%d\n", ans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
