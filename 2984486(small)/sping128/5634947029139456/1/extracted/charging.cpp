//
// charging.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Friday, 25 April 2014.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

#define MAXN 155
#define MAXL 45

string in[MAXN];
string want[MAXN];
int N;
int L;
bool change[MAXL];

string temp1[MAXN];

void solve() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> want[i];
    }
    sort(want, want + N);
    for (int i = 0; i < N; i++) {
        temp1[i] = in[i];
    }

    int minn = 1000000;
    for (int i1 = 0; i1 < N; i1++) {
        int cnt = 0;
        for (int k = 0; k < L; k++) {
            if (in[i1][k] != want[0][k]) {
                cnt++;
                change[k] = true;
            } else {
                change[k] = false;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < L; j++) {
                if (!change[j]) temp1[i][j] = in[i][j];
                else {
                    if (in[i][j] == '1') temp1[i][j] = '0';
                    else temp1[i][j] = '1';
                }
            }
        }
        sort(temp1, temp1 + N);
        bool good = true;
        for (int i = 0; i < N; i++) {
            if (temp1[i] != want[i]) {
                good = false;
                break;
            }
        }

        if (good)
            minn = min(minn, cnt);
    }

    if (minn == 1000000) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", minn);
    }
}

int main() {
    int test;
    scanf("%d", &test);
    for (int tt = 0; tt < test; tt++) {
        printf("Case #%d: ", tt + 1);
        solve();
    }
    return 0;
}
