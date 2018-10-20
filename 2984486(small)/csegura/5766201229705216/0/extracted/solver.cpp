#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <strings.h>
#include <math.h>

using namespace std;

bool isTree(vector < vector < int > > &graph, int n, int &count){
	count = 0;
	int bit = 0;
	bool isPresent[graph.size()];
	bzero(isPresent, sizeof(isPresent));
	while(n != 0){
		if (n % 2){
			isPresent[bit] = true;
			count++;
		}
		n /= 2;
		bit++;
	}
	if (count == 1){
		return true;
	}
	int counts[2];
	int root = -1;
	for (int i = 0; i < graph.size(); i++){
		if (!isPresent[i]){
			continue;
		}
		int edges = 0;
		for (int j = 0; j < graph[i].size(); j++){
			if (isPresent[graph[i][j]]){
				edges++;
			}
		}
		if (edges == 2){
			root = i;
			break;
		}
	}

	if (root == -1){
		return false;
	}
	//dfs from root
	bool visited[graph.size()];
	bzero(visited, sizeof(visited));
	int current = root;
	queue< pair<int,int> > pending;
	pending.push(pair<int, int>(root, -1));
	int nVisited = 1;
	visited[root] = true;
	while(pending.size()){
		int next = pending.front().first;
		int ignore = pending.front().second;
		pending.pop();
		int countInternal = 0;
		for (int j = 0; j < graph[next].size(); j++){
			if ((isPresent[graph[next][j]]) && (graph[next][j] != ignore)){
				if (visited[graph[next][j]]){
					return false;
				} else {
					countInternal++;
					visited[graph[next][j]] = true;
					nVisited++;
					pending.push(pair<int, int>(graph[next][j], next));
				}
			}
		}
		if ((countInternal != 0) && (countInternal != 2)){
			return false;
		}
	}
	return (nVisited == count);
}

int main(){
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++){
		int N;
		cin >> N;
		vector< vector < int > > graph(N, vector<int>());
		for (int j = 0; j < N - 1; j++){
			int xj, yj;
			cin >> xj >> yj;
			xj--;
			yj--;
			graph[xj].push_back(yj);
			graph[yj].push_back(xj);
		}
		int result = -1;
		for (int j = 0; j < (1 << N); j++){
			int count;
			if (isTree(graph, j, count)){
				if (count > result){
					result = count;
				}
			}
		}
		cout << "Case #" << (i+1) << ": " << N - result << endl;
	}
}
