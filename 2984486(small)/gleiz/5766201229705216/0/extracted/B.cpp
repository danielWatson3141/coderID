#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int visitId = 0;

class Node {
public:
	vector <int> next;
	int visit;
	int id;
	Node() {
		next = vector <int>();
	}
};

map <int, Node> nodes;

int selectNum = 0;

bool dfs(int root, int stamp, int& depth, int from) {
	int maxDepth = -1;
	int child = 0;
	bool res = true;
	
	for (auto iter = nodes[root].next.begin(); iter != nodes[root].next.end(); iter++) {
		if (from == *iter) {
			continue;
		}
		
		if (selectNum & (1 << (*iter - 1))) {
			child++;

			if (child > 2) {
				return false;
			}
			
			if (stamp == nodes[*iter].visit) {
				return false;
			}

			nodes[*iter].visit = stamp;

			int thisDepth = 0;
			res = res && dfs(*iter, stamp, thisDepth, root);

			if (res != true) {
				return false;
			}
			
			if (maxDepth == -1) {
				maxDepth = thisDepth;
			} else {
				if (thisDepth != maxDepth) {
					return false;
				}
			}
		}
	}

	if (child != 0 && child != 2) {
		return false;
	}

	return res;
}

inline int cnt(int mask, int N) {
	int res = 0;
	while (mask) {
		if (mask & 1) {
			res++;
		}
		mask /= 2;
	}

	res = N - res;
	return res;
}

int main(int argc, char *argv[])
{
    int T = 0;

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w+", stdout);
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int N = 0;
		int x = 0, y = 0;
		cin >> N;

		nodes.clear();
		
		for (int i = 0; i < N - 1; i++) {
			cin >> x >> y;
			if (nodes.count(x) <= 0) {
				nodes[x] = Node();
				nodes[x].id = x;
			}

			if (nodes.count(y) <= 0) {
				nodes[y] = Node();
				nodes[y].id = y;
			}
			nodes[x].next.push_back(y);
			nodes[y].next.push_back(x);
		}

		int res = N;
		int mask = 0;
		for (int i = 0; i < (1<<N); i++) {
			for (auto iter = nodes.begin(); iter != nodes.end(); iter++) {
				int id = iter->first;
				if (i & (1<<(id - 1))) {
					visitId++;
					selectNum = i;
					int depth = 0;
					nodes[id].visit = visitId;
						  
					if (dfs(id, visitId, depth, -1)) {
						int visitNum = 0;
						for (auto iter = nodes.begin(); iter != nodes.end(); iter++) {
							if (iter->second.visit == visitId) {
								visitNum++;
							}
						}
						
						int tmp = cnt(i, N);
						if (N - tmp == visitNum && tmp < res) {
							res = tmp;
							mask = i;
							break;
						}
					}
				}
			}
		}

		cout << "Case #" << cas << ": " << res << endl;
	}
    return 0;
}
