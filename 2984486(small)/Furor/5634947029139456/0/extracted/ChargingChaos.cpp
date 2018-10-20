#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 15

using namespace std;

int A[MAX][2];
char str[MAX];

int main() {
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int c, i, j, k, m, n, t;
	scanf("%d\n", & t);
	for (c = 0; c < t; c++) {
		scanf("%d %d\n", & n, & m);
		for (i = 0; i < 2; i++) {
			for (j = 0; j < n; j++) {
				A[j][i] = 0;
				scanf("%s", str);
				for (k = 0; k < m; k++)
					if (str[k] == '1')
						A[j][i] |= (1 << (m - k - 1));
			}
			scanf("\n");
		}
		int ans = MAX;
		for (i = 0; i < (1 << m); i++) {
			int w = 0;
			for (j = 0; j < m; j++)
				if (i & (1 << j))
					w++;
			if (w < ans) {
				vector<int> C[2];
				for (j = 0; j < n; j++) {
					C[0].push_back(A[j][0] xor i);
					C[1].push_back(A[j][1]);
				}
				sort(C[0].begin(), C[0].end());
				sort(C[1].begin(), C[1].end());
				bool match = true;
				for (j = 0; j < m; j++)
					if (C[0][j] != C[1][j])
						match = false;
				if (match)
					ans = w;
			}
		}
		printf("Case #%d: ", c + 1);
		if (ans == MAX)
			printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
