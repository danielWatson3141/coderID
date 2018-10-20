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

int N, T, siz[MaxN], m0, head[MaxN], prep[MaxN], v[MaxN], Ans;
bool used[MaxN], Canbe[MaxN], db;

bool Can(int now, int pre, int S) {
	int cnt = 0, presiz = 0;
	siz[now] = 1;
	for(int i = head[now]; i; i = prep[i]) {
		if(v[i] != pre && (!Canbe[v[i]])) {
			++cnt;
			if(!Can(v[i], now, S)) return false;
		}
	}
	if(cnt == 0 || cnt == 2) return true;
	return false;
}

void Fill(int now) {
	used[now] = 1;
	for(int i = head[now]; i; i = prep[i])
		if((!used[v[i]]) && (!Canbe[v[i]]))
			Fill(v[i]);
}

void AddEdge(int a, int b) {
	++m0; v[m0] = b; prep[m0] = head[a]; head[a] = m0;
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int i, j, T0 = 0;
	scanf("%d", &T);
	for( ; T; --T) {
		scanf("%d", &N);
		memset(head, 0, sizeof(head));
		m0 = 0;
		for(i = 1; i < N; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			--a; --b;
			AddEdge(a, b);
			AddEdge(b, a);
		}
		Ans = N;
		for(i = 0; i < (1 << N); ++i) {
			int ret = 0;
			memset(used, 0, sizeof(used));
			memset(Canbe, 0, sizeof(Canbe));
			for(j = 0; j < N; ++j)
				if((i & (1 << j))) {
					Canbe[j] = 1;
					++ret;
				}
			int fl = 1;
			for(j = 0; j < N; ++j) {
				if((i & (1 << j)) == 0)
					Fill(j);
			}
			for(j = 0; j < N; ++j) {
				if((i & (1 << j))) {
					continue;
				}
				else {
					if(!used[j]) fl = 0;
				}
			}
			memset(used, 0, sizeof(used));
			if(!fl) continue;
			for(j = 0; j < N; ++j) {
				if((i & (1 << j)) == 0) {
					if(used[j]) continue;
					if(Can(j, N, i)) {
						Fill(j); break;
					}
					db = 0;
				}
			}
			for(j = 0; j < N; ++j) {
				if((i & (1 << j))) {
					continue;
				}
				else {
					if(!used[j]) fl = 0;
				}
			}
			if(ret < Ans && fl) {
				Ans = ret;
			}
		}
		printf("Case #%d: %d\n", ++T0, Ans);
	}
	return 0;
}
