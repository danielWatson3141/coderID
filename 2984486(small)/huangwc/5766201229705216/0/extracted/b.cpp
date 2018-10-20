#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <algorithm>
#include <bitset>
#include <sstream>
using namespace std;

typedef long long i64;

int T, N;

vector<int> G[1000];
bool B[1000];

int test(int k) {
    B[k] = true;
    //cout << "**** " << k << endl;
    int x = 0, y = 0;
    for(int i = 0, z = 0; i < G[k].size(); ++i) {
        int p = G[k][i];
        if(!B[p]) {
            int z = test(p);
            if(z >= y) swap(y, z);
            if(y >= x) swap(x, y);
        }
    }
    B[k] = false;
    //cout << x << " - " << y << endl;
    //cout << "test " << k << " = " << 1 + (x&&y ? x+y : 0) << endl;;
    return 1 + (x&&y ? x+y : 0);
}

int main() {
    
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b-small.out", "w", stdout);
    
    cin >> T;
    for(int tt = 1; tt <= T; ++tt) {
        
        cin >> N;
        
        for(int i = 0; i < N; ++i) {
            G[i].clear();
            B[i] = false;
        }
        
        for(int i = 1, x, y; i < N; ++i) {
            cin >> x >> y;
            G[x-1].push_back(y-1);
            G[y-1].push_back(x-1);
        }
        
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            ans = max(ans, test(i));
        }
        
        
        cout << "Case #" << tt << ": " << N-ans
            << endl;
            
    }
    
    return 0;
    
}
