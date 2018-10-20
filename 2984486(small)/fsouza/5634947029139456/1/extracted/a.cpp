#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)

#define MAXN 150
#define MAXL 40

typedef long long lint;

using namespace std;

char outlet[MAXN][MAXL+1];
char device[MAXN][MAXL+1];
int change[MAXL];

int main(int argc, char ** argv)
{
	int nt;

	scanf("%d", &nt);

	for (int t = 0; t < nt; t++) {
		int result = INF;
		int n, l;

		scanf("%d %d", &n, &l);

		for (int i = 0; i < n; i++) {
			scanf(" %s", outlet[i]);
		}

		for (int i = 0; i < n; i++) {
			scanf(" %s", device[i]);
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l; j++) change[j] = (device[0][j] != outlet[i][j]);
			int nchange = accumulate(change, change + l, 0);

			map <string, int> remain;

			for (int k = 0; k < n; k++) {
				string put = outlet[k];
				for (int j = 0; j < l; j++)
					if (change[j])
						put[j] = '0' + (1-(put[j]-'0'));
				remain[put]++;
			}

			bool ok = true;

			for (int k = 0; k < n; k++) {
				string want = device[k];
				if (remain.find(want) == remain.end()) ok = false;
				else {
					int x = (remain[want]--);
					if (x <= 0) ok = false;
				}
			}

			if (ok) result = min(result, nchange);
		}

		printf("Case #%d: ", t+1);
		if (result == INF) printf("NOT POSSIBLE");
		else printf("%d", result);
		printf("\n");
	}

	return 0;
}
