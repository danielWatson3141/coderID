#include <stdio.h>

char ori[200][200];
char tar[200][200];
int oriz[200];
int tarz[200];
int en, el;

void swap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

bool check(int oor[], int tor[], int level) {
	for (int i = 0; i < en; i++)
		if (ori[ oor[i] ][level] != tar[ tor[i] ][level])
			return false;
	return true;
}

void flip(int n) {
	for (int i = 0; i < en; i++) {
		tar[i][n] = 1 - (tar[i][n] - '0') + '0';
	}
}

void makeblock(int a[], bool ab[], bool bb[], int level) {
	for (int i = 0; i < en - 1; i++) {
		int na = a[i];
		int nb = a[i+1];
		if (ori[na][level] != ori[nb][level])
			bb[i] = true;
		else
			bb[i] = ab[i];
	}
//	printf("%d\n", bb[0]);
}

void make(int b[], int a[], bool block[], char ref[200][200], int level) {
	for (int i = 0; i < en; i++)
		b[i] = a[i];
	for (int i = 0; i < en; i++)
		for (int j = 0; j < en - 1; j++) {
			int na = b[j];
			int nb = b[j+1];
			//printf("%d to %d\n", na, nb);
			if (block[j] == false) {
				if (ref[na][level] > ref[nb][level]) {
					swap(b[j], b[j+1]);
				}
			}
		}
//	for (int i = 0; i < en; i++)
//		printf("---%d %s\n", b[i], ref[ b[i] ]);
//	printf("\n");
}

int dfs(int level, int oor[200], int tor[200], bool block[200]) {
	if (level == el)
		return 0;
	
//	printf("level=%d\n", level);
	int noor[200];
	int ntor[200];
	bool nblock[200];
	int re = 999999;
	for (int i = 0; i < 2; i++) {
		make(noor, oor, block, ori, level);
		make(ntor, tor, block, tar, level);
		if (check(noor, ntor, level)) {
			makeblock(oor, block, nblock, level);
			int t = dfs(level+1, noor, ntor, nblock) + i;
			if (t < re)
				re = t;
		}
		flip(level);
	}
	return re;
}

void swit(int a, int b) {
	for (int i = 0; i < en; i++) {
		swap(ori[i][a], ori[i][b]);
		swap(tar[i][a], tar[i][b]);
	}
	swap(oriz[a], oriz[b]);
	swap(tarz[a], tarz[b]);
}

void calz(char c[200][200], int arr[200]) {
	//printf("en=%d el=%d\n", en, el);
	for (int i = 0; i < el; i++) {
		arr[i] = 0;
		for (int j = 0; j < en; j++) {
			if (c[j][i] == '0') {
				arr[i]++;
			}
			//printf("[%c]\n", c[j][i]);
		}
		int t = en - arr[i];
		if (t < arr[i])
			arr[i] = t;
	}
}

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		scanf("%d%d", &en, &el);
		for (int i = 0; i < en; i++)
			scanf("%s", ori[i]);
		for (int i = 0; i < en; i++)
			scanf("%s", tar[i]);
		calz(ori, oriz);
		calz(tar, tarz);
	
		//for (int i = 0; i < el; i++)
		//	printf("-%d\n", oriz[i]);

		for (int i = 0; i < el; i++)
			for (int j = 0; j < el - 1; j++)
				if (oriz[j] > oriz[j+1])
					swit(j, j+1);
	
		int orior[200];
		int taror[200];
		bool block[200];
		for (int i = 0; i < en; i++) {
			orior[i] = taror[i] = i;
			block[i] = false;
		}
		int ans = dfs(0, orior, taror, block);
		if (ans > el)
			printf("Case #%d: NOT POSSIBLE\n", ecount);
		else
			printf("Case #%d: %d\n", ecount, ans);
		//for (int i = 0; i < en; i++)
		//	printf("%s\n", ori[i]);

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
