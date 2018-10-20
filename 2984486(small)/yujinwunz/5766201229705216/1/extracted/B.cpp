#include <iostream>
#include <vector>
using namespace std;

int cases;
vector <int> node[1001];
int ans[1001][1001];
int sizeOf[1001][1001];
int nodes;

int size(int from, int to) {

	if (sizeOf[from][to] != -1) return sizeOf[from][to];
	// include the to node.
	int a = 1;
	for (int i = 0; i < node[to].size(); i++) {
		if (node[to][i] != from) a += size(to, node[to][i]);
	}
	sizeOf[from][to] = a;
	//cout<<"size "<<from<<" "<<to<<": "<<a<<"\n";
	return a;
}

int getAns(int from, int to) {
	if (ans[from][to] != -1) {
		//cout<<"nope\n";
		return ans[from][to];
	}
	// Try fo find a precomputed solution for a similar task
	/*
	int ansCount[1001];
	for (int i = 0; i < 1001; i++) {
		ansCount[i] = 0;
	}
	for (int i = 1; i <= 1000; i++) {
		if (ans[i][to] != -1) ansCount[ans[i][to]] ++;
	}
	for (int i = 1; i <= 1000; i++) {
		if (ansCount[i] >= 5) {
			ans[from][to] = i;
			//cout<<"No: "<<i<<"\n";
			return i;
		}
	}*/

	int A = 0;
	// a solution is to have no children
	for (int i = 0; i < node[to].size(); i++) {
		if (node[to][i] != from) A += size(to, node[to][i]);
	}
	int tot = A;

	// try 2 children.
	for (int a = 0; a < node[to].size(); a++) {
		for (int b = a+1; b < node[to].size(); b++) {
			if (node[to][a] == from || node[to][b] == from) continue;

			A = min(A, tot + getAns(to, node[to][a]) + getAns(to, node[to][b]) - size(to, node[to][a]) - size(to, node[to][b]));
		}
	}

	ans[from][to] = A;
	//cout<<"Ans "<<from<<" "<<to<<": "<<A<<"\n";
	return A;
}

int main() {
	cin>>cases;
	for (int c = 1; c <= cases; c++) {
		cin>>nodes;
		for (int i = 0; i <= nodes; i++) {
			node[i].clear();
			for (int j = 0; j <= nodes; j++) {
				ans[i][j] = -1;
				sizeOf[i][j] = -1;
			}
		}


		for (int i = 1; i < nodes; i++) {
			int a, b;
			cin>>a>>b;
			node[a].push_back(b);
			node[b].push_back(a);
		}

		// try every root
		int ans = (1<<30);
		for (int i = 1; i <= nodes; i++) {
			ans = min(ans, getAns(0, i));
		}
		cout<<"Case #"<<c<<": "<<ans<<"\n";
	}
}