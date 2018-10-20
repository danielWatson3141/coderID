#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

int N;
vector< vector<int> > tree;

void addedge(int x, int y) {
	tree[x].push_back(y);
	tree[y].push_back(x);
}

int choosedels(vector< pair<int,int> > ndels) {
	int n = (int)ndels.size();
	vector<int> diff(n);
	diff.resize(n);
	int totaldels = 0;
	for(int i=0; i<n; i++) {
		diff[i] = ndels[i].second-ndels[i].first;
		totaldels += ndels[i].first;
	}
	sort(diff.begin(), diff.end());
	totaldels += diff[0] + diff[1];
	return totaldels;
}

int deletesubtree(int root, int parent) {
	int sum = 1;
	for(int i=0; i<(int)tree[root].size(); i++)
		if(tree[root][i]!=parent)
			sum += deletesubtree(tree[root][i], root);
	return sum;
}

int reducesubtree(int root, int parent) {
	vector<int> neighbors = tree[root];
	int nchildren = (int)neighbors.size();
	vector<int> children;
	if(parent!=-1) {
		for(int i=0; i<nchildren; i++)
			if(neighbors[i]!=parent)
				children.push_back(neighbors[i]);
		nchildren--;
	}
	else {
		children = neighbors;
	}
	
	if(nchildren==0)
		return 0;
	else if(nchildren==1) {
		int ndels = deletesubtree(children[0],root);
		return ndels;
	}
	else if(nchildren==2) {
		int child1 = reducesubtree(children[0],root);
		int child2 = reducesubtree(children[1],root);
		return (child1+child2);
	}
	else {
		vector< pair<int,int> > ndels(nchildren);
		ndels.resize(nchildren);
		for(int i=0; i<nchildren; i++) {
			int del = deletesubtree(children[i],root);
			int red = reducesubtree(children[i],root);
			ndels[i] = make_pair(del,red);
		}
		int mindels = choosedels(ndels);
		return mindels;
	}
}

int reducetree() {
	int mindeletes = N;
	for(int root=0; root<N; root++ ) {
		int ndels = reducesubtree(root,-1);
		if(ndels<mindeletes)
			mindeletes = ndels;
	}
	return mindeletes;
}

int main() {
	int T; fin >> T;
	for(int t=1; t<=T; t++) {
		fin >> N;
		tree.clear();
		tree.resize(N);
		for(int i=0; i<N-1; i++) {
			int x,y; fin>>x>>y;
			addedge(x-1,y-1);
		}
		int ndeletes = reducetree();
		fout << "Case #" << t << ": " << ndeletes << endl;
	}

	return 0;
}

