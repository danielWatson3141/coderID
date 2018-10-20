#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define ULL unsigned long long
using namespace std;

int N;
int result = 0;
vector<bool> v(1001, false);

int delnd(vector<vector<int> > &nds, int prt, int rt)
{
    if(nds[rt].size()<2) return 1;
    int ans = 1;
    REP(i, nds[rt].size()) {
        if(nds[rt][i]==prt) continue;
        ans += delnd(nds, rt, nds[rt][i]);
    }
    return ans;
}

int dfs(vector<vector<int> > &nds, int prt, int rt) {
    if(nds[rt].size() == 2 && prt != -1) {
        return delnd(nds, prt, rt) - 1;
    }
    else if (nds[rt].size() == 1) return 0;
    else{
        int ans = 0;
        REP(i, nds[rt].size()) {
            if(nds[rt][i] == prt) continue;
            ans += dfs(nds, rt, nds[rt][i]);
        }
        return ans;
    }
}

int main()
{
    CASET {
        RI(N);
        vector<vector<int> > nds(N+1, vector<int>());
        REP(i, N+1) v[i] = false;
        REP(i, N-1) {
            DRII(a, b);
            nds[a].PB(b);
            nds[b].PB(a);
        }
        int max = N-1;
        REPP(i, 1, N+1) {
            if(nds[i].size()==2) {
                int tmp = dfs(nds, -1, i);
                if(tmp < max) max = tmp;
            }
        }
        
        printf("Case #%d: %d\n", case_n, max);
        ++case_n;
    }
    return 0;
}
