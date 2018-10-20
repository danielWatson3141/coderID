#include <stdio.h>
#include <numeric>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int vcnt;
int v[1000];
vector<int> gnext[1000];

int rec(int nod) {
	v[nod] = vcnt;
	vector<int> childrenSize;
	for(auto next : gnext[nod]) {
		if (v[next] == vcnt) continue;
		childrenSize.emplace_back(rec(next));
		if (childrenSize.size() >= 3) {
			sort(childrenSize.begin(), childrenSize.end(), greater<int>());
			childrenSize.pop_back();
		}
	}
	if (childrenSize.size() <= 1) return 1;
	return 1 + childrenSize[0] + childrenSize[1];
}

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) {
			gnext[i].clear();
		}
		for(int i = 0; i + 1 < n; i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			gnext[x].push_back(y);
			gnext[y].push_back(x);
		}
		int ans = 1;
		for(int i = 0; i < n; i++) {
			++vcnt;
			ans = max(ans, rec(i));
		}
		printf("Case #%d: %d\n", testcase, n - ans);
	}
	return 0;
}
