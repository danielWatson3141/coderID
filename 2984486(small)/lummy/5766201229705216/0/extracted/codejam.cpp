#include "stdafx.h"


// codejam.cpp : 定义控制台应用程序的入口点。
//



#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>

#define INPUTFILE "B-small-attempt1.in"
#define OUTPUTFILE "result.out"


using namespace std;

//#pragma warning(disable:4996)
bool *mark;
int **nodesAsRoot;
vector<vector<int>> graph;
int N;

void findRoot(int root,int father){
	priority_queue<int> myQue;
	if (nodesAsRoot[root][father] != -1)
		return;
	for (int j = 0; j < graph[root].size(); j++){
		if (graph[root][j] == father)
			continue;
		findRoot(graph[root][j], root);
		myQue.push(nodesAsRoot[graph[root][j]][root]);
	}
	int max=-1, second=-1;
	if (!myQue.empty()){
		max = myQue.top();
		myQue.pop();
	}
	if (!myQue.empty()){
		second = myQue.top();
		myQue.pop();
	}
	if (max != -1 && second != -1)
		nodesAsRoot[root][father] = max + second + 1;
	else
		nodesAsRoot[root][father] = 1;
}


int main()
{
	fstream infile(INPUTFILE, ios::in);
	fstream outfile(OUTPUTFILE, ios::out);
	int caseN, count;
	infile >> caseN;
	count = 1;
	int N,i,j;
	int max, temp;
	stack<int> nodes;
	int root;
	bool bRoot;
	nodesAsRoot = new int*[1000];
	
	while (count <= caseN){
		graph.clear();
		infile >> N;
		graph.assign(N, vector<int>());
		mark = new bool[N];
		
		for (i = 0; i < N; i++){
			nodesAsRoot[i] = new int[N+1];
			memset(nodesAsRoot[i], -1, sizeof(int)*(N+1));
		}
		temp = 1;
		while (temp++ < N){
			infile >> i >> j;
			graph[i - 1].push_back(j - 1);
			graph[j - 1].push_back(i - 1);
		}
		//enumearate
		max = temp = 0;
		
		for (i = 0; i < N; i++){
			findRoot(i, N);
			if (nodesAsRoot[i][N]>max)
				max = nodesAsRoot[i][N];
		}

		outfile << "Case #" << count++ << ": " << N - max << endl;
		delete[]mark;
		for (i = 0; i < N; i++)
			delete[] nodesAsRoot[i];

	}
	delete[]nodesAsRoot;
	infile.close();
	outfile.close();
	return 0;
}

