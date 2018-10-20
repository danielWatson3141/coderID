#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define pb(x) push_back(x)

typedef long long LL;


// bool hasEdge[1010][1010];
bool isVisited[1010];
bool isVisitedForDeletes[1010];
vector<int> neighbor[1010];
int N;

int howManyDeletes(int deleteNode, int parentNode) {
	int res = 1; // delete the current one

	queue<int> Q;
	for(int i=1; i <= N; i++) {
		isVisitedForDeletes[i] = false;
	}
	// cout<<"deleteNode : "<<deleteNode<<endl;
	isVisitedForDeletes[deleteNode] = true;
	isVisitedForDeletes[parentNode] = true;
	Q.push(deleteNode);
	while(!Q.empty()) {
		int curNode = Q.front(); Q.pop();

		for(int i=0; i < neighbor[curNode].size(); i++) {
			int nextNode = neighbor[curNode][i];
			if(!isVisitedForDeletes[nextNode]) {
				// cout<<"delete : "<<nextNode<<endl;
				isVisitedForDeletes[nextNode] = true;
				res++;
				Q.push(nextNode);
			}
		}
	}
	// cout<<"#############"<<endl;

	return res;
}

int recurse(int curNode) {
	int res = 0;

	vector<int> children;

	for(int i=0; i < neighbor[curNode].size(); i++) {
		int nextNode = neighbor[curNode][i];
		if(!isVisited[nextNode]) {
			isVisited[nextNode] = true;
			children.push_back(nextNode);
		}
	}
	int numChild = children.size();
	if(numChild == 0) {
		return 0;
	} else if(numChild == 1) {
		return howManyDeletes(children[0], curNode);
	} else if(numChild == 2) {
		return recurse(children[0]) + recurse(children[1]);
	} else { // many children
		
		vector< pair<int, int> >V;
		for(int i=0; i < children.size(); i++) {
			int curDelete = howManyDeletes(children[i], curNode);
			V.push_back( make_pair(curDelete, children[i]) );
		}
		sort(V.rbegin(), V.rend());
		for(int i=2; i < numChild; i++) {
			res += V[i].first;
		}
		return res + recurse(V[0].second) + recurse(V[1].second);
	}
}

int main() {
	int T;
	int x, y;

	cin>>T;
	for(int cid=1; cid <= T; cid++) {
		cin>>N;
		// init
		// for(int i=1; i <= N; i++)
		// 	for(int j=1; j <= N; j++)
		// 		hasEdge[i][j] = false;

		for(int i=1; i <= N; i++) {
			neighbor[i].clear();
		}

		for(int i=0; i < N-1; i++) {
			cin>>x>>y;
			// hasEdge[x][y] = hasEdge[y][x] = true;
			neighbor[x].pb(y);
			neighbor[y].pb(x);
		}

		int res = 1010;
		// try all nodes
		for(int root = 1; root <= N; root++) {
			for(int i=1; i <= N; i++)
				isVisited[i] = false;
			isVisited[root] = true;
			int curRes = recurse(root);
			// cout<<"root : "<<root<<" , curRes : "<<curRes<<endl;
			res = min(res, curRes);
		}

		cout<<"Case #"<<cid<<": ";
		cout<<res<<endl;



	}
    
}
