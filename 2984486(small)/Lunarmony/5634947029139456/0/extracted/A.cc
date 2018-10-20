#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int N, L;
char from[200][50], to[200][50];

void solve() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; ++i)
        scanf("%s", from[i]);
    for (int i = 0; i < N; ++i)
        scanf("%s", to[i]);
    int ans = L + 1;
    for (int x = 0; x < N; ++x) {
        // from[i] -> to[0]
        int curSolution = 0;
        bool flip[50];
        for (int j = 0; j < L; ++j) {
            flip[j] = (from[x][j] != to[0][j]);
            if (flip[j])
                ++curSolution;
        }
        if (curSolution >= ans)
            continue;
        bool valid = true;
        for (int i = 0; i < N; ++i) {
            bool found = false;
            for (int j = 0; j < N && !found; ++j) {
                bool matched = true;
                for (int k = 0; k < L && matched; ++k) {
                    bool fromCur = from[i][k] == '1';
                    if (flip[k]) {
                        fromCur = !fromCur;
                    }
                    bool toCur = to[j][k] == '1';
                    if (fromCur != toCur)
                        matched = false;
                }
                if (matched)
                    found = true;
            }
            if (!found) {
                valid = false;
                break;
            }
        }
        if (valid)
            ans = min(ans, curSolution);
    }
    if (ans == L + 1)
        printf("NOT POSSIBLE\n");
    else
        printf("%d\n", ans);
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 1; caseNo <= numCases; ++caseNo) {
        printf("Case #%d: ", caseNo);
        solve();
    }
    return 0;
}
