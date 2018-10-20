// Copyright
// @author: Ruben S. Andrist
// @date: 2014-04-25
// @email: andrist@gmail.com

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<int> > &n, vector<int> &s, int i) {
    //printf(" solve(n,s,%d)\n", i);
    s[i] = 1;
    int gain1 = -1, gain2 = -1, sum = 0;
    for (int j=0; j<n[i].size(); j++) {
        int k = n[i][j];
        if (s[k] > 0) continue;
        int cost = solve(n,s,k);
        sum += s[k];
        s[i] += s[k];
        int gain = s[k] - cost;
        if (gain > gain2) swap(gain,gain2);
        if (gain2 > gain1) swap(gain1,gain2);
    }
    if (gain1 == -1 || gain2 == -1) {
        return sum;
    } else {
        return sum - gain1 - gain2;
    }
}

int main() {

    int T=0;
    scanf("%d", &T);

    for (int t=1; t<=T; t++) {
        int N=0;
        scanf(" %d", &N);

        //printf("_________\n");

        vector<vector<int> > n;
        n.clear();
        n.resize(N);
        for (int i=0; i<N-1; i++) {
            int a, b;
            scanf(" %d %d", &a, &b);
            a-=1; b-=1;
            n[a].push_back(b);
            n[b].push_back(a);
        }

        vector<int> s(N);

        int best = N-1;
        for (int i=0; i<N; i++) {
            //printf("Assuming root %d\n", i);
            s.assign(N,0);
            int sol = solve(n,s,i);
            if (sol<best) {
                best = sol;
            }
        }
        printf("Case #%d: %d\n", t, best);
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
