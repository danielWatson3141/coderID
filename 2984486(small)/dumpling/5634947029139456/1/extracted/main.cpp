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
int64 outlet[160];
int64 device[160];
int64 midterm[160];
string code;

void init() {
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        cin >> code;
        outlet[i] = 0;
        for(int j = 0; j < code.size(); ++j){
            outlet[i] *= 2;
            outlet[i] += (code[j] == '1');
        }
    }
    for (int i = 0; i < N; ++i) {
        cin >> code;
        device[i] = 0;
        for(int j = 0; j < code.size(); ++j){
            device[i] *= 2;
            device[i] += (code[j] == '1');
        }
    }
}

bool isLegal(int64 * a) {
    sort(a, a + N);
    for (int i = 0; i < N; ++i)
        if (a[i] != device[i])
            return false;
    return true;
}

int countOne(int64 n) {
    int ret = 0;
    int64 x;
    while (n) {
        x = n & (-n);
        n -= x;
        ++ret;
    }
    return ret;
}

int flipped() {
    sort(device, device + N);
    sort(outlet, outlet + N);
    int ret = 0x3f3f3f3f;
    for (int i = 0; i < N; ++i) {
        int64 delta = device[0] ^ outlet[i];
        memset(midterm, 0, sizeof (midterm));
        for (int j = 0; j < N; ++j)
            midterm[j] = outlet[j] ^ delta;
        if (isLegal(midterm)) {
            ret = min(ret, countOne(delta));
        }
    }
    return ret;
}

int main() {
    freopen("al.in", "r", stdin);
    freopen("al.out", "w", stdout);
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