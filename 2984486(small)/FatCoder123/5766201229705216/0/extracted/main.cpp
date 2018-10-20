
// main.c

#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <numeric>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <thread>
#include <mutex>

#define WRITE_OUT_FILE 0

using namespace std;

int N;
vector<pair<int, int>>edges;
vector<pair<int, int>>tmp_edges;
//multimap<int, int>edges;
int tmp_node_cnt = 0;
bool tmp_valid = false;

vector<int> findConn(int in, int from) {
	
	vector<int>conns;
	for (int i = 0; i < tmp_edges.size(); i++) {
		if (tmp_edges[i].first == in) {
			int nod = tmp_edges[i].second;
			if (nod != from)
				conns.push_back(nod);
			
		} else if (tmp_edges[i].second == in) {
			int nod = tmp_edges[i].first;
			if (nod != from)
				conns.push_back(nod);
		}
	}
	return conns;
}

void rvbt(int node, int from) {
	vector<int> conn = findConn(node, from);
	if (!tmp_valid)
		return;
	
	if (conn.size() == 2) {
		tmp_node_cnt += 2;
		rvbt(conn[0], node);
		rvbt(conn[1], node);
	} else if (conn.size() == 0) {
		return;
	} else {
		tmp_valid = false;
		return;
	}
	
}

int solve()
{
	int max_nc = 0;
	for (int i = 1; i <= N; i++) {
		tmp_node_cnt = 0;
		tmp_valid = true;
		
		rvbt(i, 0);
		
		if (tmp_node_cnt > max_nc)
			max_nc = tmp_node_cnt;
	}
	
	return N - max_nc - 1;
}

int main()
{
	freopen("in.in", "r", stdin);
	if (WRITE_OUT_FILE)
		freopen("out.out", "w", stdout);
	
	int T;
	scanf("%d\n", &T);
	if (!T) {
		cerr << "Check input!" << endl;
		exit(0);
	}
	
	for (int t = 1; t <= T; t++) {
		if (WRITE_OUT_FILE)
			cerr << "Solving: #" << t << " / " << T << endl;
		
		scanf("%d\n", &N);
		
		edges.clear();
		tmp_edges.clear();
		
		for (int i = 0; i < N - 1; i++) {
			int e1, e2;
			scanf("%d %d\n", &e1, &e2);
			edges.push_back(pair<int, int>(e1, e2));
		}
		tmp_edges = vector<pair<int, int>>(edges);
		
		auto result = solve();
		printf("Case #%d: %d\n", t, result);
	}
	
	fclose(stdin);
	if (WRITE_OUT_FILE)
		fclose(stdout);
	
	return 0;
}


