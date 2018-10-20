#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

ifstream fin("data.txt");
ofstream fout("output.txt");

typedef vector< list<int> > Tree;

void construct_direct(Tree &undirect, Tree &direct, int root)
{
    for (auto i = undirect[root].begin(); i != undirect[root].end(); ++i)
    {
        direct[root].push_back(*i);

        undirect[*i].remove(root);
    }

    for (auto i = direct[root].begin(); i != direct[root].end(); ++i)
    {
        construct_direct(undirect, direct, *i);
    }
}

int children_count(Tree &direct, int root)
{
    int count = direct[root].size();

    for (auto i = direct[root].begin(); i != direct[root].end(); ++i)
        count += children_count(direct, *i);

    return count;
}

int dfs(Tree &direct, int root)
{
    size_t size = direct[root].size();
    if (size == 0)  return 0;
    else if (size == 1)
    {
        return children_count(direct, root);
    }
    else if (size == 2)
    {
        int d = dfs(direct, *direct[root].begin());
        int e = dfs(direct, *direct[root].rbegin());

        return d + e;
    }
    else
    {
        vector<int> d(size), f(size);
        int sum_f = 0;

        int k = 0;
        for (auto i = direct[root].begin(); i != direct[root].end(); ++i, ++k)
        {
            d[k] = dfs(direct, *i);
            f[k] = children_count(direct, *i) + 1;

            sum_f += f[k];
        }

        int result = 1000000;
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = i + 1; j < size; ++j)
            {
                int x = d[i] + d[j] + sum_f - f[i] - f[j];
                result = min(result, x);
            }
        }

        return result;
    }
}
void run_once()
{
    Tree undirect, direct;

    int n;
    fin >> n;

    undirect.resize(n+1);
    direct.resize(n+1);

    for (int i = 1; i < n; ++i)
    {
        int u, v;
        fin >> u >> v;

        undirect[u].push_back(v);
        undirect[v].push_back(u);
    }

    int result = 10000000;
    for (int root = 1; root <= n; ++root)
    {
        direct.clear();
        direct.resize(n+1);
        Tree t = undirect;
        construct_direct(t, direct, root);

        int x = dfs(direct, root);
        result = min(result, x);
    }

    fout << result << endl;
}

int main()
{
    int case_count;
    fin >> case_count;

    for (int case_id = 1; case_id <= case_count; ++case_id)
    {
        fout << "Case #" << case_id << ": ";
        run_once();
    }

    return 0;
}