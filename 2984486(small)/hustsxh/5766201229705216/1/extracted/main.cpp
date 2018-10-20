#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 1001;

vector<int> edge[N];
int f[N], cnt[N];

int DFS(int x, int father) {
    int cntchild = 0, min1 = N, min2 = N;
    cnt[x] = 0;
    for (int i = 0; i < edge[x].size(); ++i) {
        int child = edge[x][i];
        if (child != father) {
            DFS(child, x);
            cnt[x] += cnt[child];
            int temp = f[child] - cnt[child];
            if (temp < min1) {
                min2 = min1;
                min1 = temp;
            } else if (temp < min2) {
                min2 = temp;
            }
            ++ cntchild;
        }
    }
    if (cntchild >= 2) {
        f[x] = cnt[x] + min1 + min2;
    } else {
        f[x] = cnt[x];
    }
    ++ cnt[x];
    return f[x];
}

void solve() {
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i) edge[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, DFS(i, 0));
    }
    cout << " " << ans << endl;
}

int main() {
    int testcase;
    freopen("/Users/xhSong/Downloads/B-large.in", "r", stdin);
    freopen("/Users/xhSong/gcj/out.txt", "w", stdout);
    cin >> testcase;
    for (int test = 1; test <= testcase; ++test) {
        cout << "Case #" << test << ":";
        solve();
    }
    return 0;
}
