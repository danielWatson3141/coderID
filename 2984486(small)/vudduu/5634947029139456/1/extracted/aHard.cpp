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

void read(vector<string> & A) {
    F(i, N) cin >> A[i];
}

void solve() {
    cin >> N >> L;
    vector<string> A(N), B(N), C;
    read(A);
    read(B);
    int mini = 100000000;
    set<string> conj2(ALL(B));
    F(i, N) {
        C = A;
        int c = 0;
        F(j, L) {
            if(C[i][j] != B[0][j]) {
                F(k, N) C[k][j] = (C[k][j] == '1')? '0' : '1';
                c++;
            }
        }
        set<string> conj1(ALL(C));
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
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
