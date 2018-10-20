#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int>> Edges;

inline pair<Edges::const_iterator, Edges::const_iterator> erange(int i, const Edges& edges)
{
    Edges::const_iterator from = lower_bound(edges.begin(), edges.end(), make_pair(i, 0));
    Edges::const_iterator to = upper_bound(edges.begin(), edges.end(), make_pair(i, 100000));
    return make_pair(from, to);
}

static pair<int, int> eval(int n, int idx, const Edges& edges, vector<bool>& visited)
{
    auto es = erange(idx, edges);
    vector<pair<int, int>> subtrees; // size, deleted
    int size = 1;
    while (es.first != es.second)
    {
        int b = es.first->second; // Index of the second node
        ++es.first;
        if (visited[b]) continue; else visited[b] = true;
        auto t = eval(n, b, edges, visited);
        subtrees.push_back(t);
        size += t.first;
    }

    pair<int, int> result(size, 0);
    if (subtrees.size() == 1)
    {
        result.second = subtrees[0].first;
        // keep only single node
    }
    else if (subtrees.size() == 2)
    {
        auto t1 = subtrees[0];
        auto t2 = subtrees[1];
        result.second = t1.second + t2.second;
    }
    else if (subtrees.size() > 2)
    {
        sort(subtrees.begin(), subtrees.end());

        int d = 0;
        for (auto p: subtrees) d += p.first;

        int keep = -1;
        int md = d;
        for (int i = 0; i < subtrees.size(); ++i)
        {
            int t = d - subtrees[i].first + subtrees[i].second;
            if (t < md)
            {
                keep = i;
                md = t;
            }
        }
        d = md;
        for (int i = 0; i < subtrees.size(); ++i)
        {
            if (i == keep) continue;
            int t = d - subtrees[i].first + subtrees[i].second;
            if (t < md) md = t;
        }

        result.second = md;
    }
    // cerr << idx + 1 << ": <" << result.first << "," << result.second << ">" << endl;
    return result;
}

static int solve(int n, const Edges& edges)
{
    int result = n - 1;
    for (int i = 0; i < n; ++i)
    {
        // cerr << "Trying " << i + 1 << endl;
        // i is a root, count how much we should delete
        vector<bool> visited(n, false);
        visited[i] = true;
        result = min(result, eval(n, i, edges, visited).second);
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    for (int qq = 1; qq <= t; ++qq)
    {
        int n;
        cin >> n;
        Edges edges;
        edges.reserve(2 * n);
        for (int i = 0; i < n - 1; ++i)
        {
            int x, y;
            cin >> x >> y;
            --x;
            --y;
            edges.push_back(make_pair(x, y));
            edges.push_back(make_pair(y, x));
        }
        sort(edges.begin(), edges.end());

        cout << "Case #" << qq << ": " << solve(n, edges) << endl;
    }
    return 0;
}
