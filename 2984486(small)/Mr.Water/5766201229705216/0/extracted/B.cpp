// GCJ 2014 Qualification Round 1A
// problem B

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int f[MAXN], subtree[MAXN], parent[MAXN];
bool visited[MAXN], g[MAXN][MAXN];

void dp(int node, int n)
{
    int largest = 0, second_largest = 0, i, child = 0;

    visited[node] = true;
    subtree[node] = 1;
    for (i = 0; i < n; i++)
        if (!visited[i] && g[node][i])
        {
            child++;
            parent[i] = node;
            dp(i, n);
            subtree[node] += subtree[i];

            int remain = subtree[i] - 1 - f[i];

            if (remain > largest)
            {
                second_largest = largest;
                largest = remain;
            }
            else if (remain <= largest && remain > second_largest)
                second_largest = remain;
        }

    if (child == 0)
        f[node] = 0;
    else if (child == 1)
        f[node] = subtree[node] - 1;
    else
        f[node] = subtree[node] - 1 - 2 - largest - second_largest;

}

int main()
{
    FILE *fin  = fopen("B.in", "r");
    FILE *fout = fopen("B.out", "w");

    int test_case, test_now, n, i, j, ans;

    fscanf(fin, "%d", &test_case);

    for (test_now = 1; test_now <= test_case; test_now++)
    {
        fscanf(fin, "%d", &n);

        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                g[i][j] = false;

        for (i = 0; i < n - 1; i++)
        {
            int a, b;
            fscanf(fin, "%d%d", &a, &b);
            g[a - 1][b - 1] = g[b - 1][a - 1] = true;
        }

        ans = n;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                visited[j] = false, parent[j] = -1;
            dp(i, n);
            if (f[i] < ans)
                ans = f[i];
        }

        fprintf(fout, "Case #%d: %d\n", test_now, ans);

        printf("test #%d finished\n", test_now);
    }

    fclose(fout);
    fclose(fin);
    return 0;
}



