#include <iostream>
#include <vector>
#include <queue>

#define N 1010

using namespace std;

vector<int> e[N + N + 10];

void addEdge(int a, int b)
{
    e[a].push_back(b);
    e[b].push_back(a);
}

bool visited[N + 10];

int f(int v)
{
    visited[v] = true;

    priority_queue<int> q;
    for (int i = 0; i < e[v].size(); ++i)
        if (!visited[e[v][i]])
            q.push(f(e[v][i]));

    int ans = 1;
    if (q.size() >= 2)
    {
        ans += q.top();
        q.pop();
        ans += q.top();
        q.pop();
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; ++cs)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            e[i].clear();
        for (int i = 0; i < n - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            addEdge(a, b);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            memset(visited, false, sizeof(visited));
            ans = max(ans, f(i));
        }

        cout << "Case #" << cs << ": " << n - ans << endl;
    }
    return 0;
}
