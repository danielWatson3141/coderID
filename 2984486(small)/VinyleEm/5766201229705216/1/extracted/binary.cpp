#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1024;
vector<vector<int> > edges(maxn, vector<int>());
vector<vector<int> > kids(maxn, vector<int>());

void clear()
{
    for (int i = 0;i < maxn; ++i) {
        edges[i].clear();
        kids[i].clear();
    }
}

void build_tree(int root, int n)
{
    queue<int> sq;
    vector<bool> visited(n, false);

    sq.push(root);
    visited[root] = true;

    while (sq.size() > 0) {
        int node = sq.front();
        sq.pop();

        for (int i = 0;i < (int)edges[node].size(); ++i) {
            int next = edges[node][i];
            if (!visited[next]) {
                visited[next] = true;
                sq.push(next);
                kids[node].push_back(next);
            }
        }
    }

    return;
}

int dp[maxn], counted[maxn];

int getcount(int x)
{
    int& ans = counted[x];
    if (ans >= 0)
        return ans;

    ans = 1;
    for (int i = 0;i < kids[x].size(); ++i) 
        ans += getcount(kids[x][i]);
    return ans;
}

int solve(int x, int n)
{
    if (kids[x].size() == 0)
        return 0;
    int& ans = dp[x];
    if (ans >= 0)
        return ans;

    ans = getcount(x) - 1;
    if (kids[x].size() <= 1)
        return ans;

    int tmp = getcount(x) - 1;
    vector<int> v;
    for (int i = 0;i < kids[x].size(); ++i)
        v.push_back(solve(kids[x][i], n) - getcount(kids[x][i]));
    sort(v.begin(), v.end());
    ans = min(ans, tmp+v[0]+v[1]);
    return ans;
}

int main()
{
    int num_cases;
    cin >> num_cases;

    for (int cas = 1;cas <= num_cases; ++cas) {
        int n;
        cin >> n;

        clear();

        for (int i = 0;i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        int res = n - 1;
        for (int root = 0;root < n; root++) {
            for (int x = 0;x < n; ++x)
                kids[x].clear();
            build_tree(root, n);
            for (int x = 0;x < n; ++x)
                dp[x] = -1, counted[x] = -1;

            res = min(res, solve(root, n));
        }

        cout << "Case #" << cas << ": " << res << endl;
    }

    return 0;
}
