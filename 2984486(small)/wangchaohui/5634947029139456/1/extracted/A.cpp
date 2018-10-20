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
typedef vector<int> vi;

string sws[200];
string devices[200];
int N, L;

void split(int l, string *s, const vector<int> &d, vector<int> &d0, vector<int> &d1)
{
    for (int a : d)
    {
        if (s[a][l] == '0')d0.push_back(a);
        else d1.push_back(a);
    }
}

int dfs(int l, vector<pair<vi, vi>> sd)
{
    if (l == L)
    {
        return 0;
    }
    int n = sd.size();
    vector<vi> s0(n), s1(n);
    vector<vi> d0(n), d1(n);
    for0(i, n)
    {
        split(l, sws, sd[i].first, s0[i], s1[i]);
        split(l, devices, sd[i].second, d0[i], d1[i]);
    }
    int ans = L + 1;
    bool flag = true;
    vector<pair<vi, vi>> t;
    for0(i, n)
    {
        if (s0[i].size() != d0[i].size())flag = false;
        if (s0[i].size() > 0) t.push_back({ s0[i], d0[i] });
        if (s1[i].size() > 0) t.push_back({ s1[i], d1[i] });
    }
    if (flag)checkmin(ans, dfs(l + 1, t));
    flag = true;
    t.clear();
    for0(i, n)
    {
        if (s0[i].size() != d1[i].size())flag = false;
        if (s0[i].size() > 0) t.push_back({ s0[i], d1[i] });
        if (s1[i].size() > 0) t.push_back({ s1[i], d0[i] });
    }
    if (flag)checkmin(ans, dfs(l + 1, t) + 1);
    return ans;
}

void solve()
{
    scanf("%d %d", &N, &L);
    static char c[200];
    for0(i, N){ scanf("%s", c); sws[i] = c; }
    for0(i, N){ scanf("%s", c); devices[i] = c; }
    vector<int> s, d;
    for0(i, N)
    {
        s.push_back(i);
        d.push_back(i);
    }
    int ans = dfs(0, { { s, d } });
    if (ans >= L + 1)puts("NOT POSSIBLE");
    else
    {
        printf("%d\n", ans);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, TC = 0;
    scanf("%d", &T);
    while (++TC <= T)
    {
        printf("Case #%d: ", TC);
        solve();
    }
    return 0;
}
