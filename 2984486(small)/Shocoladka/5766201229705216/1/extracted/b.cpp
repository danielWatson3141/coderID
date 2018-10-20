#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int maxn = 1e3 + 3;

vector<int> gr[maxn];
int h[maxn];

int dfs(int x, int p = -1)
{
    h[x] = 1;
    for(int i = 0; i < gr[x].size(); i++)
        if(gr[x][i] != p)
            dfs(gr[x][i], x);

    if((p != -1 && gr[x].size() < 3) || (p == -1 && gr[x].size() < 2))
        return h[x];

    int max1 = 0, max2 = 0;

    for(int i = 0; i < gr[x].size(); i++)
    {
        int cur = gr[x][i];
        if(cur != p)
        {
            if(h[cur] > max1)
            {
                max2 = max1;
                max1 = h[cur];
            }
            else if(h[cur] > max2)
            {
                max2 = h[cur];
            }
        }
    }
    h[x] = max1 + max2 + 1;

    return h[x];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        cout << "Case #" << t + 1 << ": ";
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            gr[i].clear();
        int mnans = n - 1;
        for(int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            x--; y--;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }

        for(int i = 0; i < n; i++)
        {
            mnans = min(mnans, n - dfs(i));
        }

        cout << mnans << endl;
    }
}
