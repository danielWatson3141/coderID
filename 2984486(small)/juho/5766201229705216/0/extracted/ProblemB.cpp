#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N;

vector<int> conn[1000];
int subCnt[1000][1000];

int bestCnt[1000][1000];

int minCut = 10000;

int getSubCnt(int parent, int child)
{
	if (subCnt[parent][child] > 0) {
		return subCnt[parent][child];
	}

	int sum = 1;
	int len = conn[child].size();
	for (int i = 0; i < len; i++) {
		int nei = conn[child][i];
		if (parent == nei) {
			continue;
		}
		sum += getSubCnt(child, nei);
	}

	subCnt[parent][child] = sum;
	return sum;
}

int checkChild(int parent, int child)
{
	if (bestCnt[parent][child] >= 0) {
		return bestCnt[parent][child];
	}

	int size = conn[child].size();
	if (size == 1) {
		bestCnt[parent][child] = 0;
		return 0;
	}
	if (size == 2) {
		int vall;
		if (conn[child][0] != parent) {
			vall = getSubCnt(child, conn[child][0]);
		} else {
			vall = getSubCnt(child, conn[child][1]);
		}
		bestCnt[parent][child] = vall;
		return vall;
	}

	int val = 0;
	for (int i = 0; i < size; i++) {
		int nei = conn[child][i];
		if (nei == parent) {
			continue;
		}
		val += getSubCnt(child, nei);
	}

	int minVal = val;
	for (int i = 0; i < size - 1; i++) {
		int nei1 = conn[child][i];
		if (nei1 == parent) {
			continue;
		}
		int val1 = val + checkChild(child, nei1) - getSubCnt(child, nei1);
		for (int j = i + 1; j < size; j++) {
			int nei2 = conn[child][j];
			if (nei2 == parent) {
				continue;
			}
			int val2 = val1 + checkChild(child, nei2) - getSubCnt(child, nei2);
			if (val2 < minVal) {
				minVal = val2;
			}
		}
	}

	bestCnt[parent][child] = minVal;

	return minVal;
}

int checkRoot(int root)
{
	int size = conn[root].size();

	int val = 0;
	for (int i = 0; i < size; i++) {
		val += getSubCnt(root, conn[root][i]);
	}

	if (size == 1) {
		return val;
	}

	int minVal = val;
	for (int i = 0; i < size - 1; i++) {
		int child1 = conn[root][i];
		int val1 = val + checkChild(root, child1) - getSubCnt(root, child1);
		for (int j = i + 1; j < size; j++) {
			int child2 = conn[root][j];
			int val2 = val1 + checkChild(root, child2) - getSubCnt(root, child2);
			if (val2 < minVal) {
				minVal = val2;
			}
		}
	}
	return minVal;
}

void solve()
{
	for (int i = 0; i < N; i++) {
		int len = conn[i].size();
		for (int j = 0; j < len; j++) {
			int child = conn[i][j];
			subCnt[i][child] = 0;
			bestCnt[i][child] = -1;
		}
	}

	minCut = N - 1;
	for (int i = 0; i < N; i++) {
		int val = checkRoot(i);
		if (val < minCut) {
			minCut = val;
		}
	}
	printf("%d\n", minCut);
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);

		for (int j = 0; j < N; j++) {
			conn[j].clear();
		}

		for (int j = 0; j < N-1; j++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			conn[a].push_back(b);
			conn[b].push_back(a);
		}

		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
