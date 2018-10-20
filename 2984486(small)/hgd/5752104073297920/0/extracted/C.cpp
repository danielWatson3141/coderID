#include <cstdio>
#include <cstdlib>

int main() {
	FILE *fin = fopen("C-small-attempt2.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, N;
	fscanf(fin, "%d", &T);
	for (int t = 0; t < T; ++t) {
		fprintf(fout, "Case #%d: ", t + 1);
		fscanf(fin, "%d", &N);
		int s = 0;
		for (int i = 0; i < N; ++i) {
			int k;
			fscanf(fin, "%d", &k);
			if (i < 100 && k >= 100) ++s;
		}
		printf("%d\n", s);
		if (s < 80) fprintf(fout, "BAD\n");
		else fprintf(fout, "GOOD\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
