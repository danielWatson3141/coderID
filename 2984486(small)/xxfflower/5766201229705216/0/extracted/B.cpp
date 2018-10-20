#include <iostream>
#include <set>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

const int MAXN = 1000;

int f[MAXN + 1];
map<int, set<int>> g;

int t, n, ans;

bool found;

bool buildTree(const set<int>& v, int root)
{
    if (v.count(root) == 0) return false;

    queue<int> q;
    q.push(root); 

    set<int> tree;

    tree.insert(root); 

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        int count = 0;

        for (auto child : g[parent])
        {
            if (v.count(child) && !tree.count(child))
            {
                q.push(child);
                tree.insert(child);
                count++;
            }
        }

        if (count == 0 || count == 2)
        {
            
        }
        else
        {
            return false;
        }
    }

    if (tree != v) return false;

    for (auto child : v)
        cerr << child << " ";

    cerr << "root = " << root << endl;

    return true;
}

void dfs(int d, int d_t, int s, set<int>& v)
{
    if (d == d_t)
    {
        for (const auto& p : v)
        {
            if (buildTree(v, p))
            {
                ans = d;
                found = true;
                break;
            }
        }

        return;
    }

    for (int i = s; i < n && !found; i++)
    {
        if (f[i]) continue;
        f[i] = true;
        v.erase(i + 1);
        dfs(d + 1, d_t, i + 1, v);
        v.insert(i + 1);
        f[i] = false;
    }
    
}

int main()
{   
    cin >> t;
    for (int c = 1; c <= t; c++)
    {        
        cin >> n;

        found = false;

        ans = n + 1;

        g.clear();

        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].insert(y);
            g[y].insert(x);
        }

        set<int> v;

        for (int i = 1; i <= n; i++)
            v.insert(i); 

        for (int i = 0; i <= n - 1 && !found; i++)
        {
            dfs(0, i, 0, v);
        }


        cout << "Case #"<<c<<": "<<ans << endl;
    }
    return 0;
}