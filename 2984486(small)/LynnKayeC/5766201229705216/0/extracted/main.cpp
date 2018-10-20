/*
 * main.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: blding
 */


#include <cstdio>
using namespace std;

const int MAXN = 1000;

int caseNum;

int n;
int len[MAXN];
int nodes[MAXN][MAXN];
int state[MAXN][3]; // 0: leaf, 1: non-leaf

void preprocess(FILE * fin)
{
	fscanf(fin, "%d ", &n);
	for (int i = 0; i < n; ++i)
		len[i] = 0;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		fscanf(fin, "%d %d ", &a, &b);
		nodes[a - 1][len[a - 1]++] = b - 1;
		nodes[b - 1][len[b - 1]++] = a - 1;
	}
}

int getLeafSum(int cur, int parent)
{
	int sum = 0;
	for (int i = 0; i < len[cur]; ++i) {
		int adj = nodes[cur][i];
		if (adj != parent) {
			sum += state[adj][0] + 1;
		}
	}
	return sum;
}

int getNonLeafSum(int cur, int parent)
{
	// can't be internal or root
	//fprintf(stdout, "get %d %d %d\n", cur, len[cur], parent);
	if (len[cur] >= 3 || (len[cur] == 2 && parent == -1)) {
	int max1 = 0;
	int max2 = 0;
	int sum = 0;
	for (int i = 0; i < len[cur]; ++i) {
		int adj = nodes[cur][i];
		if (adj != parent) {
			sum += state[adj][0] + 1;
			int delta = state[adj][0] + 1 - state[adj][2];
			if (delta > max1) {
				max2 = max1;
				max1 = delta;
			} else if (delta > max2) {
				max2 = delta;
			}
		}
	}
	return sum - max1 - max2;
	} else {
		return n * 2;
	}
}

void traverse(int cur, int parent)
{
	for (int i = 0; i < len[cur]; ++i) {
		if (nodes[cur][i] != parent) {
			traverse(nodes[cur][i], cur);
		}
	}
	// leaf
	state[cur][0] = getLeafSum(cur, parent);
	// non leaf
	state[cur][1] = getNonLeafSum(cur, parent);

	state[cur][2] = state[cur][0] < state[cur][1] ? state[cur][0]: state[cur][1];
	//fprintf(stdout, " (%d %d %d %d)\n", cur, state[cur][0], state[cur][1], state[cur][2]);
}


void work(int caseId, FILE * fout)
{
	int mini = n;
	for (int i = 0; i < n; ++i) {
	//	fprintf(stdout, "%d\n", i);
		traverse(i, -1);
		if (state[i][2] < mini) {
			mini = state[i][2];
		}
//		for (int j = 0; j < n; ++j)
//			fprintf(stdout, " (%d %d %d)", state[j][0], state[j][1], state[j][2]);
	//	fprintf(stdout, "\n");
	}
	fprintf(fout, "Case #%d: %d\n", caseId, mini);
}
int main()
{
	FILE * fin;
	FILE * fout;

	fin = fopen("../input", "r");
	fout = fopen("../output", "w");

	fscanf(fin, "%d ", &caseNum);
	for (int caseId = 1; caseId <= caseNum; ++caseId) {
		preprocess(fin);
		work(caseId, fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

