#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 155

vector<int> wl, wr; 
int n, L, Ll, Lr; 
int pl[N], pr[N]; 
int al[N], ar[N];
int bl[N], br[N];
ll p[N], a[N], b[N]; 

void getw(int &l, int&r, ll &p) {
	string s; 
	cin >> s; 
	l = r = p = 0; 
	for (int i = 0; i < Ll; i ++) 
		(l *= 2) += (s[i] == '1'); 
	for (int i = Ll; i < Ll + Lr; i ++) 
		(r *= 2) += (s[i] == '1');
	for (int i = 0; i < Ll + Lr; i ++) 
		(p *= 2) += (s[i] == '1'); 
}

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
		wl.clear(); wr.clear(); 
		cin >> n >> L; 
		Ll = L/2; Lr = L-Ll; 
		for (int i = 0; i < n; i ++) getw(pl[i], pr[i], p[i]); 
		for (int i = 0; i < n; i ++) getw(al[i], ar[i], a[i]); 
		sort(pl, pl+n); 
		sort(pr, pr+n); 
		for (int k = 0; k < (1 << Ll); k ++) {
			for (int i = 0; i < n; i ++) {
				bl[i] = al[i] ^ k; 
			}
			sort(bl, bl+n); 
			bool F = true; 
			for (int i = 0; i < n; i ++) 
				if (bl[i] != pl[i]) {F = false; break;}
			if (!F) continue; 
			wl.pb(k); 
		}
		for (int k = 0; k < (1 << Lr); k ++) {
			for (int i = 0; i < n; i ++) {
				br[i] = ar[i] ^ k; 
			}
			sort(br, br+n); 
			bool F = true; 
			for (int i = 0; i < n; i ++) 
				if (br[i] != pr[i]) {F = false; break;}
			if (!F) continue; 
			wr.pb(k); 
		}
		int S = L+1; 
		sort(p, p+n); 
		for (int k1 = 0; k1 < (int) wl.size(); k1 ++) 
			for (int k2 = 0; k2 < (int) wr.size(); k2 ++) {
				int kl = wl[k1]; 
				int kr = wr[k2]; 
				int T = pct(kl) + pct(kr); 
				if (T >= S) continue; 
				ll k = (((long long)kl) << Lr)+kr; 
				for (int i = 0; i < n; i ++) 
					b[i] = a[i]^k; 
				sort(b, b+n); 
				bool F = true; 
				for (int i = 0; i < n; i ++) 
					if (b[i] != p[i]) {F = false; break; }
				if (!F) continue; 
				S = T; 
			}
		printf ("Case #%d: ", __); 
		if (S > L) puts ("NOT POSSIBLE"); else printf ("%d\n", S); 
	}
	return 0; 
}