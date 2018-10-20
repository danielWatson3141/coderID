#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

vector<vector<int> > G;
vector<bool> in_use;
vector<bool> used;
int n;

bool dfs(int u, int p = -1)
{
    // cout << "u: " << u << endl;
    used[u] = true;
    int amount = 0;
    for (int i = 0; i < G[u].size(); ++i)
    {
        // cout << G[u][i] << endl;
        if (G[u][i] != p && in_use[G[u][i]])
        {
            ++amount;
            // cout << "to: " << G[u][i] << endl;
        }
    }
    // cout << amount << endl;
    if (amount == 0)
        return true;
    else if (amount == 2)
    {
        bool is_good = true;
        for (int i = 0; i < G[u].size(); ++i)
            if (G[u][i] != p && in_use[G[u][i]])
            {
                // cout << G[u][i] << " " << int(dfs(G[u][i])) << endl;
                is_good &= dfs(G[u][i], u);
            }
        return is_good;
    }
    else
        return false;
}

bool check(int u)
{
    used.assign(n, false);
    bool is_good = dfs(u);
    // cout << int(is_good) << endl;
    for (int i = 0; i < n; ++i)
        if (in_use[i] && !used[i])
            return false;
    return is_good;
}

int get_bit(int n, int x)
{
    return (n >> x) & 1;
}

int count(vector<bool> a)
{
    int answer = 0;
    for (int i = 0; i < a.size(); ++i)
        answer += int(a[i]);
    return answer;
}

int main()
{
    ifstream cin("input.txt");
    // ofstream cout("output.txt");
    int t;
    cin >> t;
    G.resize(100);
    for (int q = 0; q < t; ++q)
    {
        int answer = -1;
        cin >> n;
        in_use.assign(n, false);
        for (int i = 0; i < n; ++i)
            G[i].clear();
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u - 1].push_back(v - 1);
            G[v - 1].push_back(u - 1);
        }
        // cout << "G" << endl;
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < G[i].size(); ++j)
        //         cout << G[i][j] << " ";
        //     cout << endl;
        // }
        for (int mask = 0; mask < pow(2, n); ++mask)
        {
            for (int i = 0; i < n; ++i)
                in_use[i] = get_bit(mask, i);

            // for (int i = 0; i < n; ++i)
            //     cout << in_use[i] << " ";
            // cout << endl;
            for (int i = 0; i < n; ++i)
            {
                if (!in_use[i]) continue;
                // cout << "start: " << i << endl;
                if (check(i))
                    answer = max(answer, count(in_use));
            }
        }
        cout << "Case #" << q + 1 << ": " << n - answer << endl;   
    }
}