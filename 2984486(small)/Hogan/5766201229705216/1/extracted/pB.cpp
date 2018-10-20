#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> vct[1000];
int save[1000];
int left[1000];

void dfs(int t, int p) {
    vector<pair<int, int> > ret = vector<pair<int, int> >();

    for (vector<int>::iterator it = vct[t].begin(); it != vct[t].end(); it++) {
        if (*it == p) continue;
        dfs(*it, t);

        ret.push_back(pair<int, int>(left[*it] - save[*it], *it));
    }
    sort(ret.rbegin(), ret.rend());

    save[t] = 0;
    left[t] = 1;
    for (vector<pair<int, int> >::iterator it = ret.begin(); it != ret.end(); it++) {
        left[t] += left[it->second];

        if (it - ret.begin() < 2) save[t] += save[it->second];
        else save[t] += left[it->second];
    }

    if (ret.size() == 1) save[t] = left[t] - 1;
}

int main() {
    int T, n, a, b;
    scanf("%d", &T);

    for (int times = 0; times < T; times++) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            vct[i] = vector<int>();
        }

        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &a, &b);
            a--; b--;

            vct[a].push_back(b);
            vct[b].push_back(a);
        }

        int myMin = 5000;
        for (int i = 0; i < n; i++) {
            dfs(i, i);
            myMin = min(myMin, save[i]);
        }

        printf("Case #%d: %d\n", times + 1, myMin);
    }
}
