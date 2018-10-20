#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#define FOR(i,k,n) for(int i=k; i<n; i++)
#define EPS 1.0e-6
#define INF 10000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int a[1005];

int main()
{
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);

    int T;
    int n, dist;

    scanf("%d", &T);
    for(int ncase=1; ncase<=T; ncase++)
    {
        scanf("%d", &n); dist = 0;
        FOR(i,0,n) {scanf("%d", &a[i]); dist+=fabs(i-a[i]);}
        if (dist > 326927) printf("Case #%d: GOOD\n", ncase);
        else printf("Case #%d: BAD\n", ncase);
    }

    return 0;
}
