#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

int N;

map<int, vector<int>> G;

void readCase()
{
	G.clear();
	cin >> N;
	
	for(int i = 0; i < N - 1; i++) {
		int X = 0;
		int Y = 0;
		cin >> X >> Y;
		X--;
		Y--;
		G[X].push_back(Y);
		G[Y].push_back(X);
	}
}

int count(int r, int pred = -1)
{
	int cnt = 0;
	for(int j = 0; j < G[r].size(); j++) {
		if(G[r][j] != pred) cnt += count(G[r][j], r);
	}
	return cnt + 1;
}

int solve(int r, int pred = -1)
{
	int cnt = 0;
	int c = 0;
	for(int j = 0; j < G[r].size(); j++) {
		if(G[r][j] != pred) cnt++, c = j;
	}

	if(cnt == 1) {
		return count(G[r][c], r);
	}

	cnt = 0;
	for(int j = 0; j < G[r].size(); j++) {
		if(G[r][j] != pred) cnt += solve(G[r][j], r);
	}

	return cnt;
}

void solve()
{
	int best = INT_MAX;

	for(int r = 0; r < N; r++) {
		int cur = solve(r);
		best = min(cur, best);
	}

	cout << best;
}

int main()
{
	//string fname = "./test/B-example.in";
	string fname = "./test/B-small-attempt0.in";
	//string fname = "./test/B-small-practice.in";
	//string fname = "./test/B-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

