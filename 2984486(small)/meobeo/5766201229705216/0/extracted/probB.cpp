#include <iostream>
#include <fstream> 
#include <set> 
#include <vector>
#include <string>
#include <utility>
#include <list>
using namespace std;

ofstream outFile;
ifstream inFile;
	int N;
	int T;
	std::list<int> edge[1001];
	bool processed[1001];
int compute(int r);

std::pair<int, int> report(int v);
int main(int argc, const char* argv[]) {
	inFile.open(argv[1]);
 	inFile >> T;
	outFile.open("out.txt");

	for (int i = 1; i <= T; i++) {
		inFile >> N;
		for (int j = 1; j <= N; j++){
			edge[j].clear();
			processed[j] = false;
		}
		for (int j = 1; j <= N-1; j++) {
			int v1, v2;
			inFile >> v1 >> v2;
			edge[v1].push_front(v2);
			edge[v2].push_front(v1);
		}
		int minV = 10000;
		for (int j = 1; j <= N; j++){
			int numV = compute(j);
			if (minV > numV) minV = numV;
		}
	        outFile << "Case #" << i << ": "<< minV << std::endl;
	}	

	outFile.close();
	inFile.close();
	return 0;

}	
int compute(int r) {
	for (int i = 1; i <= N; i++)
		processed[i] = false;
	processed[r] = true;
	std::pair<int,int> ret = report(r);
	return (ret.second);

}

std::pair<int, int> report(int v) {
	std::vector<int> numNode;
	std::vector<int> delNode;
	std::vector<int> diff;
	for (std::list<int>::iterator it = edge[v].begin(); it != edge[v].end(); ++it) {
		if (!processed[*it]) {
			processed[*it] = true;
			std::pair<int,int> ret = report(*it);
			numNode.push_back(ret.first);
			delNode.push_back(ret.second);
			diff.push_back(ret.second - ret.first);
		}
	}
	if (numNode.size() == 0) {
		return std::pair<int,int>(1,0);
	}
	else if (numNode.size() == 1) {
		return std::pair<int, int>(numNode[0]+1,numNode[0]);
	}
	else if (numNode.size() == 2) {
		return std::pair<int, int>(numNode[0]+numNode[1]+1, delNode[0]+delNode[1]);
	}
	else {
		int totalNode = 1;
		for (int i = 0; i < numNode.size(); i++)
			totalNode += numNode[i];
		int min = 10000;
		int pos1 = 0;
		for (int i = 0; i < numNode.size(); i++)
		if (min > diff[i]) {
			min = diff[i];
			pos1 = i;
		}
		int pos2;
		min = 10000;
		for (int i = 0; i < diff.size(); i++)
		if ((i != pos1) && (min > diff[i])){
			min = diff[i];
			pos2 = i;
		}

		return std::pair<int,int>(totalNode, diff[pos1]+diff[pos2]+totalNode-1);
	}

}
