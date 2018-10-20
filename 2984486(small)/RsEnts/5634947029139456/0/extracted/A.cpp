#include <algorithm> 
#include <cassert> 
#include <cctype> 
#include <cmath> 
#include <complex> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <deque> 
#include <functional> 
#include <iterator> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <string> 
#include <valarray> 
#include <vector> 
#include <iomanip>

#define MaxN 1010

using namespace std;
typedef long long ll;
typedef long double ld;

char str[MaxN][MaxN], tt[MaxN][MaxN];
int N, L, Ans = 0, chan[110], T;
bool used[MaxN];

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int i, j, k, l, T0 = 0;
	scanf("%d", &T);
	for( ; T; --T) {
		scanf("%d%d", &N, &L);
		for(i = 1; i <= N; ++i) cin >> str[i];
		for(i = 1; i <= N; ++i) cin >> tt[i];
		Ans = ~0U >> 1;
		for(i = 1; i <= N; ++i) {
			memset(chan, 0, sizeof(chan));
			int ret = 0;
			for(j = 0; j < L; ++j)
				if(tt[i][j] != str[1][j]) {
					chan[j] = 1; ++ret;
				}
			memset(used, 0, sizeof(used));
			int fl2 = 1;
			for(j = 1; j <= N; ++j) {
				int fl1 = 0;
				for(k = 1; k <= N; ++k) {
					if(used[k]) continue;
					int fl = 1;
					for(l = 0; l < L; ++l) {
						int tmp = (tt[j][l] == str[k][l]);
						tmp ^= chan[l];
						if(tmp == 0) {
							fl = 0; break;
						}
					}
					if(fl) {
						used[k] = 1; fl1 = 1; break;
					}
				}
				if(!fl1) {
					fl2 = 0; break;
				} 
			}
			if(!fl2) continue;
			if(ret < Ans) Ans = ret;
		}
		if(Ans > 100000) printf("Case #%d: NOT POSSIBLE\n", ++T0);
		else printf("Case #%d: %d\n", ++T0, Ans);
	}
	return 0;
}
