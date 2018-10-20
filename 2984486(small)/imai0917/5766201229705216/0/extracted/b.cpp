#include <stdio.h>
#include <vector>

using namespace std;

FILE *fin, *fout;
int N;
int E[1010][2];
vector<int> T[1010];
void init(void)
{
	int i;
	for (i=1;i<=N;++i){
		while (!T[i].empty()){
			T[i].pop_back();
		}
	}
}
void input(void)
{
	fscanf(fin, "%d", &N);
	int i;
	for (i=0;i<N-1;++i){
		fscanf(fin, "%d %d", &E[i][0], &E[i][1]);
		T[E[i][0]].push_back(E[i][1]);
		T[E[i][1]].push_back(E[i][0]);
	}
}
int chk[1010]={0};
void sswap(int &t1, int &t2){
	int t;
	t = t1; t1 = t2; t2 = t;
}
int dy(int r)
{
	chk[r] = 1;
	int n = T[r].size();
	int mmax[3];
	int i;
	int tmp;
	for (i=0;i<3;++i) mmax[i] = -1;
	for (i=0;i<n;++i){
		int t = T[r][i];
		if (chk[t] == 1) continue;
		mmax[2] = dy(t);
		if (mmax[2]>mmax[1]) sswap(mmax[2], mmax[1]);
		if (mmax[1]>mmax[0]) sswap(mmax[1], mmax[0]);
	}
	if (mmax[1] == -1) return 1;
	return mmax[0]+mmax[1]+1;
}
void process(void)
{
	int r;
	int dab = N-1;
	int tmp, i;
	for (r=1;r<=N;++r){
		for (i=1;i<=N;++i) chk[i] = 0;
		tmp = dy(r);
		//printf("%d -- %d\n", r, tmp);
		if (N-tmp < dab) dab = N-tmp;
	}
	fprintf(fout, "%d\n", dab);
}
int main(void)
{
	int T, t;
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	fscanf(fin, "%d", &T);
	for (t=1;t<=T;++t){
		input();
		//printf("Case #%d:\n", t);
		fprintf(fout, "Case #%d: ", t);
		process();
		init();
	}

	fclose(fout);
	fclose(fin);
	return 0;
}
