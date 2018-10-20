#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 20;

int d[N];
int n, e;

int cntOnes(int x) {
	int ans = 0;
	while(x) {
		ans += x % 2;
		x /= 2;
	}
	return ans;
}

int main () {
	int i, j, k, ca, T;

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-out-attempt0.txt", "w", stdout);
	cin >> T;
	for (ca = 1; ca <= T; ++ca) {
		scanf ("%d", &n);
		vector<pair<int,int> > p;
		for (k = 1; k < n; ++k) {
			scanf ("%d%d", &i, &j);
			--i; --j;
			p.push_back(make_pair(i,j));
		}
		int ans = n - 1;
		for (int mask = 0; mask < (1<<n); ++mask) {
			memset(d, 0, sizeof(d));
			e = 0;
			for (i = 0; i < p.size(); ++i) {
				int first = p[i].first, second = p[i].second;
				if ( (mask &(1<<first)) || (mask &(1<<second)) ) continue;
				d[first]++;
				d[second]++;
				e++;
			}
			/*
			if (mask == 1) {
				printf ("e = %d\n", e);
				for (i = 0; i < n; ++i)
					printf ("%d%c", d[i], i == n - 1? '\n' : ' ');
			}*/
			int cnt2 = 0;
			for (i = 0; i < n; ++i) {
				if (mask & (1<<i)) continue;
				if (d[i] == 2) cnt2++;
				if (d[i] != 2 && d[i] != 1 && d[i] != 3) break;
			}
			int left = n - cntOnes(mask);
			if (i == n && cnt2 == 1 && e == left - 1) ans = min(ans, n - left);
		}
		printf ("Case #%d: %d\n", ca, ans);
	}
	return 0;
}
