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

int N, L;
int result;
void dfs(vector<string> &ol, vector<string> &dv, int len, int ans)
{
    if(len >= L) {
        bool tr = true;
        vector<string> tt(ALL(ol));
        sort(ALL(tt));
        REP(i, N) if(tt[i]!=dv[i]) tr=false;
        if(tr==true) {
            if(ans < result)
                result = ans;
        }
        return;
    }
    dfs(ol, dv, len+1, ans);
    REP(i, N){
        ol[i][len] = (ol[i][len]=='1'?'0':'1');
    }
    dfs(ol, dv, len+1, ans+1);
    REP(i, N){
        ol[i][len] = (ol[i][len]=='1'?'0':'1');
    }
}

int main()
{
    CASET {                
        RII(N, L);
        vector<string> ol(N, "");
        vector<string> dv(N, "");
        result = L + 2;
        REP(i, N) cin >> ol[i];
        REP(i, N) cin >> dv[i];
        sort(ALL(ol));
        sort(ALL(dv));
        dfs(ol, dv, 0, 0);
        printf("Case #%d: ", case_n);
        if(result == L+2)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", result);
        ++case_n;
    }
    return 0;
}
