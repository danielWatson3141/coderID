/*
ID: Labib Rashid
LANG: C++
TASK: Codejam R1A 2014, Task - Charging Chaos
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

#define LL long long
#define PB push_back
#define X first
#define Y second
#define INF 1000000007
#define PI 2*asin(1)
#define PII pair<int,int>
#define VI vector <int>
#define EPS 1e-9

using namespace std;

int gcd (int a, int b)
{
    if (b > a) return gcd (b,a);
    return (b == 0) ? a : gcd (b, a%b);
}

int bitcount (int a)
{
    return (a != 0) ? bitcount(a & (a-1)) + 1 : 0;
}

vector <string> M;
set <string> S, C;
set <string> ::iterator it1, it2;
bool V[50];

int main()
{
    //freopen ("1Charging Chaos.txt","r",stdin);
    freopen ("A-large.in","r",stdin);
    freopen ("A-large.txt","w",stdout);

    int T, tc = 0, i, j, k, N, L, ans;
    string s;

    cin >> T;
    while (tc < T) {
        tc++;
        ans = INF;
        M.clear();
        S.clear();

        cin >> N >> L;

        for (i = 0; i < N; i++) {
            cin >> s;
            M.PB (s);
        }
        for (i = 0; i < N; i++) {
            cin >> s;
            S.insert(s);
        }

        it1 = S.begin();
        s = *it1;
        for (i = 0; i < N; i++) {
            int cnt = 0;
            for (j = 0; j < L; j++) {
                V[j] = (s[j] == M[i][j]) ? 0 : 1;
                cnt += (s[j] == M[i][j]) ? 0 : 1;
            }
            if (cnt >= ans) continue;
            string s2;
            C.clear();
            for (j = 0; j < N; j++) {
                s2 = M[j];
                for (k = 0; k < L; k++) {
                    if (!V[k]) continue;
                    s2[k] = (s2[k] == '0') ? '1' : '0';
                }
                C.insert(s2);
            }
            it1 = S.begin(), it2 = C.begin();
            for (; it1 != S.end(); it1++, it2++)
                if (*it1 != *it2) break;

            if (it1 == S.end()) ans = min (ans, cnt);
        }

        if (ans == INF) {
            printf ("Case #%d: NOT POSSIBLE\n", tc);
        }
        else printf ("Case #%d: %d\n", tc, ans);
    }


    return 0;
}
