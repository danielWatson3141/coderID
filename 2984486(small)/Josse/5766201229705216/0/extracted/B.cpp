// Not the best solution ever. It's late, I'm tired. Sorrrry.

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

struct node {
	vector<node*> children;
	int descendants;
	int cur; // for debugging purpose
	node(int _cur) : descendants(1), cur(_cur) {}
	~node() {
		//cerr << "  deleting node " << cur+1 << endl;
		for (vector<node*>::iterator it = children.begin(); it != children.end(); it++) {
			delete *it;
		}
		children.clear();
	}
	void add(node* n) {
		children.push_back(n);
		descendants += n->descendants;
	}
	int findMin() {
		if (children.size() == 0) return 0;
		if (children.size() == 1) return children[0]->descendants;
		priority_queue<int> q;
		for (vector<node*>::iterator it = children.begin(); it != children.end(); it++) {
			node* n = *it;
			int p = n->descendants - n->findMin();
			assert(p >= 0);
			q.push(p);
		}
		int A = q.top();
		q.pop();
		int B = q.top();
		int ret = this->descendants - A - B - 1;
		if (children.size() == 2) assert(ret == children[0]->findMin() + children[1]->findMin());
		return ret;
	}
};

int N;
vector<int> buren[1000];

node* makeTree(int cur, int prev) {
	node* n = new node(cur);
	for (vector<int>::iterator it = buren[cur].begin(); it != buren[cur].end(); it++) {
		if (*it != prev)
			n->add(makeTree(*it, cur));
	}
	return n;
}

int solve() {
	cin >> N;
	assert(N >= 2 && N <= 1000);
	for (int i = 1; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		X--; Y--;
		assert(X >= 0 && X < N);
		assert(Y >= 0 && Y < N);
		buren[X].push_back(Y);
		buren[Y].push_back(X);
	}
	int best = N;
	for (int i = 0; i < N; i++) {
		node* t = makeTree(i, -1);
		best = min(best, t->findMin());
		delete t;
	}
	for (int i = 0; i < N; i++) buren[i].clear();
	assert(best < N);
	return best;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
		cout << "Case #" << i+1 << ": " << solve() << endl;
	return 0;
}
