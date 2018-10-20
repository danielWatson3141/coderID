#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

string A[200], B[200], AA[200], BB[200], C[200];
int N, L;
int ca[200], cb[200], T[200];
bool change[200];
bool imp;
int curans;

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

    if (ans < curans)
        curans = ans;

    return ans;
}

bool prove(int pos)
{
    if (pos == 0)
        return true;

    for (int i = 0; i < N; i++)
    {
        C[i] = A[i];
        C[i].resize(pos);
    }
    changeF();

    sort(C, C+N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < pos; j++)
            if (C[i][j] != B[i][j])
                return false;

    return true;
}

int ans(int pos, int cc)
{
    if (imp)
        return 0;
    if (cc >= curans)
        return curans;

    if (pos == L)
        return calcans();

    if (prove(pos) == false)
        return 1000000;

    int Ca = ca[pos], Cb = cb[pos];

    if (Ca != Cb && N-Ca != Cb)
    {
        imp = true;
        return 0;
    }

    if (Ca == N/2 && Cb == N/2 && N%2==0)
    {
        change[pos] = 0;
        int res1 = ans(pos+1,cc);
        change[pos] = 1;
        int res2 = ans(pos+1,cc+1);
        return min(res1, res2);
    }

    if (Ca == Cb)
    {
        change[pos] = 0;
        return ans(pos+1, cc);
    }
    else
    {
        change[pos] = 1;
        return ans(pos+1, cc+1);
    }


}

void solve(int TT)
{
    cerr << TT << endl;
    int res;
    cin >> N >> L;
    for (int j = 0; j < N; j++)
    {
        cin >> A[j];
        AA[j] = A[j];
    }
    for (int j = 0; j < N; j++)
    {
        cin >> B[j];
        BB[j] = B[j];
    }

    for (int i = 0; i < L; i++)
        T[i] = i;
    random_shuffle(T, T+L);

    for (int j = 0; j < N; j++)
        for (int i = 0; i < L; i++)
        {
            A[j][i] = AA[j][T[i]];
            B[j][i] = BB[j][T[i]];
        }

    sort(B, B+N);
    imp = false;

    for (int j = 0; j < L; j++)
    {
        ca[j] = cb[j] = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i][j] == '1')
                ca[j]++;
            if (B[i][j] == '1')
                cb[j]++;
        }
    }

    curans = 100000;
    res = ans(0, 0);

    if (res > 1000)
        imp = true;

    if (imp)
        cout << "Case #" << TT << ": " << "NOT POSSIBLE" << endl;
    else
        cout << "Case #" << TT << ": " << res << endl;
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

