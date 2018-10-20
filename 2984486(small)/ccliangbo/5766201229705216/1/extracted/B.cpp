#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<cfloat>

#include<iostream>
#include<string>
#include<limits>
#include<sstream>

#include<utility>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;
typedef long long LL;
#undef DEBUG
int n;
int adj[1010][1010];
bool used[1010];
int search(int root) {
#ifdef DEBUG
	printf("begin search, root = %d\n",root);
#endif
	vector<int> child;
	for (int i = 1; i <= n; i++) {
		if (adj[root][i] == 1 && used[i] == false) {
			child.push_back(i);
		}
	}
	if (child.size() < 2) {
		return 1;
	}
	vector<int> childRes;
	for (int i = 0; i < child.size(); i++) {
		used[child[i]] = true;
		childRes.push_back(search(child[i]));
		used[child[i]] = false;
	}
	sort(childRes.begin(), childRes.end());
	return childRes[childRes.size() - 1] + childRes[childRes.size() - 2] + 1;
}
int main() {
	int caseNum;
	char dummy; //read the '\n' after the caseNum
	scanf("%d%c", &caseNum, &dummy);
	for (int caseCount = 1; caseCount <= caseNum; caseCount++) {
		scanf("%d", &n);
		int i;
		memset(adj, 0, sizeof(adj));
		for (i = 1; i < n; i++) {
			int from, to;
			scanf("%d%d", &from, &to);
			adj[from][to] = 1;
			adj[to][from] = 1;
		}
		fill(used, used + 1010, false);
		int res = 0;
		for (i = 1; i <= n; i++) {
			used[i] = true;
			int t = search(i);
			used[i] = false;
			if (t > res)
				res = t;
		}
		printf("Case #%d: %d\n", caseCount, n - res);
	}
	return 0;
}
