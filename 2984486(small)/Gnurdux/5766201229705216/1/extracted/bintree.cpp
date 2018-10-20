#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> neighbors[1000];

int bestTree(int root, int parent) {
	int bestChild = -10000, secondBestChild = -10000;
	for (int neighbor : neighbors[root]) {
		if (neighbor == parent) continue;
		int cand = bestTree(neighbor, root);
		if (cand > bestChild) {
			secondBestChild = bestChild;
			bestChild = cand;
		} else if (cand > secondBestChild) {
			secondBestChild = cand;
		}
	}
	if (bestChild > 0 && secondBestChild > 0) return 1 + bestChild + secondBestChild;
	else return 1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N-1; i++) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			neighbors[a].push_back(b);
			neighbors[b].push_back(a);
		}

		// We can afford to, so just brute force over all possible roots
		int best = 0;
		for (int i = 0; i < N; i++) {
			int cand = bestTree(i, -1);
			if (cand > best) best = cand;
		}
		cout << "Case #" << t << ": " << N-best << '\n';

		for (int i = 0; i < N; i++) {
			neighbors[i].clear();
		}
	}
	return 0;
}
