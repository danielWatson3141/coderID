#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<list>
using namespace std;

int N, P[1024], DP[1024][2], ans;
list<int> E[1024], CH[1024];

inline void setParent(int x, int p) {
//	fprintf(stderr, "%d %d\n", x, p);
	P[x] = p;
	CH[p].push_back(x);
	for(list<int>::iterator itr = E[x].begin(); itr != E[x].end(); ++itr)
		if(*itr != p) setParent(*itr, x);
}

inline void updateAns(int a) {
	if(ans < a) ans = a;
}

inline void getDP(int x) {
	//fprintf(stderr, "get %d\n", x);
	for(list<int>::iterator itr = CH[x].begin(); itr != CH[x].end(); ++itr)
		getDP(*itr);
	int nch = CH[x].size();
	if(nch == 0) {
		DP[x][0] = 1;
		DP[x][1] = -10000;
	} else if(nch == 1) {
		DP[x][0] = 1;
		DP[x][1] = P[x]!=0 ? (1 + DP[*CH[x].begin()][0]) : -1000;
		updateAns(1+DP[*CH[x].begin()][1]);
	} else {
		int norid[4], nor[4] = {0}, wrid[4], wr[4] = {0};
		for(list<int>::iterator itr = CH[x].begin(); itr != CH[x].end(); ++itr) {
			int y = *itr;
			if(nor[3] < DP[y][0]) {
				nor[3] = DP[y][0], norid[3] = y;
				for(int i = 3; i > 0; --i) if(nor[i] > nor[i-1]) {
					nor[i] ^= nor[i-1] ^= nor[i] ^= nor[i-1];
					norid[i] ^= norid[i-1] ^= norid[i] ^= norid[i-1];
				}
			}
			if(wr[3] < DP[y][1]) {
				wr[3] = DP[y][1], wrid[3] = y;
				for(int i = 3; i > 0; --i) if(wr[i] > wr[i-1]) {
					wr[i] ^= wr[i-1] ^= wr[i] ^= wr[i-1];
					wrid[i] ^= wrid[i-1] ^= wrid[i] ^= wrid[i-1];
				}
			}
		}
		DP[x][0] = nor[0] + nor[1] + 1;
		if(wrid[0] != norid[0]) DP[x][1] = wr[0] + nor[0] + 1;
		else DP[x][1] = max(wr[0]+nor[1], wr[1]+nor[0]) + 1;
		if(nch >= 3) {
			for(int i = 0; i < 3; ++i) {
				int wid = wrid[i], ww = wr[i];
				if(wid != norid[0] && wid != norid[1])
					updateAns(ww+nor[0]+nor[1]+1);
				else if(wid != norid[0]) updateAns(ww+nor[0]+nor[2]+1);
				else updateAns(ww+nor[1]+nor[2]+1);
			}
		}
		updateAns(DP[x][0]);
		updateAns(1+wr[0]);
	}
	//if(P[x] != 0 && ans < DP[x][1]) ans = DP[x][1];
	//fprintf(stderr, "%d\t%d %d\t%d\n", x, DP[x][0], DP[x][1], ans);
}

int main() {
	int TT;
	scanf("%d", &TT);
	for(int T = 1;  T <= TT; ++T) {
		scanf("%d", &N);
		for(int i = 0; i <= N; ++i) E[i].clear(), CH[i].clear();
		for(int i = 1; i < N; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		ans = 1;
		setParent(1, 0);
		getDP(1);
		printf("Case #%d: %d\n", T, N-ans);
	}
}


