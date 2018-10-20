#include <assert.h>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int sm[1005][1005];
int total[1005];
int good[1005];
int n;

int dfs(int idx, int fr = -1)
{
    good[idx] = 0;
    total[idx] = 1;
    vector<pair<int, int> > moo;
    for (int i = 0; i < n; ++ i) if (sm[idx][i] && i != fr)
    {
        dfs(i, idx);
        moo.push_back(make_pair(good[i] - total[i], i));
    }
    int allow = 2;
    if (moo.size() == 1) allow = 0;
    sort(moo.begin(), moo.end());
    for (int i = 0; i < moo.size(); ++ i)
    {
        if (i >= allow)
        {
            good[idx] += total[moo[i].second];
        }
        else good[idx] += good[moo[i].second];
        total[idx] += total[moo[i].second];
    }
    return good[idx];
}

int main()
{

    int tt;
    scanf("%d", &tt);

    for (int t = 1; t <= tt; ++ t)
    {
        memset(sm, 0, sizeof(sm));
        scanf("%d", &n);
        for (int i = 0 ; i < n - 1; ++ i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            -- a; -- b;
            sm[a][b] = 1;
            sm[b][a] = 1;
        }

        int ans = 1005;
        for (int i = 0; i < n; ++ i)
        {
            int cur = dfs(i);
//            printf("%d\n", cur);
            if (cur != -1 && cur < ans)
                ans = cur;
            assert(total[i] = n);
        }
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}
