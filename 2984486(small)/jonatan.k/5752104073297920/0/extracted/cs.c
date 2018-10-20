#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_LEN 1000
#define BUF_LEN 0x10
#define bool int
#define false 0
#define true 1

#define LL long long;

int nums[MAX_LEN];
char buf[BUF_LEN];

int main() {
	// process input data
	int tcs;
	scanf("%d", &tcs);
	int tc;
	for (tc = 0; tc < tcs; ++tc) {
		int res = 0;
		int na;
		scanf("%d", &na);

		int div = na >> 1;
		int suma = 0, sumb = 0;
		int i, val;
		for (i = 0; i < na; ++i) {
			//scanf("%d", nums[i]);
			scanf("%d", &val);
			if (i < div) suma += val;
			else sumb += val;
		}

		printf("Case #%d: %s\n", tc + 1, sumb > suma ? "GOOD" : "BAD");
		//printf("Case #%d: %s [%6d vs %6d ]\n", tc + 1, sumb > suma ? "GOOD" : "BAD ", suma, sumb);
	}
	return 0;
}
