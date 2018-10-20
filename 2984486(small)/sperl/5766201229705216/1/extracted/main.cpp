#include <stdio.h>

#include <vector>
#include <list>

#define N_MAX 1002

int N;

std::vector<int> tree[N_MAX];


int count(int node, int comeFrom) {
	if (tree[node].size() >= 3 || comeFrom == -1) {
		// continue		
		std::list<int> maxes;
		for (int i = 0; i < tree[node].size(); i++) {
			if (tree[node][i] != comeFrom) {
				maxes.push_back(count(tree[node][i], node));
			}
		}
		
		maxes.sort();
		
		int res = 1 + maxes.back();
		maxes.pop_back();
		return res + maxes.back();
	}
	
	return 1;
}

int main() {
	
	int T = 0;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++)  {
		scanf("%d\n", &N);
		
		for (int i = 0; i < N_MAX; i++) {
			tree[i].clear();
		}
		
		for (int i = 0; i < N-1; i++) {
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			
			tree[n1-1].push_back(n2-1);
			tree[n2-1].push_back(n1-1);
		}
		
		int max = 1;
		int node = 0;
		
		for (int i = 0; i < N; i++) {
			if (tree[i].size() >= 2) {
				// check if this is root
				//printf("try %d\n", i);
				int res = count(i, -1);
				if (res > max) {
					max = res;
					node = i;
				}
			}
		}
		
		//printf("node = %d\n", node+1);
		
		int del = N-max;
		
		printf("Case #%d: %d\n", t, del);
		
	}
}


