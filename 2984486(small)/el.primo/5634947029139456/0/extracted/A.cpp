#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

char input[45];
int outlet[155], device[155], N, L;

int fromBinToInt() {
	int n = 0;
	for(int i = 0; i < L; ++i)
		n = n * 2 + input[i] - 48;
	return n;
}

int countOnes(int n) {
	int cnt = 0;
	for(int i = 0; i < L; ++i) {
		cnt += ((n & (1 << i)) != 0);
	}
	return cnt;
}

int main() {
	int t; scanf("%d",&t);
	for(int k = 0; k < t; ++k) {
		scanf("%d %d", &N, &L);
		int ans = INF;
		for(int i = 0; i < N; ++i) {
			scanf("%s", input);
			outlet[i] = fromBinToInt();
		}
		for(int i = 0; i < N; ++i) {
			scanf("%s", input);
			device[i] = fromBinToInt();
		}
		for(int i = 0; i < (1 << L); ++i) {
			for(int j = 0; j < N; ++j)
				outlet[j] ^= i;
			int cnt = 0;
			for(int j = 0; j < N; ++j)
				for(int k = 0; k < N; ++k)
					if(outlet[j] == device[k]) cnt++;
			if(cnt == N) ans = min(ans, countOnes(i));
			for(int j = 0; j < N; ++j)
				outlet[j] ^= i;
		}
		printf("Case #%d: ", k + 1);
		if(ans >= INF) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}
