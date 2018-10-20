#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int height(vector<set<int> > &tree, int root) {
	vector<int> heights;
	for (auto it = tree[root].begin(); it != tree[root].end(); ++it) {
		tree[*it].erase(root);
		heights.push_back(height(tree, *it));
		tree[*it].insert(root);
	}
	sort(heights.begin(), heights.end());
	if (heights.size() < 2) {
		return 1;
	}
	else {
		return 1 + heights[heights.size() - 2] + heights[heights.size() - 1];
	}
}

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");

	int T;
	in >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		in >> N;
		vector<set<int> > tree;
		for (int j = 0; j < N + 1; ++j) {
			tree.push_back(set<int>());
		}
		for (int j = 0; j < N - 1; ++j) {
			int a, b;
			in >> a >> b;
			tree[a].insert(b);
			tree[b].insert(a);
		}
		int bestHeight = 0;
		for (int j = 1; j <= N; ++j) {
			bestHeight = max(bestHeight, height(tree, j));
		}
		out << "Case #" << i + 1 << ": " << (N - bestHeight) << endl;
	}
	return 0;
}