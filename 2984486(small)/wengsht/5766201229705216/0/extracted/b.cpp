
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

int head[1005];
struct Edge { 
    int v, nxt;
}edge[2005];
int in[1005];
void addEdge(int a, int b) {
    edge[m].v = b;
    edge[m].nxt = head[a];
    head[a] = m++;
}
int dfs(int x, int p) {
    vector<int> res;
    for(int i = head[x]; i != -1; i = edge[i].nxt) {
        Edge & e = edge[i];
        if(e.v != p) {
            res.push_back(dfs(e.v, x));
        }
    }
    sort(res.begin(), res.end());
    int siz = res.size();
    if(siz <= 1) return 1;
    else return 1 + res[siz-1] + res[siz-2];
}
int go(int x) {
    if(in[x] == 1) return n-1;

    return n - dfs(x, -1);
}
int main() {
    scanf("%d", &t);

    OREP(c, t) {
        scanf("%d", &n);

        memset(head, -1, sizeof head);
        memset(in, 0, sizeof in);
        m = 0;
        int a, b;
        REP(i, n-1) {
            scanf("%d %d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
            in[a] ++;
            in[b] ++;
        }

        int ret = n;

        OREP(i, n) ret = min(ret, go(i));

        printf("Case #%d: %d\n", c, ret);
    }
    return 0;
}
