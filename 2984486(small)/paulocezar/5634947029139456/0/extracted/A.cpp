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

#define MAXN 256

int N, L;
long long mask;

string x[MAXN], y[MAXN];

bool seen[MAXN];		
int m[MAXN], m1[MAXN];

bool cool(int ix, int iy) {
    for (int i = 0; i < L; ++i) {
        if ((mask & (1LL<<i)) && (x[ix][i] == y[iy][i])) return false;
        if (!(mask & (1LL<<i)) && (x[ix][i] != y[iy][i])) return false;
    }
    return true;
}

int dfs(int u) {
	if (u < 0) return 1;
	if (seen[u]) return 0;
	seen[u] = true;
	for (int i = 0; i < N; ++i) {
        if (!cool(u, i)) continue;
        
		if (dfs(m1[ i ])) {
			m[u] = i;
			m1[ i ] = u;
			return 1;
		}
	}
	return 0;
}

int dfsExp(int u) {
	for (int i = 0; i < N; ++i) seen[i] = false;
	return dfs(u);
}


int bipMatch() {
	for (int i = 0; i < N; ++i) m[i] = -1;
	for (int i = 0; i < N; ++i) m1[i] = -1;
	int aug, ans = 0;
	do {
		aug = 0;
		bool first = true;
		for (int i = 0; i < N; ++i) if (m[i] < 0) {
			if (first) aug += dfsExp(i);
			else aug += dfs(i);
			first = false;
		}
		ans += aug;
	} while (aug);
	return ans;
}

int main(int argc, char* argv[]) {
	
	ios::sync_with_stdio(false);
    
    int cases;
    cin >> cases;
    for (int kase = 1; kase <= cases; ++kase) {
        
        cin >> N >> L;
        for (int i = 0; i < N; ++i) cin >> x[i];
        for (int i = 0; i < N; ++i) cin >> y[i];
        
        int res = L+1;
        
        for (int i = 0; i < N; ++i) {
            mask = 0LL;
            int cnt = 0;
            for (int j = 0; j < L; ++j) if (x[0][j] != y[i][j]) {
                mask |= (1LL<<j);
                cnt++;
            }
            
            if (cnt < res) {
                if (bipMatch() == N) res = cnt;
            }   
        }
        
        cout << "Case #" << kase << ": "; 
        if (res <= L) cout << res << "\n";
        else cout << "NOT POSSIBLE\n";    
        
    }

	return 0;
}

















