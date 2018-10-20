#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#define REP(i, a, b) for ( int i = int(a); i <= int(b); i++ )
#define pb push_back
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define MAXN 1000
#define INF 1 << 30
using namespace std;

int T, N;
vector< vector<int> > adjList;
vector<int> visited, size, to_delete;

void dfs_size(int u, int p) {
	size[u] = 1;
	for_each(it, adjList[u]) if(*it != p) {
		dfs_size(*it, u);
		size[u] += size[*it];
	}
}

bool comp(int a, int b) {	
	return (size[a] - to_delete[a]) > (size[b] - to_delete[b]);
}

int check(int u, int p) {
	int num_child = 0, to_del = 0;
	to_delete[u] = 0;	

	for_each(it, adjList[u]) if(*it != p) {
		num_child++;
		to_del += size[*it];
	}

	if(num_child == 1) {
		to_delete[u] = to_del;
		return to_del;
	} else {
		to_del = 0;
		for_each(it, adjList[u]) if(*it != p) {
			to_del += check(*it, u);
		}

		if(num_child == 2) {
			return (to_delete[u] = to_del);	
		} else {
			to_del = 0;
			sort(adjList[u].begin(), adjList[u].end(), comp);
			num_child = 0;
			for_each(it, adjList[u]) if(*it != p) {
				num_child++;
				if(num_child > 2) {
					to_del += size[*it];
				} else {
					to_del += to_delete[*it];
				}
			}
			return (to_delete[u] = to_del);			
		}
	}
}

int main()
{
    scanf("%d", &T);
    REP(t, 1, T) {
    	scanf("%d", &N);
    	int u, v;
    	adjList.clear(); adjList.resize(N);
    	REP(i, 0, N-2) {
    		scanf("%d%d", &u, &v);
    		adjList[u-1].pb(v-1);
    		adjList[v-1].pb(u-1);
    	}

    	int cnt, min_cnt = (INF);

    	REP(i, 0, N-1) {
    		if(adjList[i].size() <= 2) {
    			//this node can be root, right?
    			size.clear(); size.resize(N);
    			to_delete.clear(); to_delete.resize(N);
    			dfs_size(i, -1);
    			cnt = check(i, -1);
    			min_cnt = min(min_cnt, cnt);
    		}
    	}

    	printf("Case #%d: %d\n", t, min_cnt);
    }
    return 0;
}
