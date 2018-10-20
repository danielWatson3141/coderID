#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int checkTree(vector<int> *occ, int N, int root, char *deleted) {
	int v, j, count;
	int visited[1024] = {0};
	vector<int> toVisit;
	int visitCount;
	toVisit.push_back(root);
	int rootCount = 0, firstRun=1, treeSize=0;
	
	while (toVisit.size()) {
		v = toVisit.back();
	//	printf("pop %d\n", v);
		toVisit.pop_back();
		visited[v] = 1;
		treeSize++;
		count = 0;
		visitCount = 0;
		for (j=0; j<(int)occ[v].size(); j++) if (deleted[occ[v][j]]==0) {
			count++;
			if (visited[occ[v][j]]) visitCount++;
		}
		if (count <= 3) {
			if (count==2) {	//root
				rootCount++;
				if (rootCount>=2) return 0;
			}
			if (firstRun==0 && visitCount!=1) return 0;
			firstRun = 1;
			for (j=0; j<(int)occ[v].size(); j++) if (deleted[occ[v][j]]==0 && visited[occ[v][j]]==0) {
				toVisit.push_back(occ[v][j]);
			//	printf("push %d\n", occ[v][j]);
			}
		}
		else return 0;
	}
//	printf("treeSize %d\n", treeSize);
//	printf("rootCount %d\n", rootCount);
	if (rootCount!=1 && treeSize>1) return 0;
	
	return treeSize;
}



/*
int treeWeight(vector<int> *occ, int root, int step) {
	int visited[1024] = {0};
	vector<int> toVisit;
	toVisit.push_back(step);
	visited[v] = 1;
	int v, treeSize=1;
	
	while (toVisit.size()) {
		v = toVisit.back();
	//	printf("pop %d\n", v);
		toVisit.pop_back();
		for (i=0; i<(int)occ[v].size(); i++) if (occ[v][i] != root && visited[occ[v][i]]==0) {
			treeSize++;
			visited[occ[v][i]] = 1;
			toVisit.push_back(occ[v][i]);
		}
	}
	return treeSize;
}
*/


void searchTree(vector<int> *occ, int N, char *deleted, int &bestTreeSize);


void searchTree(vector<int> *occ, int N, char *deleted, int &bestTreeSize) {
	int treeSize, i, v, count;
	for (v=1; v<=N; v++) {
	//	count = 0;
	//	for (i=0; i<(int)occ[v].size(); i++) if (deleted[occ[v][i]]==0) count++;
	//	if (count >= 2) {
			for (i=0; i<(int)occ[v].size(); i++) if (deleted[occ[v][i]]==0) {
				deleted[occ[v][i]] = 1;
				treeSize = checkTree(occ, N, v, deleted);
				if (treeSize > bestTreeSize) bestTreeSize = treeSize;
				deleted[occ[v][i]] = 0;
			}
	//	}
	}
}





int main(void) {
	int t, testCases;
	cin >> testCases;
	
	int i, treeSize;
	int N;
	int edge[1024][2];
	vector<int> *occ;
	char *deleted;
	
	for (t=1; t<=testCases; t++) {
		cin >> N;
		for (i=0; i<N-1; i++) {
			cin >> edge[i][0] >> edge[i][1];
		}
		occ = new vector<int> [N+1];
		for (i=0; i<N-1; i++) {
			occ[edge[i][0]].push_back(edge[i][1]);
			occ[edge[i][1]].push_back(edge[i][0]);
		}
		
		deleted = new char [N+1];
		for (i=0; i<N+1; i++) deleted[i] = 0;
		
		
		treeSize = checkTree(occ, N, 1, deleted);
		if (treeSize==0) {
			treeSize = 0;
			searchTree(occ, N, deleted, treeSize);
			if (treeSize == 0) fprintf(stderr, "err case %d\n", t);
		}
		
		printf("Case #%d: %d\n", t, N-treeSize);
		
		delete[] occ;
		delete[] deleted;
	}
	
	
	return 0;
}