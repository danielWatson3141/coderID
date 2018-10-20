#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <queue>
#include <deque>

using namespace std;

#define INF 1000000


int target[200][200];
int outlet[200][200];
int sumtar[200];
int sumout[200];
set<int> canflip;

void inpout(int x, int L)
{
    string s;
    cin >> s;
    for(int i = 0; i < L; i ++)
    {
        outlet[x][i] = s[i]-'0';
        sumout[i] += outlet[x][i];
    }
}

void inptar(int x, int L)
{
    string s;
    cin >> s;
    for(int i = 0; i < L; i ++)
    {
        target[x][i] = s[i]-'0';
        sumtar[i] += target[x][i];
    }
}

bool check(int N, int L)
{
    string a[200], b[200];
    for(int i = 0; i < N; i ++)
    {
        a[i] = "";

        for(int j = 0; j < L; j ++)
        {
            stringstream ss;
            string s;
            ss << outlet[i][j];
            ss >> s;
            a[i] = a[i] + s;
        }
        b[i] = "";
        for(int j = 0; j < L; j ++)
        {
            stringstream ss;
            string s;
            ss << target[i][j];
            ss >> s;
            b[i] = b[i] + s;
        }
    }
    sort(a, a+N);
    sort(b, b+N);
    for(int i = 0; i < N; i ++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}

void flip(int x, int N)
{
    for(int i = 0; i < N; i ++)
        outlet[i][x] = 1-outlet[i][x];
    // if(x == 0)
    // {
    //     cout << "hah!\n";
    //     for(int i = 0; i < N; i ++)
    //     {
    //         for(int j = 0; j < 10; j ++)
    //             cout << outlet[i][j];
    //         cout << '\n';
    //     }
    // }
}

void printtarget(int N, int L)
{
    for(int i = 0; i < L; i ++)
        cout << sumtar[i] << ' ';
    cout << '\n';
    for(int i = 0; i < L; i ++)
        cout << sumout[i] << ' ';
    cout << '\n';
}
int func(int n, int N, int L)
{
    if(n == -1)
    {
        if(check(N, L))
            return 0;
        else
            return INF;
    }
    set<int>::iterator it;
    it = canflip.find(n);
    // if(n == 3)
//         cout << "??\n";
    if(it == canflip.end())
        return func(n-1, N, L);
    int res = func(n-1, N, L);
    flip(n, N);
    int temp = func(n-1, N, L)+1;
    flip(n, N);
    // if(n == 3)
//         cout << "n = " << n << " temp = " << temp << " res = " << res << '\n';
    if(temp < res)
        res = temp;
    return res;
}
int main()
{
    int t;
    scanf("%d", &t);

    for(int CASE = 1; CASE <= t; CASE ++)
    {
        int N, L;
        scanf("%d %d", &N, &L);
        for(int i = 0; i < L; i ++)
            sumtar[i] = sumout[i] = 0;
        for(int i = 0; i < N; i ++)
            inpout(i, L);
        for(int i = 0; i < N; i ++)
            inptar(i, L);
                    
        int res = 0;
        bool flag = false;
        for(int i = 0; i < L; i ++)
        {
            if(sumtar[i] != sumout[i] && sumtar[i]+sumout[i] != N)
            {
                // cout << "i = " << i << " " << sumtar[i] << " " << sumout[i] << '\n';
                flag = true;
                break;
            }
            if(sumtar[i] == sumout[i] && sumtar[i]+sumout[i] == N)
            {
                canflip.insert(i);
            }
            else if(sumtar[i] != sumout[i])
            {
                for(int j = 0; j < N; j ++)
                    outlet[j][i] = 1-outlet[j][i];
                res ++;
            }
        }
        // set<int>::iterator it;
//         for (it=canflip.begin(); it!=canflip.end(); ++it)
//             std::cout << ' ' << *it;
//         cout << '\n';
//         cout << res << '\n';
        if(flag)
        {
            printf("Case #%d: NOT POSSIBLE\n", CASE);
            continue;
        }
        int temp = func(L-1, N, L);
        res += temp;
        if(temp < INF)
            flag = true;
        if(flag)
            printf("Case #%d: %d\n", CASE, res);
        else
            printf("Case #%d: NOT POSSIBLE\n", CASE);
    }
    return 0;
}
