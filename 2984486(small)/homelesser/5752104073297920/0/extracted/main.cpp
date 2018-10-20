#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
const int maxn = 1005;
int n;
int a[maxn];

int main() {
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (a[j] > a[i]) cnt++;
        //cout << cnt << endl;
        if (cnt * 4 < n * (n - 1)) printf("Case #%d: BAD\n", cas);
        else printf("Case #%d: GOOD\n", cas);


    }
    return 0;
}