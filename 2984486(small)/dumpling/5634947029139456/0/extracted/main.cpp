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
#include <bitset>
using namespace std;

#define mp make_pair

//%llu
typedef unsigned long long uint64;
typedef long long int64;
typedef pair<int, int> pair2;

int T, N, L;
uint64 outlet[160];
uint64 device[160];
uint64 midterm[160];
string code;

void init() {
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        cin >> code;
        bitset<64> bs(code);
        outlet[i] = bs.to_ulong();
    }
    for (int i = 0; i < N; ++i) {
        cin >> code;
        bitset<64> bs(code);
        device[i] = bs.to_ulong();
    }
}

bool isLegal(uint64 * a) {
    sort(a, a + N);
    for (int i = 0; i < N; ++i)
        if (a[i] != device[i])
            return false;
    return true;
}

int countOne(int n) {
    int ret = 0, x;
    while (n) {
        x = n & (-n);
        n -= x;
        ++ret;
    }
    return ret;
}

int flipped() {
    sort(device, device + N);
    int ret = 0x3f3f3f3f;
    uint64 maxn = (1 << L) - 1;
    for (uint64 i = 0; i <= maxn; ++i) {
        memset(midterm, 0, sizeof (midterm));
        for (int j = 0; j < N; ++j)
            midterm[j] = outlet[j] ^ i;
        if (isLegal(midterm)) {
            ret = min(ret, countOne((int) i));
        }
    }
    return ret;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        int ret = flipped();
        if (ret == 0x3f3f3f3f)
            printf("Case #%d: NOT POSSIBLE\n", t);
        else
            printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}