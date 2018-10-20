#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

string A[200], B[200], C[200];
int N, L;
bool change[200];
bool imp;

void changeF()
{
    for (int i = 0; i < L; i++)
        if (change[i])
            for (int j = 0; j < N; j++)
                C[j][i] = '0' + (1-(C[j][i]-'0'));
}

int calcans()
{
    for (int i = 0; i < N; i++)
        C[i] = A[i];
    changeF();
    sort(C, C+N);
    for (int i = 0; i < N; i++)
        if (C[i] != B[i])
            return 1000000;
    int ans = 0;
    for (int i = 0; i < L; i++)
        if (change[i])
            ans++;
    return ans;
}

int ans(int pos)
{
    if (imp)
        return 0;

    if (pos == L)
        return calcans();

    int ca = 0, cb = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i][pos] == '1')
            ca++;
        if (B[i][pos] == '1')
            cb++;
    }

    if (ca != cb && N-ca != cb)
    {
        imp = true;
        return 0;
    }

    if (ca == N/2 && cb == N/2 && N%2==0)
    {
        change[pos] = 0;
        int res1 = ans(pos+1);
        change[pos] = 1;
        int res2 = ans(pos+1);
        return min(res1, res2);
    }

    if (ca == cb)
        change[pos] = 0;
    else
        change[pos] = 1;

    return ans(pos+1);
}

void solve(int T)
{
    cerr << T << endl;
    int res;
    cin >> N >> L;
    for (int j = 0; j < N; j++)
        cin >> A[j];
    for (int j = 0; j < N; j++)
        cin >> B[j];

    sort(B, B+N);
    imp = false;
    res = ans(0);

    if (res > 1000)
        imp = true;

    if (imp)
        cout << "Case #" << T << ": " << "NOT POSSIBLE" << endl;
    else
        cout << "Case #" << T << ": " << res << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}

