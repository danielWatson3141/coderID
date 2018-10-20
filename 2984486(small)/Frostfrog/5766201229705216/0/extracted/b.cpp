#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct node {
	explicit node(int i) {num = i;}
	~node() {}
	int num;
	int count;
	vector<node*> edges;
};

bool Compare(node* a, node*b)
{
return a->count > b->count;
}

struct G {
	G() {}
	typedef map<int, node*>::iterator mapit;
	~G() {
	map<int, node*>::iterator it = nodes.begin();
		while(it != nodes.end()) {
			delete it->second;
			it++;
		}
		nodes.clear();
	}
	map<int, node*> nodes;
	node *createNode (int i) {
		map<int, node*>::iterator it;
		it = nodes.find(i);
		if (it != nodes.end()) {
			return it->second;
		}
		node * n= new node(i);
		nodes[i] = n;
		n->num = i;
		return n;
	};
	
	void insertEdge(int i, int j)
	{
		node *ni, *nj;
		ni = createNode(i);
		nj = createNode(j);
		ni->edges.push_back(nj);
		nj->edges.push_back(ni);
	}
	
	void solve() {
		int N;
		cin >> N;
		int count = N - 1;
		while(count--) {
			int i,j;	
			cin >> i >> j;
			insertEdge(i,j);
		}
		int ans = 0;
		for (int i = 1; i <= N; i ++) {
			if (nodes.find(i) == nodes.end()) {
				ans ++;
			} 
		}
		int m = 0;
		for (mapit it = nodes.begin() ; it != nodes.end(); it ++) {
			int n =  search(it->second);
		//	cout << it->second->num << "wtf" <<n <<endl;
			m = std::max(m, n);
			
		}
		
		cout << N - m;
	}
	
	int search (node* n) {
		
		return search_int(n, NULL);
	}
	
	int search_int(node* n ,node *from){
		if (from) n->edges.erase(find(n->edges.begin(), n->edges.end(), from));
		n->count = 1;
	
		//if (n->edges.size() == 0) {
	//	cout << n->num << ',' <<n->edges.size() << '\t' ;
		//}
		if (n->edges.size() == 1) {
			if (from) n->edges.push_back(from);
	//		cout << "a"<< n->num << ',' <<n->edges.size() << ',' <<n->count << '\t' ;
			return n->count;
		}
		

		if (n->edges.size() <= 2) {
			for (int i = 0; i < n->edges.size(); i++) {
				n->count += search_int(n->edges[i], n);
			}
			if (from) n->edges.push_back(from);
	//		cout  << "b"<< n->num << ',' <<n->edges.size() << ',' <<n->count << '\t' ;
			return n->count;
		} 
		
		
		for (int i = 0; i <n->edges.size(); i++) {
			node *now = n->edges[i];
			now->count = search_int(now, n);
		}
		sort(n->edges.begin(), n->edges.end(), Compare);
		
		n->count += n->edges[0]->count;
		n->count += n->edges[1]->count;
		
		if (from) n->edges.push_back(from);
	//	cout << "c" << n->num << ',' << n->edges.size() << ',' <<n->count << '\t' ;
		return n->count;
	}
	
	
	
};


void solve_one() {
G g;
g.solve();
}

int main()
{
	//freopen("B-small-attempt0.in", "r", stdin);

	int T, cases=0;
	cin >> T;
	while(T--) {
		cout << "Case #" << ++cases << ": ";
		solve_one();
		cout << endl;
	}
	return 0;
}
