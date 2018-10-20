#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <memory.h>

using namespace std;

vector<int> g[2000];
int nc[2000];

ofstream out;

void num_childs(int v, int p)
{
    int res = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p)
        {
            num_childs(g[v][i], v);
            res += nc[g[v][i]];
        }
    nc[v] = res;
}

int find_ans(int v, int p)
{
    int ans1 = 1;
    if (p == -1 && g[v].size() <= 1)
        return ans1;
    if (p != -1 && g[v].size() <= 2)
        return ans1;

    vector<int> r;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p)
            r.push_back( find_ans(g[v][i], v) );

    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());

    return 1 + r[0] + r[1];
}

void solve(int T)
{
    cerr << "case " << T << endl;
    int n;
    cin >> n;
    int res = n-1;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cerr << "case " << T << endl;

    for (int root = 0; root < n; root++)
    {
        memset(nc, 0, sizeof nc);
        cerr << "case " << T << "+ " << root << endl;
        num_childs(root, -1);
        cerr << "case " << T << "- " << root << endl;
        int cr = n - find_ans(root, -1);
        cerr << "case " << T << "= " << root << endl;
        if (cr < res)
            res = cr;

    }

    out << "Case #" << T << ": " << res << endl;

    for (int i = 0; i < n; i++)
    {
        g[i].clear();
    }
    cerr << "case " << T << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    out.open("output.txt");
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++ )
        solve(i);
    return 0;
}

