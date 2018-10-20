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

bool grafo[20][20];
int tam[20];
bool rem[20];
bool mark[20];
int best = 20;
int tot = 0;

int bin(int at, int pai) {
	if(mark[at]) return -9999;
	mark[at] = true;
	int fil = 0;
	int check = 0;
	for(int i = 1; i <= n; ++i){
		if(i == pai || rem[i]) continue;
		if(grafo[at][i]){
			check++;
			int tmp = bin(i,at);
			if(tmp < 0) {
				mark[at] = false;
				return -9999;
			}
			fil += tmp;
		}
	}
	mark[at] = false;
	if(check != 0 && check != 2) return -9999;
	return fil+1;
}

void go(int at){
	if(at == n) {
		for(int i = 1; i <= n; ++i) {
			if(bin(i,-1) == n-tot){
				best = min(best,tot);
				return;
			}
		}
		return;
	}
	go(at+1);
	rem[at+1] = true;
	tot++;
	go(at+1);
	rem[at+1] = false;
	tot--;
}

int main () {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++){
		printf("Case #%d: ", _);
		scanf("%d", &n);
		memset(grafo, 0, sizeof grafo);
		memset(tam, 0, sizeof tam);
		memset(rem, 0, sizeof rem);
		memset(mark, 0, sizeof mark);
		for(int i = 0; i < n-1; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			grafo[a][b] = grafo[b][a] = 1;
			tam[a]++;
			tam[b]++;
		}
		best = 20;
		go(0);
		printf("%d\n", best);

	}
return 0;
}