#include <omp.h>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> n, l;
vector<vector<string> > o, d;
vector<vector<int> > q1, q2;
vector<int> ans;

int solve(int num, int pos = 0, int cur = 0)
{
    if (pos == l[num])
    {
        set<string> s1, s2;
        for (int i = 0; i < n[num]; ++i)
        {
            s1.insert(o[num][i]);
            s2.insert(d[num][i]);
        }
        if (s1 == s2)
        {
            return cur;
        }
        return -1;
    }
    int ans = -1;
    if (q1[num][pos] == q2[num][pos])
    {
        ans = solve(num, pos + 1, cur);
    }
    if (q1[num][pos] == n[num] - q2[num][pos])
    {
        for (int i = 0; i < n[num]; ++i)
        {
            d[num][i][pos] = d[num][i][pos] == '0' ? '1' : '0';
        }
        int dd = solve(num, pos + 1, cur + 1);
        if (ans == -1 || (dd != -1 && dd < ans))
        {
            ans = dd;
        }
        for (int i = 0; i < n[num]; ++i)
        {
            d[num][i][pos] = d[num][i][pos] == '0' ? '1' : '0';
        }
    }
    return ans;
}

int main(void)
{
    int q;
    cin >> q;
    n.assign(q, 0);
    l.assign(q, 0);
    ans.assign(q, 0);
    for (int i = 0; i < q; ++i)
    {
        cin >> n[i] >> l[i];
        o.push_back(vector<string>(n[i]));
        for (int j = 0; j < n[i]; ++j)
        {
            cin >> o[i][j];
        }
        d.push_back(vector<string>(n[i]));
        for (int j = 0; j < n[i]; ++j)
        {
            cin >> d[i][j];
        }
        q1.push_back(vector<int>(l[i]));
        q2.push_back(vector<int>(l[i]));
        for (int j = 0; j < n[i]; ++j)
        {
            for (int k = 0; k < l[i]; ++k)
            {
                if (o[i][j][k] == '1')
                {
                    ++q1[i][k];
                }
                if (d[i][j][k] == '1')
                {
                    ++q2[i][k];
                }
            }
        }
    }
#pragma omp parallel for
    for (int i = 0; i < q; ++i)
    {
        ans[i] = solve(i);
    }
    for (int i = 0; i < q; ++i)
    {
        if (ans[i] < 0)
        {
            cout << "Case #" << (i + 1) << ": " << "NOT POSSIBLE\n";
        }
        else
        {
            cout << "Case #" << (i + 1) << ": " << ans[i] << "\n";
        }
    }
    return 0;
}
