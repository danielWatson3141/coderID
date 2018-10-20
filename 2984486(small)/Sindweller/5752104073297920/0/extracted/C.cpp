/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: C.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-04-26
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,s,t) for (LL i = (s); i <= (t); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;
typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

int a[1000];
double pro[1000][1000];

int rand(int l, int r)
{
        return l + rand() % (r - l + 1);
}

int main()
{
        int n = 1000, T = 1000000, cas = 0;
        double pp = 1.0 / T;
        while (T--) {
                REP(i,n) a[i] = i;
                REP(i,n) {
                        int p = rand(0, n - 1);
                        swap(a[i], a[p]);
                }
                REP(i,n) pro[a[i]][i] += pp;
        }
        scanf("%d", &T);
        //T = 120;
        while (T--) {
                scanf("%d", &n);
                REP(i,n) scanf("%d", &a[i]);
                //REP(i,n) a[i] = i;
                //REP(i,n) {
                //        int p = rand(0, n - 1);
                //        swap(a[i], a[p]);
                //}
                double res = 0;
                REP(i,n) res += pro[a[i]][i];
                printf("Case #%d: %s\n", ++cas, res - 1 > 0.005? "BAD": "GOOD");
        }

        return 0;
}
