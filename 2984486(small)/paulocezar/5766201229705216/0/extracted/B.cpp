#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <fstream>

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 1024

vector<int> gr[MAXN];

int doit(int node, int pa = -1) {
    
    int mx1 = -1, mx2 = -1;
    
    for (int i = 0; i < int(gr[node].size()); ++i) {
        if (gr[node][i] == pa) continue;
        
        int rs = doit(gr[node][i], node);
        
        if (rs > mx1) { mx2 = mx1; mx1 = rs; }
        else if (rs == mx1) { mx2 = mx1; }
        else if (rs > mx2) { mx2 = rs; }
    }
    
    int mbest = 1;
    if (mx2 > 0) mbest += (mx1+mx2);
    return mbest;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for (int kase = 1; kase <= cases; ++kase) {
        
        int N;
        cin >> N;
        
        for (int i = 0; i < N; ++i) gr[i].clear();
        
        for (int i = 1; i < N; ++i) {
            int u, v; cin >> u >> v; u--, v--;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        
        int res = 0;
        for (int i = 0; i < N; ++i) res = max(res, doit(i));
        res = N-res;
        
        cout << "Case #" << kase << ": " << res << "\n";
    }

	return 0;
}

















