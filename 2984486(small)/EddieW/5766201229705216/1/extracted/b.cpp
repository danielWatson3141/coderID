#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <deque>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

ifstream fin ("B-large.in");
ofstream fout ("bl.out");

#define cin fin
#define cout fout
#define dout cout
// #define NDEBUG

int treeSizeAt(int current, vector<vector<int>>& edges, bool* used) {
	vector<int> children = edges[current];
	if (children.size() == 1 || children.size() == 0) return 1;
	vector<int> childTreeSizes (children.size());
	for (int i = 0; i < children.size(); i++) {
		bool canUse = true;
		if (used[children[i]]) {
			canUse = false;
		}
		else {
			vector<int> childrensChildren = edges[children[i]];
			for (int j = 0; j < childrensChildren.size(); j++) {
				if (used[childrensChildren[j]] && childrensChildren[j] != current) {
					canUse = false;
					break;
				}
			}
		}
		if (canUse) {
			used[children[i]] = true;
			childTreeSizes[i] = treeSizeAt(children[i], edges, used);
			used[children[i]] = false;
		}
		else childTreeSizes[i] = 0;
	}
	int best = 0, best2 = 0;
	for (int i = 0; i < childTreeSizes.size(); i++) {
		if (childTreeSizes[i] > best) {
			best2 = best;
			best = childTreeSizes[i];
		}
		else if (childTreeSizes[i] > best2) {
			best2 = childTreeSizes[i];
		}
	}
	if (best2 == 0) return 1;
	return 1+best+best2;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		vector<vector<int>> edges (N+1);
		for (int n = 1; n <= N; n++) {
			vector<int> empty;
			edges[n] = empty;
		}
		bool used[1001] = {false};
		for (int n = 1; n <= N-1; n++) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		int bestTreeSize = 0;
		for (int n = 1; n <= N; n++) {
			used[n] = true;
			int treeSize = treeSizeAt(n, edges, used);
			used[n] = false;
			if (treeSize > bestTreeSize) {
				bestTreeSize = treeSize;
			}
		}
		cout << "Case #" << t << ": " << N-bestTreeSize << '\n';
	}
	return 0;
}