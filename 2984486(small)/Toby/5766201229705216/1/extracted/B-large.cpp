#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int N;
vector<int> neighbor[1000];
bool visited[1000];

bool comp(const std::pair<int,int>& lhs, const std::pair<int,int>& rhs)
{
      return lhs.first - lhs.second > rhs.first - rhs.second;
}

// return (total, need_to_cut)
pair<int, int> dfs(int v) {
    visited[v] = true;
    vector<pair<int, int> > cut;
    for (vector<int>::iterator iter = neighbor[v].begin(); iter != neighbor[v].end(); ++iter) {
        if (visited[*iter])
            continue;
        cut.push_back(dfs(*iter));
    }
    sort(cut.begin(), cut.end(), comp);
/*cout << "dfs " << v << ", " << cut.size() << endl;
cout << "\t";
for (int i = 0; i < cut.size(); i++)
    cout << cut[i].first << "," << cut[i].second << " ";
cout << endl;*/
    if (cut.size() == 0)
        return make_pair(1, 0);
    else if (cut.size() == 1) {
        int total = cut[0].first;
        return make_pair(total + 1, total);
    } else {
        int total = 0;
        for (int i = 0; i < cut.size(); i++)
            total += cut[i].first;
        int keep = cut[0].first - cut[0].second + cut[1].first - cut[1].second;
        return make_pair(total + 1, total - keep);
    }
}

int check(int root) {
    memset(visited, false, sizeof(visited));
//cout << "check " << root << endl;
    return dfs(root).second;
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++)
        neighbor[i].clear();
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        neighbor[a].push_back(b);
        neighbor[b].push_back(a);
    }

    int ans = N;
    for (int i = 0; i < N; i++) {
        int r = check(i);
        ans = min(r, ans);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }

    return 0;
}
