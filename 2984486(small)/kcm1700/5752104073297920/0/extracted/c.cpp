#include <stdio.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<vector<int>, int> cnt;
void rec(vector<int> a,int ind = 0) {
	if (ind == a.size()) {
		cnt[a]++;
		return;
	}
	for(int i = 0; i < a.size(); i++) {
		swap(a[i], a[ind]);
		rec(a, ind+1);
		swap(a[i], a[ind]);
	}
}

int dat[1024];

double dt[1024][1024];

const int N = 1000;

int main()
{
	for(int k = 0; k < N; k++) {
		dt[k][k] = N;
		for(int i = 0; i < N; i++) {
			double base = dt[k][i] / N;
			for(int j = 0;j < N; j++) {
				if (i == j) {
					dt[k][i] = base + (N-dt[k][i]) / N;
				} else {
					dt[k][j] = dt[k][j] * (N-1.0)/N + base;
				}
			}
		}
		if (k % 100 == 0) fprintf(stderr,"Preproc: %d\n", k);
	}
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		if (testcase % 10 == 0) fprintf(stderr,"Data: %d\n", testcase);
		int n;
		scanf("%d",&n);
		double mul = 1;
		for(int i = 0; i < n; i++) {
			scanf("%d",&dat[i]);
			mul *= dt[dat[i]][i];
		}
		bool likely = (mul > 1.0);
		printf("Case #%d: ",testcase);
		if (likely) {
			printf("BAD\n");
		} else {
			printf("GOOD\n");
		}
	}
	return 0;
}
