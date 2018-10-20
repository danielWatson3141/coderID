#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

vector <vector <char> > masks1;
vector <vector <char> > masks2;
vector <vector <char> > newm1;

int getCnt(const vector <char> &a)
{
    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += a[i];
    return ans;
}

vector <char> getMask(const vector<char> &a, const vector<char> &b)
{
    vector <char> ans(a.size());
    for (int i = 0; i < a.size(); i++)
        ans[i] = (a[i] != b[i]);
    return ans;
}

void applyMask(vector <char> &a, const vector <char> &mask)
{
    for (int i = 0; i < a.size(); i++)
        a[i] = (a[i] + mask[i]) % 2;
}

bool comp(const vector<char> &a, const vector <char> &b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}

bool CheckMask(const vector<char> &mask)
{
    newm1 = masks1;
    for (int i = 0; i < newm1.size(); i++)
        applyMask(newm1[i], mask);
    sort(newm1.begin(), newm1.end(), comp);
    for (int i = 0; i < newm1.size(); i++)
        if (newm1[i] != masks2[i])
            return false;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int q = 0; q < t; q++)
    {
        printf("Case #%d: ", q + 1);
        int n, l;
        scanf("%d %d\n", &n, &l);
        masks1.resize(n);
        for (int i = 0; i < n; i++)
            masks1[i].resize(l);
        masks2.resize(n);
        for (int i = 0; i < n; i++)
            masks2[i].resize(l);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < l; j++)
            {
                scanf("%c", &masks1[i][j]);
                masks1[i][j] -= '0';
            }
            scanf(" ");
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < l; j++)
            {
                scanf("%c", &masks2[i][j]);
                masks2[i][j] -= '0';
            }
            scanf(" ");
        }

        int ans = -1;

        sort(masks2.begin(), masks2.end(), comp);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                vector <char> m = getMask(masks1[i], masks2[j]);
                if (CheckMask(m))
                {
                    if (ans == -1)
                        ans = getCnt(m);
                    else
                        ans = min(ans, getCnt(m));
                }
            }

        if (ans == -1)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
