#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 1010;
int a[N], b[N], c[N];
__int64 ret;
void MergeSort(int l, int r) {
	if (l < r) {
		int mid = (l + r) >> 1;
		MergeSort(l, mid);
		MergeSort(mid + 1, r);
		int i = l, j = mid + 1, k = l;
		for (; i <= mid && j <= r; ) {
			if (a[i] <= a[j]) {
				c[k++] = a[i++];
			}
			else {
				ret += j - k;
				c[k++] = a[j++];
			}
		}
		while (i <= mid) c[k++] = a[i++];
		while (j <= r) c[k++] = a[j++];
		for (i = l; i <= r; ++i) a[i] = c[i];
	}
}
double anv[1010];
int main() {
	freopen("C-small-attempt6.in", "r", stdin);
	freopen("C-out.txt", "w", stdout);
	anv[1] = 0; double t = 0.5;
	for (int i = 2; i <= 1000; ++i) {
		anv[i] = anv[i - 1] + t;
		t += 0.5;
	}

	int n;
	int ca = 1; int T;
	int cc = 0;
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		rep(i, n) scanf("%d", &a[i]);
		ret = 0;
		MergeSort(0, n - 1);
		printf("Case #%d: ", ca++);
		double x = 1.0 * fabs(ret - anv[n]) / anv[n];
		if (x < 0.025) {
			++cc;
			puts("GOOD");
		} else {
			puts("BAD");
		}
	}
	cerr<<cc<<endl;
	return 0;
}


