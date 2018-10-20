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

vector <int> gen1(int n) {
    vector <int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = i;
        int v = ((long long)rand() * RAND_MAX + rand()) % (i + 1);
        swap(res[i], res[v]);
    }
    return res;
}

vector <int> gen2(int n) {
    vector <int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        int v = rand() % n;
        swap(res[i], res[v]);
    }
    return res;
}

vector <int> calcCycles(vector <int> p) {
    int n = p.size();
    vector <char> used(n);
    vector <int> cycles;
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        int d = 0;
        int cur = i;
        do {
            ++d;
            used[cur] = 1;
            cur = p[cur];
        } while (cur != i);
        cycles.push_back(d);
    }
    sort(cycles.begin(), cycles.end());
    return cycles;
}

void print(vector <int> a) {
    for (int v : a) {
        cout << v << " ";
    }
}

long long delta(vector <int> a) {
    int n = a.size();
    long long res = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        res += a[i] * (n / 2 - abs(i - n / 2));
    }
    return res;
}

long double delta2(vector <int> a) {
    int n = a.size();
    long double res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) continue;
        if (a[i] < i) {
            res += pow(i - a[i], 0.9);
        } else {
            res -= pow(a[i] - i, 0.9);
        }
        //res += (long long)(i - a[i]) * (i - a[i]) * (i - a[i]) * (i - a[i]) * (i - a[i]);
    }
    return res;
}

long double delta3(vector <int> a) {
    int n = a.size();
    long double res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == i) continue;
        if (a[i] < i) {
            res += pow(i - a[i], 1.1);
        } else {
            res -= pow(a[i] - i, 1.1);
        }
        //res += (long long)(i - a[i]) * (i - a[i]) * (i - a[i]) * (i - a[i]) * (i - a[i]);
    }
    return -res;
}

vector <int> read(int n) {
    vector <int> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }
    return res;
}

void Solution::solveOneTestCase() {
    int n;
    cin >> n;
    //int n = 1000;
    vector <int> a = read(n);

    long double delt1 = delta2(a);
    long double delt2 = delta3(a);
    int cnt = 0;

    for (int i = 0; i < 100; ++i) {
        vector <int> z = gen1(n);
        long double val1 = delta2(z);
        long double val2 = delta3(z);
        if (val1 < delt1 && val2 < delt2) {
            ++cnt;
        }
    }

    if (cnt < 12) {
        puts("BAD");
    } else {
        puts("GOOD");
    }
}

int main()
{
    srand(time(0));
    Solution solution("C-small");
    solution.solveAllTestCases();
    return 0;
}
