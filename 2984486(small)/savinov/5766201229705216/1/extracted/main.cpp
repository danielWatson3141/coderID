#include <bits/stdc++.h>
#include <ext/rope>
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))
using namespace std;
template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

class Solution {
public:
    Solution(string problemName) {
        freopen((problemName + ".in").c_str(), "r", stdin);
        freopen((problemName + ".out").c_str(), "w", stdout);
    }

    void solveAllTestCases() {
        cin >> testNumber;
        for (int test = 1; test <= testNumber; ++test) {
            cout << "Case #" << test << ": ";
            solveOneTestCase();
        }
    }

private:
    int testNumber;
    void solveOneTestCase();
};

vector <vector <int> > g;

int dfs(int v, int p) {
    vector <int> sizes;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        sizes.push_back(dfs(to, v));
    }
    if (sizes.size() < 2) {
        return 1;
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    return 1 + sizes[0] + sizes[1];
}

void Solution::solveOneTestCase() {
    int n;
    cin >> n;
    g.assign(n, vector <int>());
    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        cin >> from >> to;
        --from, --to;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    int best = n;
    for (int i = 0; i < n; ++i) {
        best = min(best, n - dfs(i, i));
    }
    cout << best << endl;
}

int main()
{
    Solution solution("B-large");
    solution.solveAllTestCases();
    return 0;
}
