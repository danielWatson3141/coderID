#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef vector<int> vi;

vector<vi> adlist;
vi parent;
vi rank;

int TC,cases,N;
void DFSparent(int u){
	int r = 1;
	for (int i=0;i<(int)adlist[u].size();i++){
		int v = adlist[u][i];
		if (parent[u]==v) continue;
		parent[v] = u;
		DFSparent(v);
		r += rank[v];
	}
	rank[u] = r;
	
}

int calfrom(int u){
	
	int min1 = 0 , min2  = 0;
	if ( (int)adlist[u].size() == 1 && rank[u]==N) return N-1;
	if ( (int)adlist[u].size() == 1 ) return 0;
	if ( (int)adlist[u].size() == 2 && rank[u] != N ) return rank[u]-1;
	
	
	for (int i=0;i<(int)adlist[u].size();i++){
		int v = adlist[u][i];
		if (v == parent[u]) continue;
		min2 = max(min2, rank[v] - calfrom(v));
		if (min2 > min1) swap(min1,min2);
	}
	//printf("cal from (%d) is %d",u,rank[u]-1 - (min1 + min2));
	
	return rank[u]-1 - (min1 + min2);
	
}
int main(){
	//freopen("in3.txt","r",stdin);freopen("out.txt","w",stdout);
	scanf(" %d",&TC);
	//printf("TC = %d\n",TC);
	
	int i,t1,t2,mini,root;
	for (cases = 1;cases<=TC;cases++){
		scanf(" %d",&N);
		//printf("N = %d\n",N);
		adlist.clear();
		adlist.resize(N);
		//printf("aodfa\n");
		for (i=0;i<N-1;i++){
			scanf("%d %d",&t1,&t2);
			t1--;t2--;
			//printf("i = %d t1 =  %d t2= %d\n",i,t1,t2);
			adlist[t1].push_back(t2);
			adlist[t2].push_back(t1);
		}
		
		//printf("agaf\n");
		
		mini = N;
		for (root = 0;root <N;root++){
			//DFS find rank;
			parent.clear();
			parent.resize(N);
			rank.clear();
			rank.resize(N);
			
			rank[root] = N;
			
			parent[root] = root;
			DFSparent(root);
			//printf("root = %d\n",root);
			//for (i=0;i<N;i++) printf(" rank[%d] = %d\n",i,rank[i]);
			//printf("done DFS parent for root = %d\n",root);
			
			mini = min (mini,calfrom(root));
		}
		printf("Case #%d: %d\n",cases, mini);
	}
}
