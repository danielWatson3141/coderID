#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

string a[1000], b[1000], c[1000];
int q[100];
int n, m;

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int Tests, tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			char x[50];
			scanf("%s", x);
			a[i] = x;
		}
		for (int i = 1; i <= n; ++i) {
			char x[50];
			scanf("%s", x);
			b[i] = x;
		}

		sort(a + 1, a + n + 1);

		int ans = m + 1;
		for (int i = 1; i <= n; ++i) {
			q[0] = 0;
			for (int j = 0; j < m; ++j)
				if (a[1][j] != b[i][j]) q[++q[0]] = j;

			if (q[0] < ans) {
				for (int j = 1; j <= n; ++j) {
					c[j] = b[j];
					for (int k = 1; k <= q[0]; ++k)
						c[j][q[k]] = 97 - c[j][q[k]];
				}
				sort(c + 1, c + n + 1);
				int ff = 1;
				for (int j = 1; j <= n; ++j)
					if (a[j] != c[j]) {
						ff = 0;
						break;
					}
				if (ff) ans = q[0];
			}
		}

		printf("Case #%d: ", ++tts);
		if (ans == m + 1) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}