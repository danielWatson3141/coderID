#include <stdio.h>
#include <string.h>

FILE *fin, *fout;
int N, L;
char init[152][50], req[152][50];
void input(void)
{
	int i;
	fscanf(fin, "%d %d", &N, &L);
	for (i=0;i<N;++i){
		fscanf(fin, "%s", init[i]);
	}
	for (i=0;i<N;++i){
		fscanf(fin, "%s", req[i]);
	}
}

bool sw[50];

bool possible(void)
{
	int i, j, k;
	bool used[50];
	for (i=0;i<N;++i) used[i] = false;
	for (i=0;i<N;++i){
		for (j=0;j<N;++j){
			if (used[j]) continue;
			for (k=0;k<L;++k){
				if (sw[k]^(init[i][k] == req[j][k])){
					break;
				}
			}
			if (k==L) used[j] = true;
		}
	}
	for (i=0;i<N;++i)
		if (!used[i]) return false;
	return true;
}

void process(void)
{
	int dab=L+1;
	int i, j, k;
	int tmp;
	for (i=0;i<N;++i){ // 0 - i
		tmp = 0;
		for (j=0;j<L;++j){
			sw[j] = (init[0][j] == req[i][j]);
			if (!sw[j]) ++tmp;
		}
		if (tmp < dab){
			if (possible()) dab = tmp;
		}
	}
	if (dab > L) fprintf(fout, "NOT POSSIBLE");
	else fprintf(fout, "%d", dab);
}

int main(void)
{
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");
	int T, t;
	fscanf(fin, "%d", &T);
	for (t=1; t<=T; ++t){
		input();
		fprintf(fout, "Case #%d: ", t);
		process();
		fprintf(fout, "\n");
	}
	fclose(fout);
	fclose(fout);
	return 0;
}
