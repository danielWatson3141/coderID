#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 10000;
string a[maxn], b[maxn], c[maxn];
bool h[maxn];

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int Cases;
	scanf("%d", &Cases);
	for (int C = 1; C <= Cases; ++C){
		printf("Case #%d: ", C);
		int n, L;
		scanf("%d%d", &n, &L);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i){
			cin >> b[i];
		}
		sort(b, b + n);

		int ans = -1;
		for (int i = 0; i < n; ++i){
			memset(h, false, sizeof(h));
			int tmp = 0;
			for (int k = 0; k < L; ++k)
				if (a[0][k] != b[i][k]){
					h[k] = true;
					++tmp;
				}

			for (int j = 0; j < n; ++j){
				c[j] = a[j];
				for (int k = 0; k < L; ++k)
					if (h[k]){
						if (c[j][k] == '0') c[j][k] = '1'; else c[j][k] = '0';
					}
			}
			sort(c, c + n);

			bool ok = true;
			for (int j = 0; j < n; ++j)
				if (c[j] != b[j]){
					ok = false;
					break;
				}
			if (ok && (ans == -1 || ans > tmp)) ans = tmp;
		}
		if (ans == -1) puts("NOT POSSIBLE"); else printf("%d\n", ans);
	}
	return 0;
}

