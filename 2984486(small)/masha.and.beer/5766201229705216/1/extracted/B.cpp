// A.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 1010

int best;
int n;
vector<int> v[MAXN];
int sum[MAXN][MAXN];

int csum(int x, int from) {
    if (sum[x][from] >=0) return sum[x][from];
    if (from == 0) return n;
    sum[x][from] = 1;
    for(int i=0; i<v[x].size(); ++i) if (v[x][i] != from) sum[x][from] += csum( v[x][i], x);
    return sum[x][from];
}

int rec(int x, int from) {
    int b[2];
    int tmp;
    b[0] = MAXN;
    b[1] = MAXN;
    for(int i=0; i<v[x].size(); ++i) {
        int y = v[x][i];
        if (y != from) {
            tmp = rec(y, x) - csum(y, x);
            if (tmp < b[0]) {
                b[1] = b[0];
                b[0] = tmp;
            } else if (tmp < b[1]) {
                b[1] = tmp;
            }
        }
    }
    //printf("csum %i from %i = %i\n", x, from, csum(x, from));
    tmp = csum(x, from) + b[0] + b[1] - 1;
    if (csum(x, from) - 1 < tmp) tmp = csum(x, from) - 1;
    return tmp;
}


int main(){
    int tc;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%i", &tc);
    for(int tt=1; tt<=tc; ++tt) {
        memset(sum, 0xFF, sizeof(sum));
        scanf("%i", &n);
        best = n - 1;
        for(int i=1; i<=n; ++i) {
            v[i].clear();
        }

        for(int i=0; i<n-1; ++i) {
            int x, y;
            scanf("%i %i", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i=1; i<=n; ++i) {
            int tmp = rec(i, 0);
            //printf("root %i gets %i\n", i, tmp);
            best = (tmp < best ? tmp : best);
        }
        printf("Case #%i: ", tt);
        printf("%i\n", best);
    }

    return 0;
}

