#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define in freopen("B-small-attempt2.in", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 30010
/*************************************************HABIJABI ENDS HERE******************************************************/

int mask, n, color[16], flag;
vector <int> adj[16];

void dfs(int node)
{
    color[node] = 1;
    int called = 0;
    for(int i = 0; i < SZ(adj[node]); i++)
    {
        if((mask & (1 << adj[node][i])) && !color[adj[node][i]])
            called++, dfs(adj[node][i]);
    }
    if(!(called == 0 || called == 2)) flag = false;
}

int main()
{
    in;
    out;
    int test, i, j, kase = 1, a, b, k;
    cin >> test;
    while(test--)
    {
        int mn = infinity;
        cin >> n;
        for(i = 0; i < n; i++)
            adj[i].clear();

        for(i = 1; i < n; i++)
        {
            cin >> a >> b;
            a--,b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        for(mask = 0; mask < (1 << n); mask++)
        {
            flag = 1;
            for(i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    clr(color, 0);
                    dfs(i);
                    break;
                }
            }
            int cnt = 0;
            for(i = 0; i < n; i++)
                cnt += color[i];
            if(flag && cnt == no_of_ones(mask))
                mn = min(mn, n - no_of_ones(mask));
        }
        printf("Case #%d: %d\n", kase++, mn);
    }
    return 0;
}
