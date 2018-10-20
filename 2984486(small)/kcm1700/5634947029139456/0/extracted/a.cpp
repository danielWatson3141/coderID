#include <stdio.h>
#include <numeric>
#include <climits>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

char dat[2][160][64];

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		int n, l;
		scanf("%d%d",&n,&l);
		vector<string> B;
		for(int j = 0; j < 2; j++) {
			for(int i = 0; i < n; i++) {
				scanf("%s",dat[j][i]);
				if (j == 1) {
					B.push_back(dat[j][i]);
				}
			}
		}
		sort(B.begin(),B.end());
		int ans = INT_MAX;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				vector<string> A;
				char diff[64];
				for(int k = 0; k < l; k ++) {
					diff[k] = dat[0][i][k]^dat[1][j][k];
				}
				int cnt = accumulate(diff, diff + l, (int)0);
				for(int k = 0; k < n; k++) {
					string p;
					for(int a = 0; a < l; a++) {
						p.push_back(dat[0][k][a] ^ diff[a]);
					}
					A.push_back(p);
				}
				sort(A.begin(),A.end());
				if (A == B) {
					ans = min(ans, cnt);
				}
			}
		}

		printf("Case #%d: ", testcase);
		if (ans == INT_MAX) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
