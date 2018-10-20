#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


const int N = 222;
const int INF = 11111111;

vector<string> a, b, c, d;
int n, l;
char buf[111111];
int mark[N];

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for(int testCount = 1; testCount <= test; testCount++) {
		printf("Case #%d: ", testCount);
		scanf("%d %d", &n, &l);
		a.clear();
		b.clear();
		for(int i = 0; i < n; i++) {
			scanf("%s", buf);
			string tmp = buf;
			a.push_back(tmp);			
		} 
		for(int i = 0; i < n; i++) {
			scanf("%s", buf);
			string tmp = buf;
			b.push_back(tmp);
		}
		sort(b.begin(), b.end());
		int ans = INF;
		for(int i = 0; i < n; i++) {
			int cnt = 0;
			for(int j = 0; j < l; j++) {
				mark[j] = (a[0][j] != b[i][j]);
				cnt += mark[j];
			}
			c.clear();
			for(int j = 0; j < n; j++) {
				string tmp;
				for(int k = 0; k < l; k++) {
					tmp += (((a[j][k] - '0') ^ mark[k]) + '0');
				}
				c.push_back(tmp);
			}
			sort(c.begin(), c.end());
			if (b == c) {
				ans = min(ans, cnt);
			}
		}
		if (ans == INF) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
