#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char have[155][155];
char want[155][155];

int moo(int n, int r, int idx)
{
    vector<string> v1, v2;
    int q;

    for (int i = 0; i < n; ++ i)
    {
        string s = have[i];
        q = 0;
        for (int j = 0; j < r; ++ j)
        {
            if (have[0][j] != want[idx][j])
            {
                ++ q;
                s[j] = '1' + '0' - s[j];
            }
        }
        v1.push_back(s);

        s = want[i];
        v2.push_back(s);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (v1 == v2) return q;
    return 2000;
}

int main()
{
    int t, tt = 1;
    for (scanf("%d", &t); tt <= t; ++ tt)
    {
        int n, r;
        printf("Case #%d: ", tt);
        scanf("%d %d", &n, &r);

        for (int i = 0; i < n; ++ i)
        {
            scanf("%s", have[i]);
        }
        for (int i = 0; i < n; ++ i)
        {
            scanf("%s", want[i]);
        }

        int ans = 1005;
        for (int i = 0; i < n; ++ i)
        {
            int cur = moo(n, r, i);
            if (cur < ans) ans = cur;
        }
        if (ans == 1005)
        {
            printf("NOT POSSIBLE");
        }
        else printf("%d", ans);
        printf("\n");
    }

    return 0;
}
