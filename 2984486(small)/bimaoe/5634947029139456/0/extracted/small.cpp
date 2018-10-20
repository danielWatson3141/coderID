#include <stdio.h>
#include <iostream>

using namespace std;

int main (void) {
	int t, c;
	int n, l, i, j;
	char ini[10][11], fin[10][11];
	bool flip[10];
	int v[10];
	scanf ("%d", &t);
	for (c = 1; c <= t; c++) {
		printf ("Case #%d: ", c);
		scanf ("%d%d", &n, &l);
		for (i = 0; i < n; i++)	scanf ("%s", ini[i]);
		for (i = 0; i < n; i++)	scanf ("%s", fin[i]);
		for (i = 0; i < n; i++)	v[i] = i;
		bool ok = false;
		int cnt, ans = 100000;
		bool poss = false;
		do {
			memset (flip, false, sizeof flip);
			ok = true;
			cnt = 0;
			for (j = 0; j < l; j++)
				if (ini[v[0]][j] != fin[0][j]) {
					flip[j] = true;
					cnt++;
				}
			for (i = 1; i < n && ok; i++) {
				for (j = 0; j < l && ok; j++)
					if (ini[v[i]][j] != fin[i][j]) {
						if(!flip[j])	ok = false;
					} else {
						if (flip[j])	ok = false;
					}
			}
			if (ok)	{
				poss = true;
				ans = min(ans, cnt);
			}

		} while(next_permutation(v, v+n));
		if (!poss)	printf ("NOT POSSIBLE\n");
		else	printf ("%d\n", ans);
	}
	return 0;
}