#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define REP(i, N) for(int i = 0; i < (N); i++)

using namespace std;
char outlets[222][2][44];
int main() {
	int T, testcase=1;
	scanf("%d", &T);
	while(T--) {
		int N, L;
		scanf("%d%d", &N, &L);
		REP(a, 2) REP(i, N) scanf("%s", outlets[i][a]);

		int ans = -1;
		REP(i, 1<<L) {
			vector<string> orig, res;
			int cans = 0;
			REP(j, N) { orig.pb(outlets[j][0]); res.pb(outlets[j][1]); }
			REP(j, L) if(i&(1<<j)) {
				cans++;
				REP(k, N) orig[k][j] = !(orig[k][j]-'0')+'0';
			}
			sort(orig.begin(), orig.end());
			sort(res.begin(), res.end());
			bool ok = true;
			REP(j, N) if(orig[j] != res[j]) ok = false;
			if(ok) {
				if(ans == -1 || cans < ans)
					ans = cans;
			}
		}

		printf("Case #%d: ", testcase++);
		if(ans == -1) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	}
	
	return 0;
}
