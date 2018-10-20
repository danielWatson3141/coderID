// Template.cpp by kevinptt 20140306
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <iostream>
#define REP(I, N) for(int I=0; I<(N); ++I)
#define REPP(I, A, B) for(int I=(A); I<(B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define MP make_pair
#define PB push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
//typedef pair<int,int> pii;

string all[2][155];
string tmp[155];
int main() {
	DRI(N);
	REP(casen, N) {
		printf("Case #%d: ", casen+1);
		DRII(n, l);
		REP(i, n) cin >> all[0][i];
		REP(i, n) cin >> all[1][i];
		sort(all[1], all[1]+n);
		int ans=1<<30, cnt;
		REP(i, n) {
			cnt=0;
			REP(j, n) tmp[j] = all[0][j];
			REP(j, l)
				if( all[0][0][j] != all[1][i][j] ) {
					++cnt;
					REP(k, n) tmp[k][j] = tmp[k][j]=='1'?'0':'1';
				}
			sort(tmp, tmp+n);
			bool done=true;
			REP(j, n)
				if( all[1][j] != tmp[j] ) { done=false; break; }
			if( done && cnt<ans ) ans=cnt;
		}
		if( ans<=l ) printf("%d\n", ans);
		else puts("NOT POSSIBLE");

	}

	return 0;
}

