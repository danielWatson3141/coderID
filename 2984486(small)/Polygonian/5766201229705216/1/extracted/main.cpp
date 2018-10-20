#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

enum { MAX = 2000 };

vector<int> E[MAX];
int N;

typedef pair<int, int> PII;

PII recurse(int parent, int current) {  // return how many to delete to make this node full;
	vector<int> r;
	int killall = 0;
	int keepall = 0;
	for (int i = 0; i < int(E[current].size()); i++) {
		if (E[current][i] == parent) continue;
		PII x = recurse(current, E[current][i]);
		// cout << "recurse(" << current + 1 << "," << E[current][i] + 1 << ", parent = " << parent << "): keep = " << x.first << ", kill = " << x.second << endl;
		r.push_back(x.first - x.second);
		keepall += x.first;
		killall += x.second;
	}
	if (r.size() == 0) {
		return make_pair(0, 1);  // no child;
	} else if (r.size() == 1) {
		return make_pair(killall, 1 + killall);  // one;
	} else {
		// cout << "HERE: ";
		sort(r.begin(), r.end());
		int cost = r[0] + r[1] + killall;  // cost of killing all but two;
		// for (int i = 0; i < int(r.size()); i++) {
		// 	cout << r[i] << " ";
		// }
		// cout << endl;

		int keepcost = cost;
		int killcost = 1 + killall;
		return make_pair(keepcost, killcost);
	}
}

void solve(int CASE) {
	scanf("%d", &N);
	for (int i = 0; i < MAX; i++)
		E[i].clear();
	for (int i = 0; i < N - 1; i++) {
		int from, to;
		scanf("%d%d", &from, &to);
		from--;
		to--;
		E[from].push_back(to);
		E[to].push_back(from);
	}

	int best = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (E[i].size() == 0) continue;
		PII result = recurse(-1, i);
		if (result.first < best) best = result.first;
	}


	printf("Case #%d: %d\n", CASE, best);
}

int main(void) {
	int Q;
	scanf("%d", &Q);
	for (int q = 0; q < Q; q++) {
		solve(q + 1);
	}
	return 0;
}
