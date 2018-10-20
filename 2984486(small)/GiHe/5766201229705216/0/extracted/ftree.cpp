#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#define inf 10000000

using namespace std;

struct node
{
    int nxt, y;
};

node edge[2555];
int st[1222], hei[1222], sz[1222];
int edgetot;
bool h[1222];

void build(int x, int y)
{
    edgetot++;
    edge[edgetot].nxt = st[x];
    edge[edgetot].y = y;
    st[x] = edgetot;
}

int maxh;
bool pp;
int f[1222];

void dfs(int x, int height)
{
    h[x] = false;
    hei[x] = height;
    sz[x] = 1;
    int t = st[x], sons = 0;
    while (t) {
        if (h[edge[t].y]) {
                dfs(edge[t].y, height+1);
                sz[x] += sz[edge[t].y];
                sons++;
        }
        t = edge[t].nxt;
    }
    if (sons > 2) {pp = false; return;}
    if (sons < 2) if (hei[x] < maxh) maxh = hei[x];
}

int sum, n;

void calc(int x)
{
    h[x] = false;
    //if (hei[x] > maxh) {sum += sz[x];return;}
    f[x] = sz[x] - 1;
    int dele = 0;
    int t = st[x];
    int min1 = inf;
    int min2 = inf;
    int p1 = 0, p2 = 0, yy;
    //printf("---\n");
    while (t) {
        if (h[edge[t].y]) {
           calc(edge[t].y);
           yy = edge[t].y;
           if (f[yy] < min1) {
                //printf("---\n");
                dele += sz[p2];
                min2 = min1;p2 = p1;
                min1 = f[yy];p1 = yy;
           }
           else if (f[yy] < min2) {
                dele += sz[p2];
                min2 = f[yy];p2 = yy;
           }
        }
        t = edge[t].nxt;
    }
    if ((min1 == inf) || (min2 == inf)) f[x] = (sz[x] - 1);
    else f[x] = dele + min1 + min2;
    //cout << f[x] << endl;
}

int ans;

int main()
{
    freopen("ftree.in","r", stdin);
    freopen("ftree.out","w",stdout);
    int testcase;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++) {
        scanf("%d", &n);

        memset(st, 0, sizeof st);
        memset(edge, 0, sizeof edge);
        edgetot = 0;
        int x, y;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            build(x, y);
            build(y, x);
        }

        ans = n -1;
        for (int i = 1; i <= n; i++) {
            memset(h, true, sizeof h);
            memset(sz, 0, sizeof sz);
            dfs(i, 1);
            memset(h, true, sizeof h);
            //printf("--\n");
            //sum = 0;
            calc(i);
            if (f[i] < ans) {
                ans = f[i];
                //printf("##%d %d\n", sum, i);
                //for (int j = 1; j <= n; j++) cout << hei[j] << endl;
            }
        }

        printf("Case #%d: %d\n", test, ans);
    }
    return 0;
}
