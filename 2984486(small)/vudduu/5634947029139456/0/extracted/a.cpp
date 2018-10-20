#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define MP          make_pair
typedef long long   LL;

int N, L;

void read(vector<int> & A) {
    string s;
    F(i, N) {
        cin >> s;
        A[i] = 0;
        F(j, L) A[i] = A[i] | ((s[j] == '1') << j);
    }
}

void solve() {
    cin >> N >> L;
    vector<int> A(N), B(N), C;
    read(A);
    read(B);
    set<int> conj2(ALL(B));
    int mini = 100000000;
    F(mask, 1<<(L+1)) {
        C = A;
        int c = 0;
        F(i, L) {
            int x = (1<<i);
            if(mask & x) c++;
        }
        F(i, N) C[i] = C[i] ^ mask;
        set<int> conj1(ALL(C));
        if(conj1 == conj2) {
            mini = min(mini, c);
        }
    }
    if(100000000 == mini)
        cout << "NOT POSSIBLE" << endl;
    else
        cout << mini << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
