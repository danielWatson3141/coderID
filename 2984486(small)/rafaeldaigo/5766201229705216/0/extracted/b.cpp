#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int mat[1100][1100];
int len[1100];

int calc(int node, int parent)
{
    int i;
    int neig = len[node];
    int best = 0;
    int secondbest = 0;
    int ans = 1;
    for (i = 0; i < neig; i++)
    {
        int next = mat[node][i];
        if (next == parent)
            continue;
        int cand = calc(next, node);
        if (cand > best)
        {
            secondbest = best;
            best = cand;
        }
        else if (cand > secondbest)
        {
            secondbest = cand;
        }
    }
    if (secondbest != 0)
    {
        ans += best + secondbest;
    }
    return ans;
}

int main()
{
    int t, teste;
    int i;
    int n;
    int a, b;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d\n", &n);
        for (i = 0; i < n; i++)
        {
            len[i] = 0;
        }
        for (i = 1; i < n; i++)
        {
            scanf("%d %d\n", &a, &b);
            a--;
            b--;
            mat[a][len[a]++] = b;
            mat[b][len[b]++] = a;
        }
        int best = n - 1;

        for (i = 0; i < n; i++)
        {
            int cand = n - calc(i, -1);
            if (best > cand)
                best = cand;
        }

        printf("Case #%d: %d\n", t + 1, best);
    }
    return 0;
}
