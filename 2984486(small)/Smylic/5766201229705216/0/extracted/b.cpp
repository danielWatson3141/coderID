#include <iostream>
#include <vector>

using namespace std;

vector<int> a[1024];
int c[1024];
int d[1024];
int e[1024];
int s[1024];

void dfs(int i, int p)
{
    for (int j=0; j<a[i].size(); j++)
        if (a[i][j] != p)
            dfs(a[i][j], i);

    s[i] = 1;
    e[i] = 1;
    c[i] = 0;
    d[i] = 1 + (p >= 0);

    int u = -1, v = -1, w = -1, x = -1, y = -1, z = -1;

    for (int j=0; j<a[i].size(); j++)
        if (a[i][j] != p)
        {
            s[i] += s[a[i][j]];
            e[i] = max(e[i], e[a[i][j]]);

            if (!~u || c[u] < c[a[i][j]])
                u = a[i][j];
            if (!~v || c[v] < c[u])
                swap(u, v);
            if (!~w || c[w] < c[v])
                swap(v, w);

            if (!~x || d[x] < d[a[i][j]])
                x = a[i][j];
            if (!~y || d[y] < d[x])
                swap(x, y);
            if (!~z || d[z] < d[y])
                swap(y, z);
        }

    if (~y)
        e[i] = max(e[i], d[y] + d[z] - 1);

    if (~w)
        e[i] = max(e[i], c[w]);

    if (~x)
    {
        e[i] = max(e[i], c[w] + (w != z ? d[z] : 0) + (w != y ? d[y] : 0) + (w == z || w == y ? d[x] : 0) - 2);
        e[i] = max(e[i], c[v] + (v != z ? d[z] : 0) + (v != y ? d[y] : 0) + (v == z || v == y ? d[x] : 0) - 2);
        e[i] = max(e[i], c[u] + (u != z ? d[z] : 0) + (u != y ? d[y] : 0) + (u == z || u == y ? d[x] : 0) - 2);
    }

    if (~z && p >= 0)
        c[i] = max(c[i], d[z] + 1);

    if (~y && p >= 0)
    {
        c[i] = max(c[i], c[w] + (w != z ? d[z] : d[y]));
        c[i] = max(c[i], c[v] + (v != z ? d[z] : d[y]));
    }

    if (~y && p >= 0)
        d[i] = max(d[i], d[z] + d[y]);

//    cout << i << "   " << e[i] << " " << c[i] << " " << d[i] << "   " << z << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int n;
        cin >> n;

        for (int i=0; i<n; i++)
            a[i].clear();

        for (int i=0; i<n-1; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        dfs(0, -1);

        cout << "Case #" << tt << ": " << n - e[0] << endl;
    }
    return 0;
}
