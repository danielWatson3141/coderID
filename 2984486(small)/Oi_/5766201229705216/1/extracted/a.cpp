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

int n, t; 
typedef pair<int,int> pii;

vector<int> grafo[1001];
int best = 9999;
int ret1 = 0;
int ret2 = 0;

void bin(int at, int pai) {
	vector<pii> custos;
	int filhos = 0;
	int custo = 0;
	for(int i = 0; i < grafo[at].size(); ++i){
		int nxt = grafo[at][i];
		if(nxt == pai) continue;
		bin(nxt,at);
		filhos += ret2;
		custos.push_back(pii(ret2-ret1,ret1));
		//custos.push_back(bin(nxt,at));
	}
	sort(custos.begin(), custos.end());
	if(custos.size() == 1){
		custo = custos[0].first + custos[0].second;
	} else if(filhos > 1) {
		int asd = 0;
		//printf("alo\n");
		for(int i = custos.size()-1; i >= 0; --i) {
			//printf("se nao pegar custa %d a mais\n", custos[i].first);
			if(asd < 2) {
				custo += custos[i].second;
			} else custo += custos[i].second+custos[i].first;
			asd++;
		}
	}
	
	ret2 = filhos+1;
	ret1 = custo;
	//printf("at %d tenho %d nos e custo %d\n", at, ret2, ret1);
	
}

int main () {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++){
		printf("Case #%d: ", _);
		scanf("%d", &n);
		for(int i = 0; i < 1001; ++i) grafo[i].clear();
		for(int i = 0; i < n-1; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		best = 9999;
		for(int i = 1; i <= n; ++i) {
			bin(i, -1);
			//printf("serve %d\n", ret1);
			best = min(best, ret1);
			//best = min(best,bin(i,-1));
		}
		printf("%d\n", best);

	}
return 0;
}