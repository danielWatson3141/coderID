#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

const int NN = 1024;
int N;
int adj[NN][NN], deg[NN];
int subCnt[NN], F[NN];

const int INF = 1000000000;

int go(int u, int fa) {
    subCnt[u] = 1;
    F[u] = 0;
    int  m1 = INF, m2 = INF;
    int  g1 = -1, g2 = -1;
    int  cnt = 0;
    int  tot = 0;
    F0(k, deg[u]) {
        int  v = adj[u][k];
        if (v == fa) continue;
        go(v, u);
        ++cnt;
        int  s = F[v] - subCnt[v];
        tot += subCnt[v];
        subCnt[u] += subCnt[v];
        if (s < m1) {
            m2 = m1;
            g2 = g1;
            m1 = s;
            g1 = k;
        }
        else if (s < m2) {
            m2 = s;
            g2 = k;
        }
    }
    if (cnt >= 2) {
        F[u] += tot + m1 + m2;
        // if (g1 < 0 || g2 < 0) {
        //     printf("%d: F=%d subs=%d cnt=%d g1=%d m1=%d g2=%d m2=%d\n",
        //            u, F[u], cnt, subCnt[u], g1, m1, g2, m2);
        // }
    }
    else if (cnt == 1) {
        F[u] = tot;
    }
    else {
        F0(k, deg[u]) {
            int v = adj[u][k];
            if (v == fa) continue;
            F[u] += F[v];
        }
    }
    // printf("%d: F=%d subs=%d cnt=%d\n", u, F[u], cnt, subCnt[u]);
    return F[u];
}

int  calc(int idx) {
    memset(subCnt, 0, sizeof(subCnt));
    memset(F, 0, sizeof(F));
    go(idx, -1);
    return F[idx];
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    F1(iT, T) {
        scanf("%d", &N);
        memset(deg, 0, sizeof(deg));
        for(int i=1; i<N; ++i) {
            int  u, v;
            scanf("%d%d", &u, &v);
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }
        int  ans = N;
        F1(i, N) {
            ans = min(calc(i), ans);
            // break;
        }
        printf("Case #%d: %d\n", iT, ans);
    }
    return 0;
}
