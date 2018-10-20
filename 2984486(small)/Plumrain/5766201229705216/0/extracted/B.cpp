/*
 * Author:  Plumrain
 * Created Time:  2014/4/26 10:25:36
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>

using namespace std;

#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define INF 999999999999999999
#define zero(x) (((x)>0?(x):-(x))<eps)
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
#define CINBEQUICKER std::ios::sync_with_stdio(false)

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;

const double eps = 1e-10;
const double PI = atan(1.0)*4;
const int inf = 2147483647 / 2;

template <class T> void chmin(T &t,T x){if (x < t) t = x;}
template <class T> void chmax(T &t,T x){if (x > t) t = x;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}

vi son[1005];

int dfs (int x, int fa){
    int t1 = 0, t2 = 0;
    repf (i, 0, sz(son[x])-1) if (fa != son[x][i]){
        int tmp = dfs (son[x][i], x);
        if (tmp > t1) t2 = t1, t1 = tmp;
        else if (tmp > t2) t2 = tmp;
    }
    if (t2 == 0) return 1;
    return 1 + t1 + t2;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b.out","w",stdout);
//    std::ios::sync_with_stdio(false);
    int T, cas = 0;
    scanf ("%d", &T);
    while (T--){
        int n;
        scanf ("%d", &n);
        repf (i, 0, n-1) son[i].clear();
        int t1, t2;
        repf (i, 0, n-2){
            scanf ("%d%d", &t1, &t2); -- t1; -- t2;
            son[t1].pb (t2); son[t2].pb (t1);
        }
        
        int ans = inf;
        repf (i, 0, n-1) chmin (ans, n - dfs (i, -1));
        printf ("Case #%d: %d\n", ++ cas, ans);
    }
    return 0;
}
