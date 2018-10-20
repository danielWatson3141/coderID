#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <vector>
#include <set>
#include <map>
#include <deque>
#include <string>
#include <bitset>

#include <algorithm>
#include <cmath>
using namespace std;

int const MAX_N = 1010;

int n;
int perm[MAX_N],dp[MAX_N];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	int cnt_bad = 0,cnt_good = 0;
	srand(11);
	for (int qq=0; qq<t; qq++) {
		printf("Case #%d: ",qq+1);

		scanf("%d",&n);
		for (int i=0; i<n; i++)
			scanf("%d",&perm[i]);

		int inv_count = 0;
		for (int i=0; i<n; i++)
			for (int j=i+1; j<n; j++)
				if (perm[i] > perm[j])
					inv_count++;

		int up_sec = 0;
		for (int i=0; i<n; i++) dp[i] = -1;
		for (int i=0; i<n; i++) {
			dp[i] = 1;
			for (int j=0; j<i; j++)
				if (perm[j] < perm[i])
					dp[i] = max(dp[i], dp[j] + 1);
		}
		for (int i=0; i<n; i++) up_sec = max(up_sec, dp[i]);

		int down_sec = 0;
		for (int i=0; i<n; i++) dp[i] = -1;
		for (int i=0; i<n; i++) {
			dp[i] = 1;
			for (int j=0; j<i; j++)
				if (perm[j] > perm[i])
					dp[i] = max(dp[i], dp[j] + 1);
		}
		for (int i=0; i<n; i++) down_sec = max(down_sec, dp[i]);

		int total_max_inv_count = n*(n-1)/2;

		int is_sosed = 0;
		for (int i=0; i<n-1; i++)
			if ((perm[i]+1==perm[i+1]) || (perm[i]-1==perm[i+1]))
				is_sosed = 1;

		if ((perm[0] <= n/2) && (up_sec > down_sec-5)) {
			printf("BAD");
			cnt_bad++;
		}
		else {
			int c = rand()%89;
			if (1) {
				cnt_good++;
				printf("GOOD");
			}
			else {
				cnt_bad++;
				printf("BAD");
			}
		}

		printf("\n");
	}

	cerr<<cnt_bad<<" "<<cnt_good;
	return 0;
}