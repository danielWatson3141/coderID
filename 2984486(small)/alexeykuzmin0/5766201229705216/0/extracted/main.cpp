#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int _time;
vector<vector<int> > e;
vector<int> marks;
vector<int> delete_cost;

int DFS(int v)
{
    if (marks[v] == _time)
    {
        return 0;
    }
    marks[v] = _time;
    delete_cost[v] = 1;
    for (int i = 0; i < (int)e[v].size(); ++i)
    {
        delete_cost[v] += DFS(e[v][i]);
    }
    return delete_cost[v];
}

int DFS2(int v)
{
    if (marks[v] == _time)
    {
        return -1;
    }
    marks[v] = _time;
    vector<int> p1;
    vector<int> p2;
    for (int i = 0; i < (int)e[v].size(); ++i)
    {
        int t = DFS2(e[v][i]);
        if (t > -1)
        {
            p2.push_back(t);
            p1.push_back(delete_cost[e[v][i]]);
        }
    }
    if (p1.size() == 0)
    {
        return 0;
    }
    if (p1.size() == 1)
    {
        return p1[0];
    }
    vector<pair<int, int> > p3(p1.size(), make_pair(0, 0));
    for (int i = 0; i < (int)p1.size(); ++i)
    {
        p3[i] = make_pair(p1[i] - p2[i], i);
    }
    sort(p3.begin(), p3.end());
    int ans = p2[p3[0].second] + p2[p3[1].second];
    for (int i = 2; i < (int)p1.size(); ++i)
    {
        ans += p1[p3[i].second];
    }
    return ans;
}

int main(void)
{
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i)
    {
        cin >> n;
        e.assign(n, vector<int>());
        for (int j = 0; j < n - 1; ++j)
        {
            int a, b;
            cin >> a >> b;
            e[--a].push_back(--b);
            e[b].push_back(a);
        }
        marks.assign(n, 0);
        delete_cost.assign(n, 0);
        int ans = n + 5;
        for (int j = 0; j < n; ++j)
        {
            _time = 2 * j + 1;
            DFS(j);
            _time = 2 * j + 2;
            ans = min(ans, DFS2(j));
        }
        cout << "Case #" << (i + 1) << ": " << ans << "\n";
    }
    return 0;
}
