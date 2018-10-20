#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

void solve_testcase()
{
    int n, l;
    scanf("%d%d", &n, &l);
    char initial[n][l+5];
    for (int i = 0; i < n; ++i)
        scanf("%s", &initial[i]);
    char required[n][l+5];
    for (int i = 0; i < n; ++i)
        scanf("%s", &required[i]);


    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int delta_size = 0;
        bool delta[l];
        for (int bit = 0; bit < l; ++bit)
            delta[bit]  = initial[i][bit] != required[0][bit],
            delta_size += initial[i][bit] != required[0][bit];
        if (ans != -1 && delta_size >= ans) continue;

        vector<string> s1;
        for (int j = 0; j < n; ++j) {
            string str1;
            for (int bit = 0; bit < l; ++bit)
                str1.push_back(required[j][bit] - '0');
            s1.push_back(str1);
        }

        vector<string> s2;
        for (int j = 0; j < n; ++j) {
            string str2;
            for (int bit = 0; bit < l; ++bit)
                str2.push_back(delta[bit] ? 1 - (initial [j][bit] - '0') : (initial [j][bit] - '0'));
            s2.push_back(str2);
        }

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if (s1 == s2) {
            ans = delta_size;
        }
    }

    if (ans == -1) {
        puts("NOT POSSIBLE");
    } else {
        printf("%d\n", ans);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w+", stdout);
    #endif

    int testcases_count;
    scanf("%d", &testcases_count);
    for (int testcase = 1; testcase <= testcases_count; ++testcase) {
        printf("Case #%d:", testcase);
        putchar(' ');
        //putchar('\n');
        solve_testcase();
    }
}
