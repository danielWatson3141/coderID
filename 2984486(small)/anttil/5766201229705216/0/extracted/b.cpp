#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int> p[1010];
int aa[1010];
int bb[1010];

int laske(int k, int e) {
    int ac = 0;
    vector<pair<int,int>> q;
    for (int i = 0; i < p[k].size(); i++) {
        if (p[k][i] == e) continue;
        laske(p[k][i], k);
        ac += aa[p[k][i]];
        q.push_back(make_pair(aa[p[k][i]], bb[p[k][i]]));
    }
    aa[k] = ac+1;
    if (q.size() == 0) {
        bb[k] = 0;
    } else if (q.size() == 1) {
        bb[k] = q[0].first;
    } else {
        int cc = 0;
        for (int i = 0; i < q.size(); i++) {
            cc += q[i].first;
        }
        int v = 999999999;
        for (int i = 0; i < q.size(); i++) {
            for (int j = i+1; j < q.size(); j++) {
                int u = cc+q[i].second+q[j].second-q[i].first-q[j].first;
                v = min(v, u);
            }
        }
        bb[k] = v;
    }
}

int main() {
    cin >> t;
    for (int x = 0; x < t; x++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            p[i].clear();
        }
        for (int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            p[a].push_back(b);
            p[b].push_back(a);
        }
        int v = 999999999;
        for (int i = 1; i <= n; i++) {
            laske(i, -1);
            v = min(v, bb[i]);
        }
        cout << "Case #" << x+1 << ": " << v << endl;
    }
}
