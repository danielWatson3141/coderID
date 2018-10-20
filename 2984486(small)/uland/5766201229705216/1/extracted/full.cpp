#include <cstdio>
#include <vector>
#define var(a, b) typeof(b) a = (b)
#define foreach(iter, cont) for (var(iter, (cont).begin()); iter != (cont).end(); ++iter)

using namespace std;

const int maxN = 2000;

int n;
vector<int> g[maxN + 1];

bool visited[maxN + 1];
int formed[maxN + 1];
int removed[maxN + 1];

void dfs(int x)
{
    visited[x] = true;
    removed[x] = 1;
    int q1 = 0, q2 = 0;
    int childCnt = 0;
    foreach (i, g[x]) {
        if (!visited[*i]) {
            //printf("%d -> %d\n", x, *i);
            ++childCnt;
            dfs(*i);
            removed[x] += removed[*i];
            int diff = removed[*i] - formed[*i];
            if (diff > q1) {
                q2 = q1;
                q1 = diff;
            } else if (diff > q2) {
                q2 = diff;
            }
        }
    }
    if (childCnt < 2) {
        formed[x] = removed[x] - 1;
    } else {
        formed[x] = removed[x] - 1 - q1 - q2;
    }
    //printf("@ %d formed = %d removed = %d (%d)\n", x, formed[x], removed[x], childCnt);
}

int withRoot(int root)
{
    for (int i = 1; i <= n; ++i)
        visited[i] = false;
    dfs(root);
    return formed[root];
}

int testCase()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        g[i] = vector<int>();
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int best = n;
    for (int i = 1; i <= n; ++i) {
        int tmp = withRoot(i);
        //printf("%d : %d\n", i, tmp);
        if (best > tmp)
            best = tmp;
    }
    return best;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int r = testCase();
        printf("Case #%d: %d\n", i, r);
    }
}