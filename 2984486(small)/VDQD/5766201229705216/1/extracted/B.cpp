#include <bits/stdc++.h>
using namespace std;

const int maxN = 1111;
#define PB push_back
#define FORE(it,c) for(__typeof(c.begin())it=c.begin();it!=c.end();it++)

int N;
vector<int> a[maxN];
int f[maxN], res;

void visit(int u, int p){
    int max1 = -1, max2 = -1;
    FORE (it, a[u]) if (*it != p){
        visit(*it, u);
        if (f[*it] >= max1) max2 = max1, max1 = f[*it];
        else if (f[*it] >= max2) max2 = f[*it];
    }
    f[u] = 1;
    if (max2 != -1) f[u] += max1 + max2;
}

void runTest(){
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) a[i].clear();
    int u, v;
    for (int i = 0; i < N - 1; i++){
        scanf("%d%d", &u, &v);
        a[u].PB(v);
        a[v].PB(u);
    }
    res = N - 1;
    for (int i = 1; i <= N; i++){
        visit(i, -1);
        res = min(res, N - f[i]);
    }
    printf("%d\n", res);
}

int main(){
    freopen("B.inp", "r", stdin);
    freopen("B.out", "w", stdout);

    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        runTest();
    }
    return 0;
}
