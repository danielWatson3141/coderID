#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T;
int N;
vector<vector<int>> tree;

// find the least number of nodes to delete from under this node
int FindLeast(int node, int parent)
{
    const vector<int> & subTree = tree[node];
    vector<int> least;
    for (int i = 0; i < subTree.size(); ++i) // for each children
    {
        if (subTree[i] != parent)
        {
            least.push_back(FindLeast(subTree[i], node));
        }
    }
    if (least.empty())
    {
        return 0;
    }
    // find the smallest two children and add them up
    sort(least.begin(), least.end());
    // add the rest
    int total = 0;
    if (least.size() == 1) // one children, must remove
    {
        total = least[0] + 1;
    }
    else if (least.size() == 2) // two children, retain both
    {
        total = least[0] + least[1];
    }
    else // more than 2 children
    {
        for (int i = 2; i < least.size(); ++i)
        {
            total += least[i] + 1;
        }
        total += least[0] + least[1];
    }
    return total;
}

void Solve(int t)
{
    int smallest = N;
    // for each node
    for (int i = 0; i < N; ++i)
    {
        int trySmallest = FindLeast(i, -1);
        if (trySmallest < smallest)
        {
            smallest = trySmallest;
        }
    }
    if (smallest == N - 1)
        smallest = N;
    cout << "Case #" << t << ": " << smallest << endl;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> N;
        tree.resize(N);
        for (int i = 0; i < N; ++i)
        {
            tree[i].clear();
        }
        for (int i = 0; i < N - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            tree[a - 1].push_back(b - 1);
            tree[b - 1].push_back(a - 1);
        }
        Solve(t);
    }
    int a = 0;
}