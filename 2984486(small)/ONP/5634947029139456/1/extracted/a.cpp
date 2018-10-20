#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

long long w[200], h[200], g[200];
int n, L;
char ch;
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &L);
		for (int i = 0; i < n; i++) {
			w[i] = 0;
			for (int j = 0; j < L; j++) {
				scanf(" %c", &ch);
				w[i] = w[i] * 2 + (ch - '0');
			}
		}
		for (int i = 0; i < n; i++) {
			h[i] = 0;
			for (int j = 0; j < L; j++) {
				scanf(" %c", &ch);
				h[i] = h[i] * 2 + (ch - '0');
			}
		}
		sort(w, w + n);
		int ans = 192837465;
		for (int i = 0; i < n; i++) {
			long long delta = w[0] ^ h[i];
			for (int j = 0; j < n; j++)
				g[j] = h[j] ^ delta;
			sort(g, g + n);
			int flag = 1;
			for (int j = 0; j < n; j++)
				if (g[j] != w[j]) {
					flag = 0;
					break;
				}
/*			for (int j = 0; j < n; j++)
				cout << h[j] << ' ';
				cout << endl;
			for (int j = 0; j < n; j++)
				cout << g[j] << ' ';
				cout << endl;
			for (int j = 0; j < n; j++)
				cout << w[j] << ' ';
				cout << endl;*/
			if (flag) {
				int nn = 0;
				while (delta > 0) {
					nn += delta % 2;
					delta /= 2;
				}
				ans = min(nn, ans);
			}
		}
		if (ans > L)
			printf("Case #%d: NOT POSSIBLE\n", ++ca);
		else 
			printf("Case #%d: %d\n", ++ca, ans);
	}
}
