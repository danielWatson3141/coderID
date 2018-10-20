#include "stdafx.h"


std::fstream instream;
std::fstream outstream;

int N,L;
int test_cases;
int pd[1001][1001];
int pdTreeSize[1001][1001];

vector<int> nodes[1111];

int treeSize(int current_node, int parent_node){
	int& resp = pdTreeSize[current_node][parent_node];
	if (resp < 0){
		resp = 1;
		for (int i = 0; i < nodes[current_node].size(); i++){
			if (nodes[current_node][i] == parent_node) continue;
			resp += treeSize(nodes[current_node][i], current_node);
		}
	}
	return resp;
}

int minCost(int current_node, int parent_node){
	int& resp = pd[current_node][parent_node];
	if (resp < 0){
		int numFilhos = nodes[current_node].size() - (parent_node != 0);

		if (numFilhos == 0) resp = 0;
		else if (numFilhos == 1) resp = treeSize(current_node, parent_node) - 1;
		else{
			int maxEconomia1 = -1, maxEconomia2 = -1;

			int node_max1 = -1, node_max2 = -1;
			int custo_tranformar_full1 = -1, custo_tranformar_full2 = -1;
			int custo_remover_todos = 0;

			for (int i = 0; i < nodes[current_node].size(); i++){

				int node_atual = nodes[current_node][i];
				if (node_atual == parent_node) continue;
					
				int tranformar_full = minCost(node_atual, current_node);
				int size_currrent = treeSize(node_atual, current_node);
					
				custo_remover_todos += size_currrent;
				int economia_atual = size_currrent - tranformar_full;

				if (economia_atual > maxEconomia1){
					swap(economia_atual, maxEconomia1);
				}

				if (economia_atual > maxEconomia2){
					swap(economia_atual, maxEconomia2);
				}
			}
				
			resp = custo_remover_todos - (maxEconomia1 + maxEconomia2);
		}
	}

	return resp;
}


void process(int t){
	int mincost = 999999999;

	for (int i = 1; i <= N; i++){
		mincost = min(mincost, minCost(i, 0));
	}

	outstream << "Case #" << t << ": " << mincost<<endl;
}

void lerTeste(){
	//1 ... N
	instream.open("B-large.in", std::fstream::in);
	outstream.open("saida.txt", std::fstream::out);
	
	instream >> test_cases;

	for (int i = 0; i < test_cases; i++){
		instream >> N;
		memset(pd, -1, sizeof(pd));
		memset(pdTreeSize, -1, sizeof(pdTreeSize));

		for (int j = 0; j <= N; j++) while (nodes[j].size())	nodes[j].pop_back();// clear();

		for (int j = 0; j < N-1; j++){
			int a, b;
			instream >> a >> b;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		
		process(i + 1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	lerTeste();

	//go(my_tree->root);


	return 0;
}