#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
typedef long long ll;

int n, t, l, best;
char ent[50];
ll outlets[160];
int sum[50];
int sum2[50];
set<ll> mapa;

void invert(int x) {
	for (int i = 0; i < n; ++i) {
		outlets[i] ^= (1LL)<< x;
	}
}

void go(int at, int usado) {
	if (usado > best) return;
	if (at == l) {
		for(int i = n-1; i >= 0; --i){
			if (mapa.find(outlets[i]) == mapa.end()) return;
		}
		best = usado;
		return;
	}
	if(sum[at] == sum2[at])
		go(at+1, usado);
	invert(at);
	go(at+1, usado+1);
	invert(at);
}

int main () {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++){
		memset(sum, 0, sizeof sum);
		memset(sum2, 0, sizeof sum2);
		printf("Case #%d:", _);
		scanf("%d %d", &n, &l);
		best = 99;
		mapa.clear();
		for(int i = 0; i < n; ++i){
			scanf("%s", ent);
			ll device = 0;
			for(int j = 0; j < l; ++j){
				ll val = ent[j]-'0';
				device += val << (l-j-1);
				sum[l-j-1] += val;
			}
			mapa.insert(device);
		}
		for(int i = 0; i < n; ++i){
			scanf("%s", ent);
			ll outlet = 0;
			for(int j = 0; j < l; ++j){
				ll val = ent[j]-'0';
				outlet += val << (l-j-1);
				sum2[l-j-1] += val;
			}
			outlets[i] = outlet;
		}
		for(int i = 0; i < l; ++i) {
			if(sum[i] != sum2[i] && sum[i] != (n-sum2[i])) goto skip;
		}
		go(0,0);
			skip:
		if(best == 99) printf(" NOT POSSIBLE\n");
		else printf(" %d\n", best);
	}
return 0;
}