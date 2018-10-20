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
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
    int higher_than_diagonal = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] >= i)
            higher_than_diagonal++;
    puts(higher_than_diagonal <= (1<<9) ? "GOOD" : "BAD");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("C-small-attempt0.in", "r", stdin);
    //freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w+", stdout);
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
