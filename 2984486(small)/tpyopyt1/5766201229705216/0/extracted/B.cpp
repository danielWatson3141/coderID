#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 10000;
int n, bs, ans;
int di[MAXN], bj[MAXN], bi[MAXN], f[MAXN];

void add(int x, int y)
{
     bj[++bs] = y; bi[bs] = di[x]; di[x] = bs;
}

void dfs(int x, int fa)
{
     int i, y, x1, x2;
     x1 = 0; x2 = 0;
     for (i = di[x]; i != 0; i = bi[i]){
         y = bj[i];
         if (y == fa) continue;
         dfs(y, x);
         if (f[y] > f[x1]){
            x2 = x1; x1 = y;
         }
         else if (f[y] > f[x2])
              x2 = y;
     }
     if (x1 != 0 && x2 != 0)
        f[x] = 1 + f[x1] + f[x2];
     else f[x] = 1;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    
    int ks, ts, i, j, x, y;
    cin >> ts;
    for (ks = 0; ks < ts; ks++){
        cin >> n;
        bs = 1;
        for (i = 0; i <= n ; i++) di[i] = 0;
        for (i = 0; i < n - 1; i++){
            cin >> x >> y;
            add(x, y); add(y, x);
        }
        ans = n;
        for (i = 1; i <= n; i++){
            for (j = 0; j <= n; j++) f[j] = 0;
            dfs(i, 0);
            if (ans > n - f[i])
               ans = n - f[i];
        }
        printf("Case #%d: %d\n", ks + 1, ans);
    }
    return 0;
}
