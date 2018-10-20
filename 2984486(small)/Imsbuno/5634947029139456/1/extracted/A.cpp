#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int64;
typedef map<int64,int> mapi64;

mapi64 s;
char a[155][44], b[155][44];
int64 diff[155][155];
int v[155], N, L;


int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int testCaseNum;
	scanf("%d", &testCaseNum);
	for (int testCase = 1; testCase <= testCaseNum; ++testCase) {
		scanf("%d%d", &N, &L);
		for (int i = 0; i < N; ++i) scanf("%s", a[i]);
		for (int i = 0; i < N; ++i) scanf("%s", b[i]);
		
		memset(diff, 0, sizeof(diff));
		s.clear();
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				for (int k = 0; k < L; ++k) 
					if (a[i][k] != b[j][k])
						diff[i][j] += 1ll << k;
				if (s.find(diff[i][j]) == s.end()) s[diff[i][j]] = 0;
				s[diff[i][j]]++;
			}
		
		int ans = 1 << 30;
		for (mapi64::iterator z = s.begin(); z != s.end(); ++z) {
			if (z->second < N) continue;
			int64 d = z->first;
			memset(v, 0, sizeof(v));
			int succ = 1;
			for (int i = 0; i < N && succ; ++i) {
				succ = 0;
				for (int j = 0; j < N; ++j)
					if (diff[i][j] == d && !v[j]) v[j] = succ = 1;
			}
			if (!succ) continue;
			int now = 0;
			for (int64 x = d; x; x -= x & (-x)) ++now;
			ans = min(ans, now);
		}
		
		printf("Case #%d: ", testCase);
		if (ans == 1 << 30) printf("NOT POSSIBLE\n"); else printf("%d\n", ans);
	}
}