#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> col, siz;
vector<vector<int>> G;

int ile_usunac_jesli_korzen(int v) {
    col[v] = 1;
    vector<int> wyniki;
    for(int &u: G[v]) {
        if(!col[u]) {
            int wynu = ile_usunac_jesli_korzen(u);
            wyniki.push_back(siz[u] - wynu);
            siz[v] += siz[u];
        }
    }
    siz[v] ++;
    if(wyniki.size() < 2)
        return siz[v] - 1;
    sort(wyniki.rbegin(), wyniki.rend());
    return siz[v] - wyniki[0] - wyniki[1] - 1;
}

int solve() {
    int n;
    scanf("%d", &n);
    G.clear();
    G.resize(n);
    for(int i = 0; i < n - 1; i ++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[--a].push_back(--b);
        G[b].push_back(a);
    }
    int m = n + 100;
    for(int i = 0; i < n; i ++) {
        col.clear();
        siz.clear();
        col.resize(n, 0);
        siz.resize(n, 0);
        m = min(m, ile_usunac_jesli_korzen(i));
    }
    return m;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i ++)
        printf("Case #%d: %d\n", i, solve());
}