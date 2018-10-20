#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

struct node {
	int index;
	int count;
	vector<int> connected;
};

struct node nodes[1001];
int N;

int count(int parent, int node) {
	int r = 1;
	for(vector<int>::iterator it = nodes[node].connected.begin(); it != nodes[node].connected.end(); ++it) {
		if (*it != parent)
			r += count(node, *it);
	}
	nodes[node].count = r;
}

int solve_r(int parent, int node) {
	int max[2] = {-1, -1};
	for(vector<int>::iterator it = nodes[node].connected.begin(); it != nodes[node].connected.end(); ++it) {
		if (*it == parent)
			continue;
		
		int r = nodes[*it].count - solve_r(node, *it);
		if (r >= max[0]) {
			max[1] = max[0];
			max[0] = r;
		} else if (r >= max[1])
			max[1] = r;
	}
	
	int r = 0;
	if (max[0] == -1 && max[1] == -1)
		r = 0;
	else if (max[1] == -1)
		r = nodes[node].count - 1;
	else
		r = nodes[node].count - max[0] - max[1] - 1;
	return r;
	//printf("%d %d %d\n", parent, node ,r);
}

int solve() {
	int min = N + 1;
	for (int root = 0; root < N ;root++) {
		count(root, root);
		int v = solve_r(root, root);
		if (v < min)
			min = v;
	}
	return min;
}
int main(int argc, char* argv[]) {
	int T;
	
	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for(int t=0; t<T; t++) {
			scanf("%d\n", &N);
			for(int i=0; i<N; i++) {
				nodes[i].connected.clear();
				nodes[i].index = i;
			}
			
			for(int i=0; i<N-1;i++) {
				int x, y;
				scanf("%d %d\n", &x, &y);
				x--; y--;
				nodes[x].connected.push_back(y);
				nodes[y].connected.push_back(x);
			}
			
			printf("Case #%d: %d\n", t+1, solve());
	}
	
	return 0;
}
