#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

struct Tflow {
	int v[MaxN],next[MaxN],h[MaxN],tot,c[MaxN];
	void clr() { Fill(h,tot = 0); }
	void add(int b,int e,int f) { //cerr << b << ' ' << e << ' ' << f << endl;
		v[++tot] = e; next[tot] = h[b]; h[b] = tot; c[tot] = f;
		v[++tot] = b; next[tot] = h[e]; h[e] = tot; c[tot] = 0;
	}
	int S,T,d[MaxN],flow,found,gap[MaxN],cur[MaxN],ans;
	void aug(int i) {
		if (i == T) {
			ans += flow; found = true;
			return ;
		}
		int mind = T, tf = flow, z;
		for (z = cur[i]; z; z = next[z]) if (c[z]) {
			if (d[v[z]] + 1 == d[i]) {
				flow = min(flow,c[z]); cur[i] = z;
				aug(v[z]);
				if (found) break ; if (d[S] >= T) return ;
				flow = tf; 
			} mind = min(mind,d[v[z]]);
		}
		if (found) {
			c[z] -= flow; c[(z & 1) ? (z + 1) : (z - 1)] += flow;
		} else {
			if (--gap[d[i]] == 0) d[S] = T;
			for (int z = h[i]; z; z = next[z]) if (c[z]) mind = min(mind,d[v[z]]);
			++gap[d[i] = mind + 1]; cur[i] = h[i];
		}
	}
	void isap() {
		ans = 0; Fill(d,0); Fill(gap,0); gap[0] = T; For(i,1,T) cur[i] = h[i];
		while (d[S] < T) {
			flow = INF; found = false ;
			aug(S);
		}
	}
	int Sol(int _s,int _t) {
		S = _s; T = _t;
		isap();
		return ans;
	}
} TF;

int n,L;
long long a[MaxN],b[MaxN];
map<long long,int> MAP;
int main() {
	freopen("input.txt","r",stdin); freopen("output2.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) {
		printf("Case #%d: ",TTT);
		cin >> n >> L;
		For(i,1,n) {
			scanf(" ");
			long long t = 0;
			For(j,1,L) {
				t = (t << 1) + (getchar() == '1');
			}
			a[i] = t;
		}
		For(i,1,n) {
			scanf(" ");
			long long t = 0;
			For(j,1,L) {
				t = (t << 1) + (getchar() == '1');
			}
			b[i] = t;
		}
		int ans = INF;
		For(i,1,n) {
			cerr << i << endl;
			long long Mask = a[1] ^ b[i];
			MAP.clear();
			For(j,1,n) ++MAP[a[j] ^ Mask];
			bool valid = true;
			For(j,1,n) if (!MAP.count(b[j])) valid = false ;
			else if (MAP[b[j]] == 0) valid = false ;
			else --MAP[b[j]];
			if (valid) ans = min(ans,__builtin_popcountll(Mask));
		}
		if (ans > 50) puts("NOT POSSIBLE");
		else cout << ans << endl;
	}
	return 0;
}

