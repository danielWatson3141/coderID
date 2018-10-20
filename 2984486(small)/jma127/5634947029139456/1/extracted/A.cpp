/**
 * jerrym
 * A.cpp
 */

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;

int gInt () {
    int i;
    scanf("%d", &i);
    return i;
}

lli gLong () {
    lli i;
    scanf("%lld", &i);
    return i;
}

double gDouble () {
    double i;
    scanf("%lf", &i);
    return i;
}

void quit () {
    fflush(stdout);
    exit(0);
}

int n, l;

char outlets[200][70], devices[200][70];
int outletSums[64];
int deviceSums[64];

void flip (int cur) {
    for (int i = 0; i < n; ++i) {
        outlets[i][cur] = (outlets[i][cur] == '1' ? '0' : '1');
    }
}

bool validate (int upTo) {
    if (upTo == 0) return true;
    vector<string> a, b;
    for (int i = 0; i < n; ++i) {
        a.push_back(string(outlets[i], upTo));
        b.push_back(string(devices[i], upTo));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int getAns (int cur) {
    if (!validate(cur)) {
        return 2000;
    }
    if (cur == l) {
        return 0;
    }
    if (outletSums[cur] == deviceSums[cur] && outletSums[cur] + deviceSums[cur] == n) {
        int noflip = getAns(cur + 1);
        if (noflip == 0) {
            return noflip;
        }
        flip(cur);
        int flipped = getAns(cur + 1);
        flip(cur);
        return min(noflip, flipped + 1);
    } else if (outletSums[cur] == deviceSums[cur]) {
        return getAns(cur + 1);
    } else if (outletSums[cur] + deviceSums[cur] == n) {
        flip(cur);
        int ret = getAns(cur + 1) + 1;
        flip(cur);
        return ret;
    } else {
        return 2000;
    }
}

void solve (int nC) {
    n = gInt();
    l = gInt();
    for (int i = 0; i < n; ++i) {
        scanf("%s", outlets[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", devices[i]);
    }
    for (int i = 0; i < l; ++i) {
        outletSums[i] = deviceSums[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (outlets[j][i] == '1') {
                ++outletSums[i];
            }
            if (devices[j][i] == '1') {
                ++deviceSums[i];
            }
        }
    }
    int ans = getAns(0);
    printf("Case #%d: ", nC + 1);
    if (ans > l) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", ans);
    }
}

int main (int argc, char ** argv) {
    int nC = gInt();
    for (int i = 0; i < nC; ++i) solve(i);
    quit();
}
