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

unsigned long long get(string a) {
    unsigned long long res = 0;
    for (int i = 0; i < (int)a.length(); ++i) {
        res = res * 2 + a[i] - '0';
    }
    return res;
}

void Solution::solveOneTestCase() {
    int n, k;
    cin >> n >> k;
    unsigned long long a[n];
    unsigned long long b[n];
    for (int i = 0; i < n; ++i) {
        string q;
        cin >> q;
        a[i] = get(q);
    }

    for (int i = 0; i < n; ++i) {
        string q;
        cin >> q;
        b[i] = get(q);
    }
    sort(b, b + n);

    long long best = ULLONG_MAX;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            unsigned long long aa[n];
            for (int k = 0; k < n; ++k) {
                aa[k] = a[k] ^ a[i] ^ b[j];
            }
            sort(aa, aa + n);
            if (!memcmp(aa, b, n * sizeof(long long))) {
                long long move = a[i] ^ b[j];
                if (__builtin_popcountll(move) < __builtin_popcountll(best)) {
                    best = move;
                }
            }
        }
    }

    if (best == ULLONG_MAX) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << __builtin_popcountll(best) << endl;
    }


}

int main()
{
    Solution solution("A-small");
    solution.solveAllTestCases();
    return 0;
}
