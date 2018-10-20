#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 1005
using namespace std;

int _T;
int N, a, b;

bool seen[MAX_N];
int nOut[MAX_N], v[MAX_N];
vector <int> allV[MAX_N];

vector <int> allE[MAX_N];

int ans;

void dfs (int c) {
    //printf ("IM AT %d\n", c);
    seen[c] = true;
    for (int i = 0; i < allE[c].size(); i++) {
        int cP = allE[c][i];
        if (seen[cP]) continue;
        //printf ("GOING OUT %d to %d\n", c, cP);
        dfs (cP);
        nOut[c]++;
        allV[c].push_back (v[cP]);
    }
    if (nOut[c] < 2) {
        //printf ("IN HERE %d\n", c);
        v[c] = 1;
        return;
    } else {
        sort (allV[c].begin(), allV[c].end());
        reverse (allV[c].begin(), allV[c].end());
        v[c] = allV[c][1]+allV[c][0]+1;
        return;
    }
    return;
}

int main() {
    freopen ("q2.in", "r", stdin);
    freopen ("q2.out", "w", stdout);
    scanf ("%d", &_T);
    for (int _z=1; _z <= _T; _z++) {
        printf ("Case #%d: ", _z);
        scanf ("%d", &N);
        ans = N-1;
        for (int p = 1; p <= N; p++) {
            allE[p].clear();
        }
        for (int p = 0; p < N-1; p++) {
            scanf ("%d %d", &a, &b);
            allE[a].push_back (b);
            allE[b].push_back (a);
        }
        for (int i = 1; i <= N; i++) {
            for (int p = 1; p <= N; p++) {
                seen[p] = false;
                nOut[p] = 0;
                v[p] = 1;
                allV[p].clear();
            }
            dfs (i);
            /*
            printf ("%d: %d\n", i, v[i]);
            for (int p = 1; p <= N; p++) {
                printf ("v %d: %d\n", p, v[p]);
            }
            */
            ans = min (ans, N-v[i]);
        }
        printf ("%d\n", ans);
    }
    return 0;
}
