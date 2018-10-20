#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


ifstream fin("small2.in");
ofstream fout("small2.out");
int edges[1000][1000];
int degree[1000];
bool visited[1000];



int dfs(int node, int& nNodes){
	visited[node] = true;
	int trueDeg = 0;
	for(int i=0;i<degree[node];i++){
		if(!visited[edges[node][i]]){
			trueDeg++;
		}
	}
	if(trueDeg == 0){
		nNodes = 1;
		return 0;
	}
	if(trueDeg == 1){
		for(int i=0;i<degree[node];i++){
			if(!visited[edges[node][i]]){
				int child = edges[node][i];
				dfs(child, nNodes);
				nNodes++;
				return nNodes-1;
			}
		}
	}
	if(trueDeg == 2){
		nNodes = 1;
		int tmpNNodes = 0;
		int minToDelete = 0;
		for(int i=0;i<degree[node];i++){
			if(!visited[edges[node][i]]){
				int child = edges[node][i];
				minToDelete += dfs(child, tmpNNodes);
				nNodes+=tmpNNodes;
			}
		}
		return minToDelete;
	}
	if(trueDeg >= 3){
		int tmpNumNodes[1000];
		int tmpMinToDelete[1000];
		nNodes = 1;
		int count = 0;
		for(int i=0;i<degree[node];i++){
			if(!visited[edges[node][i]]){
				int child = edges[node][i];
				tmpMinToDelete[count] = dfs(child, tmpNumNodes[count]);
				nNodes+=tmpNumNodes[count];
				count++;
			}
		}
		int minToDelete = 2000;
		for(int i=0;i<count;i++){
			for(int j=0;j<count;j++){
				if(i!=j){
					int tmpTotal = 0;
					for(int k=0;k<count;k++){
						if(k==i || k==j){
							tmpTotal += tmpMinToDelete[k];
						}
						else{
							tmpTotal += tmpNumNodes[k];
						}
					}
					if(tmpTotal < minToDelete){
						minToDelete = tmpTotal;
					}
				}
			}
		}
		return minToDelete;
	}
}

int main(){
	int nt;
	fin >> nt;
	for(int t=0;t<nt;t++){
		int n;
		fin >> n;
		for(int i=0;i<n;i++){
			degree[i] = 0;
		}
		for(int i=0;i<n-1;i++){
			int a,b;
			fin >> a >> b;
			a--;b--;
			edges[a][degree[a]] = b;
			edges[b][degree[b]] = a;
			degree[a]++;
			degree[b]++;
		}
		int min = 2000;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				visited[j] = false;
			}
			int tmp;
			int r=dfs(i,tmp);
			if(r<min)
				min = r;
		}
		fout << "Case #" << t+1 << ": " << min << endl;
	}
	return 0;
}