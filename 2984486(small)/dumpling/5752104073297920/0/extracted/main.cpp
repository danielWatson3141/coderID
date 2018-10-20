/*
 * @author: zhenpeng.fang
 * @nickname: dumpling
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;
typedef pair<int, int> pair2;

int T;
int N;
int a[1024];

int main() {
    freopen("C-small-attempt4.in", "r", stdin);
    freopen("c4.out", "w", stdout);
    scanf("%d", &T);
    srand((unsigned) time(NULL));
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            scanf("%d", a + i);
            if (i * 2 <= N) sum += a[i];
        }
        if (sum * 4 < N * N) {
            printf("Case #%d: BAD\n", t);
        } else
            printf("Case #%d: GOOD\n", t);
    }
    return 0;
}