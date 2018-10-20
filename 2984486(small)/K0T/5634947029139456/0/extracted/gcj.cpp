#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <cstring>
#include <ext/rope>
#include <iterator>

using namespace std;
using namespace __gnu_cxx;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz size
#define scf scanf
#define prf printf
#define prev(x) (x/2)
#define left(x) (x*2)
#define right(x) (x*2+1)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define gcd(a,b) __gcd(a,b)
#define getBit(x,i) ((x&(1<<i))!=0 ? 1 : 0)
#define For(i,n) for (int i = 0; i < n; ++i)
#define FOR(i,begin,end,move) for (int i = begin; i <= end; i += move)

typedef long long ll;

const ll base = 1000000007LL;
const ll INF = 10000000000000LL;

int ans = 0;
int n, l;
string s1[101], s2[101], s3[101];
bool used[1001] = {false};

void dfs(int v, int cur)
{
    if (v == l)
    {
        For(i,n)
            s3[i] = s1[i];
        For(i,n)
            For(j,l)
                if (used[j])
                    if (s3[i][j] == '0')
                    s3[i][j] = '1';
                else s3[i][j] = '0';
        sort(s3, s3 + n);
        bool ok = true;
        For(i,n)
            if (s3[i] != s2[i])
            {
                ok = false;
                break;
            }
        if (ok)
            ans = min(ans, cur);
        return;
    }
    used[v] = true;
    dfs(v + 1, cur + 1);
    used[v] = false;
    dfs(v + 1, cur);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scf("%d", &t);
    For(q,t)
    {
        cin >> n >> l;
        For(i,n)
            cin >> s1[i];
        For(i,n)
            cin >> s2[i];
        sort(s2, s2 + n);
        ans = l + 2;
        fill(used, used + l + 2, false);
        dfs(0, 0);
        printf("Case #%d: ", q + 1);
        if (ans == l + 2)
            printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
