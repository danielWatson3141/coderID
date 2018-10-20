#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <string>
using namespace std;

int T, N, L, f;
set<int> S;

int s2i(string s) {
    int r = 0;
    for (int i = 0, j = 1; i < s.size(); j *= 2)
        r += (s[i++] == '1') * j;
    return r;
}

bool check(int p[150]) {
    for (int i = 0; i < N; i++)
        if (!S.count(p[i])) return false;
    return true;
}

bool work(int p[3][150], int *P) {
    copy(p[0], p[0] + N, p[2]);
    for (int i = 0; i < L; i++)
        if (P[i])
            for (int j = 0; j < N; j++)
                p[2][j] ^= 1 << i;
    bool b = check(p[2]);
    if (false && b) {
        printf("  > found: ");
        for (int i = 0; i < L; i++)
            printf("%d", P[i]);
        printf("\n");
    }
    return b;
}

int main() {
    scanf("%d", &T);
    for (int t = 0; t++ < T;) {
        scanf("%d%d", &N, &L);
        S.clear();
        int p[3][150], b = 1;
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < N; i++) {
                string s;
                cin >> s;
                p[j][i] = s2i(s);
                if (j)
                    S.insert(p[j][i]);
            }
        for (f = 0; f <= L; f++) {
            int perm[40] = {};
            for (int i = 0; i < f; i++)
                perm[L - i - 1] = 1;
            do {
                b ^= work(p, perm);
            } while (b && next_permutation(perm, perm + L));
            if (!b) break;
        }
        printf("Case #%d: ", t);
        if (f > L)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", f);
    }
}
