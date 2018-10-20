/*********************************************************************************
*     File Name           :     A.cpp
*     Created By          :     YIMMON, yimmon.zhuang@gmail.com
*     Creation Date       :     [2014-04-26 08:39]
*     Last Modified       :     [2014-04-26 11:11]
*     Description         :
**********************************************************************************/

#include  <iostream>
#include  <cstdio>
#include  <cstring>
#include  <cstdlib>
#include  <cmath>
#include  <algorithm>
#include  <queue>
#include  <vector>
#include  <map>
#include  <stack>
#include  <string>
using namespace std;

int T, n, l, cnt[2][200];
vector <string> vec[2];
int vst[200];
const int inf = 99999999;

void flip(int x)
{
    for (int j = 0; j < n; j++)
        if (vec[0][j][x] == '1')
            vec[0][j][x] = '0';
        else
            vec[0][j][x] = '1';
}

int dfs(int ans, int k)
{
    if (k >= l)
    {
        for (int i = 0; i < n; i++)
            if (vec[0][i] != vec[1][i])
                return inf;
        return ans;
    }

    int kk;
    for (kk = k + 1; kk < l && vst[kk] == 0; kk++)
        ;
    int q;
    for (q = 0; q < n; q++)
    {
        for (int p = 0; p < k; p++)
            if (vec[0][q][p] != vec[1][q][p])
                return inf;
        if (vec[0][q][k] != vec[1][q][k])
        {
            flip(k);
            sort(vec[0].begin(), vec[0].end());
            int tmp = dfs(ans + 1, kk);
            flip(k);
            sort(vec[0].begin(), vec[0].end());
            return tmp;
        }
    }
    int tmp = dfs(ans, kk);
    flip(k);
    sort(vec[0].begin(), vec[0].end());
    tmp = min(tmp, dfs(ans + 1, kk));
    flip(k);
    sort(vec[0].begin(), vec[0].end());
    return tmp;
}

void solve()
{
    memset(vst, 0, sizeof(vst));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cnt[i][j] = 0;
            for (int k = 0; k < n; k++)
                if (vec[i][k][j] == '1')
                    cnt[i][j]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < l; i++)
    {
        if (cnt[0][i] == cnt[1][i])
        {
            if (cnt[0][i] == n - cnt[0][i])
                vst[i] = 1;
        }
        else if (cnt[0][i] == n - cnt[1][i])
        {
            ans++;
            flip(i);
        }
        else
        {
            puts("NOT POSSIBLE");
            return;
        }
    }
    sort(vec[1].begin(), vec[1].end());
    for (;;)
    {
        sort(vec[0].begin(), vec[0].end());
        int i;
        for (i = 0; i < n; i++)
            if (vec[0][i] != vec[1][i])
                break;
        if (i >= n)
            break;
        int k;
        for (k = 0; k < l && vst[k] == 0; k++)
            ;
        if (vst[k] == 0)
        {
            puts("NOT POSSIBLE");
            return;
        }
        ans = dfs(ans, k);
        if (ans >= inf)
        {
            puts("NOT POSSIBLE");
            return;
        }
        break;
    }
    printf("%d\n", ans);
}

int main(int argc, char *argv[])
{
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        printf("Case #%d: ", cas);
        scanf("%d%d", &n, &l);
        vec[0].clear(), vec[1].clear();
        for (int i = 0 ; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                string tmp;
                cin >> tmp;
                vec[i].push_back(tmp);
            }
        }
        solve();
    }

    return 0;
}
