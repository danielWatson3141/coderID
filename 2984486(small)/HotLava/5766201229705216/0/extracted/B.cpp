#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_subtrees(int node, int parent, vector<vector<int>>& adjacent, vector<int>& subtrees) {
	int sum =1;

	for(auto v : adjacent.at(node)) if(v != parent) sum += compute_subtrees(v, node, adjacent, subtrees);

	subtrees.at(node) = sum;

	return sum;
}


int compute(int node, int parent, vector<vector<int>>& adjacent, vector<int>& subtree_sizes) {
	int s = 0;
	int c1 = -1;

	for(auto v : adjacent.at(node))
		if( v != parent) { ++s; c1 = v; }

	//cout << s << endl;

	if(s == 0) return 0;

	if(s == 1) return subtree_sizes.at(c1);

	vector< pair<int,int>> sums;
	int ssum = 0;
	for(auto v : adjacent.at(node)) {
		if( v != parent) { 
			sums.push_back( make_pair(v, compute(v, node, adjacent, subtree_sizes)) );
			ssum += subtree_sizes.at(v);
		}
	}
	

	//sort(sums.begin(), sums.end(), [](pair<int,int> p1, pair<int, int> p2) {return p1.second > p2.second;} );

	
	//int c = 0;
	/*auto it = sums.begin();
	while(s > 2) { 
		c += subtree_sizes.at(it->first); 
		it++;
		--s; 
	}

	// s == 2
	c += it->second;
	it++;
	c += it->second;*/

	int c = 2000;
	for(int i=0; i<s; ++i) for(int j=i+1; j<s; ++j) {
		int cost = sums.at(i).second + sums.at(j).second + ssum - subtree_sizes.at(sums.at(i).first) - subtree_sizes.at(sums.at(j).first);
		c = min(c, cost);
	}

	//cout << "cost " << node << " = " << c << endl;

	return c;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		vector<vector<int>> adjacent(n+1);

		for(int i=0; i<n-1; ++i) {
			int x,y;
			cin >> x >> y;

			adjacent.at(x).push_back(y);
			adjacent.at(y).push_back(x);
		}

		int mincost = 2000;
		for(int root=1; root<=n; ++root) {
			vector<int> subtree_sizes(n+1);
			compute_subtrees(root, -1, adjacent, subtree_sizes);
			int cost = compute(root, -1, adjacent, subtree_sizes);
			if(cost < mincost) {
				//cout << root << " gives " << cost << endl;
				mincost = cost;
			}
		}

		cout << "Case #" << i+1 << ": " << mincost << endl;
	}
}