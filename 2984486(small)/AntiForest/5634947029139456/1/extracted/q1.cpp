#include <cstdio>
#include <set>

using namespace std;

typedef set<long long>::iterator myIt;

int _T;

int N, L;
char a[200][200], b[200][200];
long long nB[200];

set <long long> allS;

bool isSwitch[200];

bool isPos;
int cAns;

int main() {
    freopen ("q1.in", "r", stdin);
    freopen ("q1.out", "w", stdout);
    scanf ("%d", &_T);
    for (int _z=1; _z<=_T; _z++) {
        printf ("Case #%d: ", _z);   
        scanf ("%d %d", &N, &L);
        for (int i = 0; i < N; i++) {
            for (int p = 0; p < L; p++) {
                scanf (" %c ", &a[i][p]);
                a[i][p] -= '0';
            }
        }
        for (int i = 0; i < N; i++) {
            nB[i] = 0;
            for (int p = 0; p < L; p++) {
                scanf (" %c ", &b[i][p]);
                b[i][p] -= '0';
                nB[i] = nB[i]<<1ll;
                nB[i] += b[i][p];
            }
        }
        int ans = 2000000;
        for (int i = 0; i < N; i++) {
            //Try every way of turning 1st into ith:
            isPos = true;
            cAns = 0;
            for (int p = 0; p < L; p++) {
                if (a[0][p] != b[i][p]) {
                    cAns++;
                    isSwitch[p] = true;
                } else {
                    isSwitch[p] = false;
                }
            }
            allS.clear();
            for (int p = 0; p < N; p++) {
                allS.insert (nB[p]);
            }
            for (int p = 0; p < N; p++) {
                long long temN = 0;
                for (int k = 0; k < L; k++) {
                    temN = temN<<1ll;
                    if (isSwitch[k]) {
                        temN += !a[p][k];
                    } else {
                        temN += a[p][k];
                    }
                }
                myIt it = allS.find (temN);
                if (it == allS.end()) {
                    isPos = false;
                    break;
                } else {
                    allS.erase (it);
                }
            }
            if (isPos) {
                ans = min (ans, cAns);
            }
            //printf ("%d: %d isPos: %d\n", i, ans, isPos);
        }
        if (ans != 2000000) {
            printf ("%d\n", ans);
        } else {
            printf ("NOT POSSIBLE\n");
        }
    }
    return 0;
}
