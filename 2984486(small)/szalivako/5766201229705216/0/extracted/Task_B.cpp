#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> l[10000];
bool mark[10000];

bool isTree;
int gmin = 1000000000;

void bfs(int v) {
	
	queue<int> q;
	q.push(v);

	mark[v] = true;
	int cnt = 0;
	for (int i = 0; i < l[v].size(); i++) {
		if (!isTree) {
			return;
		}
		if (!mark[l[v][i]]) {
			dfs(l[v][i]);
			cnt++;
		}
	}
	if (cnt != 0 && cnt != 2) {
		isTree = false;
	}
}


int main() {

	int T;
	scanf("%d", &T);
	
	for (int ti = 0; ti < T; ti++) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			l[i].clear();
		}
		gmin = 1000000000;

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			l[x - 1].push_back(y - 1);
			l[y - 1].push_back(x - 1);
		}

		for (int i = 0; i < n; i++) {
			isTree = true;
			dfs(i);

			for (int j = 0; j < n; j++) {
				if (!mark[j]) {
					isTree = false;
				}
			}

			if (isTree) {
				if (cnt < gmin) {
					gmin = cnt;
				}
			}
		}

		printf("Case #%d: %d\n", ti + 1, gmin);
		
	}

	
	

}