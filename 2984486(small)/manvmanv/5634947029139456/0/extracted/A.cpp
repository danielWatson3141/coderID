#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;
typedef LL typec;
typedef LL type;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MAX 11

char ini[MAX][MAX];
char part[MAX][MAX];
char goal[MAX][MAX];

int cmp(const void *s1, const void *s2) {
    return strcmp((char *)s1, (char *)s2);
}

bool Same(char s1[][MAX], char s2[][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        if (strcmp(s1[i], s2[i])) {
            return false;
        }
    }
    return true;
}

int main(void) {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int nCase;
    while (~scanf("%d", &nCase)) {
        for (int cas = 1; cas <= nCase; ++cas) {
            int N;
            int L;
            scanf("%d%d", &N, &L);
            for (int i = 0; i < N; ++i) {
                scanf("%s", ini[i]);
            }
            for (int i = 0; i < N; ++i) {
                scanf("%s", goal[i]);
            }
            
            qsort(goal, N, sizeof(goal[0]), cmp);
            int mn = INF;
            int nTotal = (1 << L) - 1;
            for (int k = 0; k <= nTotal; ++k) {
                for (int i = 0; i < N; ++i) {
                    strcpy(part[i], ini[i]);
                }
                int nBits = 0;
                for (int i = 0; i < L; ++i) {
                    if (k & (1 << i)) {
                        ++nBits;
                        for (int j = 0; j < N; ++j) {
                            part[j][i] = ((part[j][i] - '0') ^ 1) + '0';
                        }
                    }
                }
                qsort(part, N, sizeof(part[0]), cmp);
                if (Same(part, goal, N)) {
                    mn = min(mn, nBits);
                }
            }
            printf("Case #%d: ", cas);
            if (mn < INF) {
                printf("%d\n", mn);
            } else {
                printf("NOT POSSIBLE\n");
            }
        }
    }
    return 0;
}