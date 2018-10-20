#include <bits/stdc++.h>
using namespace std;

const int maxN = 155;

int N, L;
string a[maxN], b[maxN];
int res;

bool check(int j){
    if (j == 0) return true;
    sort(a, a + N);
    for (int i = 0; i < N; i++) if (a[i][j-1] != b[i][j-1]) return false;
    return true;
}

void attempt(int j, int all){
    if (!check(j)) return;
    if (j == L){
        res = min(res, all);
        return;
    }
    attempt(j + 1, all);
    for (int i = 0; i < N; i++) a[i][j] = '1' - a[i][j] + '0';
    attempt(j + 1, all + 1);
    for (int i = 0; i < N; i++) a[i][j] = '1' - a[i][j] + '0';
}

void runTest(){
    scanf("%d%d", &N, &L);
    char s[44];
    for (int i = 0; i < N; i++){
        scanf("%s", s); a[i] = s;
    }
    for (int i = 0; i < N; i++){
        scanf("%s", s); b[i] = s;
    }
    sort(b, b + N);
    res = L + 1;
    attempt(0, 0);
    if (res == L + 1) printf("NOT POSSIBLE\n");
    else printf("%d\n", res);
}

int main(){
    freopen("A.inp", "r", stdin);
    freopen("A.out", "w", stdout);

    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        printf("Case #%d: ", i);
        runTest();
    }
    return 0;
}
