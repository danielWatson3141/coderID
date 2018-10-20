#include <stdio.h>
#include <algorithm>

using namespace std;

int nextt[1000][1000];
int len[1000];
int en;


int dfs(int n, int last) {
	//printf("%d (%d)\n", n, last);
	int ar[1000];
	int amany = 0;
	for (int i = 0; i < len[n]; i++) {
		int t = nextt[n][i];
		if (t != last)
			ar[amany++] = dfs(t, n);
	}
	if (amany < 2)
		return 1;
	else {
		sort(ar, ar+amany);
		return 1 + ar[amany-1] + ar[amany-2];
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

		scanf("%d", &en);
		for (int i = 0; i < en; i++)
			len[i] = 0;
		for (int i = 1; i < en; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			nextt[a][ len[a] ] = b;
			nextt[b][ len[b] ] = a;
			len[a]++;
			len[b]++;
		}

		int ans = en;
		for (int i = 0; i< en ;i++) {
			int t = dfs(i, -1);
			int tans = en - t;
			if (tans < ans)
				ans = tans;
			//printf("\n");
		}

		printf("Case #%d: %d\n", ecount, ans);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
