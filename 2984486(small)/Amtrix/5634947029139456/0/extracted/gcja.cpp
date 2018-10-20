#include <bits/stdc++.h>
using namespace std;

const int maxn = 200;

int n,m;
string w[maxn], goal[maxn];
vector<int>flip;

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz10.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int tests; cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        flip.clear();
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> w[i];
        for (int i = 0; i < n; ++i) cin >> goal[i];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                w[i][j] -= '0', goal[i][j] -= '0';

        sort(goal, goal + n);
        vector<string> possible;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                string str = "";
                for (int k = 0; k < m; ++k)
                    str += string(1,(w[i][k]+goal[j][k])%2);
                possible.push_back(str);
            }
        }

        int minsol = 1e9;
        for (int i = 0; i < possible.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                cnt += int(possible[i][j]);
                for (int k = 0; k < n && possible[i][j]; ++k)
                    w[k][j] = 1 - w[k][j];
            }

            sort(w, w + n);
            bool ok = 1;
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k)
                    if (w[j][k] != goal[j][k]) ok = 0;

            if (ok)
                minsol = min(minsol, cnt);


            for (int j = 0; j < m; ++j) {
                cnt += int(possible[i][j]);
                for (int k = 0; k < n && possible[i][j]; ++k)
                    w[k][j] = 1 - w[k][j];
            }
        }

        cout << "Case #" << t << ": ";
        if (minsol == 1e9) cout << "NOT POSSIBLE" << endl;
        else cout << minsol << endl;

    }
}
