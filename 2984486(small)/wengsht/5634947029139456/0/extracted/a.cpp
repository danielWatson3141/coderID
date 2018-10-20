/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <sstream>
#include <set>
using namespace std;

#define MX 100005
#define REP(i,n) for(int i=0;i<(n);i++)
#define OREP(i,n) for(int i=1;i<=(n);i++)

typedef long long          LL;
typedef unsigned long long ULL;
typedef unsigned int       UINT;

int n, m, k, t;
int l;

string A[155];
string B[155];
string C[155];

#define INF 150
int ret = INF;

bool flags[55];

bool good() {
    sort(C, C+n);

    REP(i, n) if(C[i] != B[i]) return false;

    return true;
}
void go(int i, int j) {
    int cnt = 0;
    REP(k, l) {
        if(A[i][k] != B[j][k]) {
            cnt ++;
            flags[k] = 1;
        }
        else flags[k] = 0;
    }
    REP(a, n) {
        C[a] = A[a];
        REP(b, l) if(flags[b]) C[a][b] = (A[a][b] == '1') ? '0' : '1';
    }

    if(good()) ret = min(ret, cnt);
}
void go() {
    REP(i, n) REP(j, n) go(i, j);
}
int main() {
    scanf("%d", &t);
    OREP(c, t) {
        scanf("%d %d", &n, &l);

        REP(i, n) 
            cin >> A[i];
        REP(i, n) 
            cin >> B[i];

        sort(B, B+n);
        ret = INF;

        go();

        printf("Case #%d: ",c);
        if(ret == INF) {
            printf("NOT POSSIBLE\n");
        }
        else {
            printf("%d\n", ret);
        }
    }
    return 0;
}

