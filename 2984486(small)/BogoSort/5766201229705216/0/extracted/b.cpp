#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int getSize(int root, int father, vector<int> edge[])
{
    vector<int> s;
    for (int i = 0; i < edge[root].size(); ++i)
    {
        if (edge[root][i] == father) continue;
        s.push_back(getSize(edge[root][i], root, edge));
    }
    sort(s.begin(), s.end(), cmp);
    if (s.size() == 0) return 1;
    if (s.size() == 1) return 1;
    return s[0] + s[1] + 1;
}

int solve()
{
    int n;
    cin >> n;
    vector<int> edge[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int ans = n;
    for (int i = 1; i <= n; ++i)
    {
        int p = n - getSize(i, 0, edge);
        if (p < ans) ans = p;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}
