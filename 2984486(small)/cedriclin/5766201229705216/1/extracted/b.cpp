#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> graph[1024];

vector<int> children[1024];
int parent[1024];
bool visited[1024];

int num[1024]; //returns # of nodes in the subtree rooted by the index
int delcnt[1024]; // returns # of nodes required to delete in the subtree rooted by index, to turn it into a full binary tree

void dfs(int curr){
	visited[curr] = true;
	num[curr] = 1;
	for (int i = 0; i < graph[curr].size(); i++){
		int next = graph[curr][i];
		if (!visited[next]) {
			children[curr].push_back(next);
			parent[next] = curr;
			dfs(next);
			num[curr] += num[next];
		}
	}
	
	if (children[curr].size() == 0){
		delcnt[curr] = 0;
		return;
	}
	if (children[curr].size() == 1){
		delcnt[curr] = num[children[curr][0]];
		return;
	}
	delcnt[curr] = 0;
	int best1 = 0, best2 = 0;
	for (int i = 0; i < children[curr].size(); i++){
		int next = children[curr][i];
		int offset = num[next] - delcnt[next];
		if (offset > best1) {
			best2 = best1;
			best1 = offset;
		}
		else if (offset > best2){
			best2 = offset;
		}
		delcnt[curr] += num[next];
	}
	delcnt[curr] -= best1;
	delcnt[curr] -= best2;
}

int make_tree(int root){ //return ans if tree is rooted at root
	for (int i = 0; i < 1000; i++)
		children[i].clear();
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));
	memset(num,0,sizeof(num));
	memset(delcnt,0,sizeof(delcnt));
	dfs(root);
	/*
	for (int i = 0; i < n; i++)
		cout << num[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << delcnt[i] << " ";
	cout << endl;
	*/
	return delcnt[root];
}

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> n;	
		for (int i = 0; i < 1000; i++)
			graph[i].clear();
		for (int i = 0; i < n-1; i++){
			int x,y;
			cin >> x >> y;
			x--; y--;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		int besti = -1, best = n;
		for (int i = 0; i < n; i++){
			int ans = make_tree(i);
			//cout << "i = " << i << ", ans = " << ans << endl;
			if (best > ans){
				besti = i;
				best = ans;
			}
		}
		cout << "Case #" << zz << ": " << best << endl;
	}
	
	return 0;
}
