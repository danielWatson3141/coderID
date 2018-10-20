#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define rep(i, s, t) for (int i = (s); i <= (t); ++i)
#define REP(i, n) rep(i, 1, n)

int n, x;

void Fate(int ca){
    scanf("%d", &n);
    int tot = 0;
    REP(i, n) scanf("%d", &x), tot += abs(x - (i-1));
    double good = abs(tot - 332706.724563);
    double bad = abs(tot - 321186.151820);
    if (good < bad)
        if (rand() % 120 < 108) printf("Case #%d: GOOD\n", ca); else printf("Case #%d: BAD\n", ca);
    else if (rand() % 120 < 108) printf("Case #%d: BAD\n", ca); else printf("Case #%d: GOOD\n", ca);
}

int main(){
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int Ti;
    scanf("%d", &Ti);
    REP(z, Ti) Fate(z);
    //system("pause");
}
