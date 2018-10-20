// root@lyq.me 2014-4-26

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define ll long long

int n, L;
int a[200], b[200];
ll map[200][200];

int cmp(const void *a, const void *b)
{
    int p1 = *(int*)a, p2 = *(int*)b;
    return p1 - p2;
}
int find(int i, ll num)
{
    int left, right, mid;

    left = 0; right = n-1;
    while (left < right)
    {
        mid = (left+right) >> 1;
        if (map[i][mid] < num) left = mid + 1;
            else right = mid;
    }

    if (map[i][left] != num) return -1;

    return left;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int Test;
    cin>>Test;
    for (int tt = 1; tt <= Test; tt++)
    {
        int d;
        scanf("%d %d\n", &n, &L);
        for (int i = 0; i < n; i++)
        {
            a[i] = 0;
            for (int j = 0; j < L; j++)
            {
                d = (int)(getchar()-48);
                a[i] = a[i]*2 + d;
            }
            getchar();
        }
        for (int i = 0; i < n; i++)
        {
            b[i] = 0;
            for (int j = 0; j < L; j++)
            {
                d = (int)(getchar()-48);
                b[i] = b[i]*2 + d;
            }
            getchar();
        }

        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i][j] = a[i] ^ b[j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) a[j] = map[i][j];
            qsort(a, n, sizeof(int), cmp);
            for (int j = 0; j < n; j++) map[i][j] = a[j];
        }

        int ans, k1, k2, temp;
        ll k3;

        ans = temp = 100000;
        for (int i = 0; i < n; i++)
        {
            for (k1 = 1; k1 < n; k1++)
            {
                k2 = find(k1, map[0][i]);
                if (k2 == -1) break;
            }
            if (k1 == n)
            {
                temp = 0;
                k3 = map[0][i];
                while (k3 > 0)
                {
                    if (k3 & 1) temp++;
                    k3 >>= 1;
                }
            }
            ans = min(ans, temp);
        }
        if (ans == 100000)
        {
            printf("Case #%d: NOT POSSIBLE\n", tt);
        }else
        {
            printf("Case #%d: %d\n", tt, ans);
        }
    }
    return 0;
}
