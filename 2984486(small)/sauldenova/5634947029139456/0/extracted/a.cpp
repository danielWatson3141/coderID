//a.cpp
//By Saul de Nova

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <vector>

#define TR(container, it) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

using namespace std;

typedef long long int lli;
typedef pair<lli, pair<int, int> > plp;

const int MAXN = 152;
const int MAXL = 42;
const int IMPOSSIBRU = 1E9;

int N, L;
lli comb1[MAXN];
lli comb2[MAXN];
list<int> graph[MAXN];
set<plp> comb;

lli convToLong(int L, char* arr) {
	lli res = 0LL, pot = 1LL;
	//printf("%s ", arr);
	for(int i = L - 1; i >= 0; i--) {
		if(arr[i] == '1') {
			res += pot;
		}
		pot *= 2;
	}
	return res;
}

bool visited[MAXN];

int flow(int i) {
	if(i >= N) {
		return 0;
	}
	int maxFlow = 0;
	TR(graph[i], it) {
		if(!visited[*it]) {
			visited[*it] = true;
			maxFlow = max(maxFlow, flow(i + 1) + 1);
			visited[*it] = false;
		}
	}
	return maxFlow;
}

int countBits(int a) {
	int res = 0;
	while(a > 0) {
		a -= (a & -a);
		res++;
	}
	return res;
}

int calculateGraph(int lastComb) {
	memset(visited, false, sizeof(visited));
	int maxFlow = flow(0);
	if(maxFlow < N) {
		return IMPOSSIBRU;
	}
	return countBits(lastComb);
}

int main(void) {
	int T;
	char arr[MAXL];
	scanf(" %d", &T);
	for(int t = 0; t < T; t++) {
		scanf(" %d %d", &N, &L);
		for(int i = 0; i < N; i++) {
			scanf(" %s", arr);
			comb1[i] = convToLong(L, arr);
			//printf("%s->%lld ", arr, comb1[i]);
		}
		scanf("\n");
		for(int i = 0; i < N; i++) {
			scanf(" %s", arr);
			comb2[i] = convToLong(L, arr);
			//printf("%s->%lld ", arr, comb2[i]);
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				comb.insert(make_pair(comb1[i] ^ comb2[j], make_pair(i, j)));
			}
		}
		
		int lastComb = -1;
		int minRes = IMPOSSIBRU;
		TR(comb, it) {
			if(it->first != lastComb) {
				if(lastComb != -1) {
					minRes = min(minRes, calculateGraph(lastComb));
				}
				lastComb = it->first;
				for(int i = 0; i < N; i++) {
					graph[i].clear();
				}
			} 
			graph[it->second.first].push_back(it->second.second);
		}
		minRes = min(minRes, calculateGraph(lastComb));
		//printf("\n");
		if(minRes >= IMPOSSIBRU) {
			printf("Case #%d: NOT POSSIBLE\n", t + 1);
		} else {
			printf("Case #%d: %d\n", t + 1, minRes);
		}
		comb.clear();
	}
	return 0;
}
