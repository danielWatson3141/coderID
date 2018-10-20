#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime> 
using namespace std;
template<class T> inline void checkmin(T &a, T b){ if (b<a) a = b; }//NOTES:checkmin( 
template<class T> inline void checkmax(T &a, T b){ if (b>a) a = b; }//NOTES:checkmax( 
#define SIZE(x) ((int)(x).size()) 
#define for0(i,n) for(int i=0;i<(n);i++) 
#define for1(i,n) for(int i=1;i<=(n);i++) 
#define for0r(i,n) for(int i=(n)-1;i>=0;i--) 
#define for1r(i,n) for(int i=(n);i>=1;i--) 
typedef long long ll;

int N;
vector<int> E[2000];
bool visited[2000];

int cc(int x)
{
    visited[x] = true;
    int c = 1;
    for (int y : E[x])
    {
        if (!visited[y])c += cc(y);
    }
    visited[x] = false;
    //printf("\nc:%d %d\n", x, c);
    return c;
}

int dfs(int x)
{
    visited[x] = true;
    int c = 0;
    int last;
    for (int y : E[x])
    {
        if (!visited[y])
        {
            c++;
            last = y;
        }
    }
    if (c == 0)return 0;
    if (c == 1)return cc(last);
    int ans = 0;
    vector<int> t;
    for (int y : E[x])
    {
        if (!visited[y])
        {
            int g = cc(y);
            ans += g;
            int d = dfs(y);
            t.push_back(d - g);
        }
    }
    sort(t.begin(), t.end());
    ans += t[0] + t[1];
    return ans;
}

void solve()
{
    scanf("%d", &N);
    for0(i, N) E[i].clear();
    for0(i, N - 1)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    int ans = N + 1;
    for0(i, N)
    {
        memset(visited, 0, sizeof(visited));
        int t = dfs(i);
        checkmin(ans, t);
    }
    printf("%d\n", ans);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case #%d: ", TC);
        solve();
    }
    return 0;
}
