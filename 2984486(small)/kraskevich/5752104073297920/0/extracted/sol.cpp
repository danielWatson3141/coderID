#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

vector<int> good(int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = i;
    for (int i = 0; i < n; i++)
    {
        int v = i + rand() % (n - i);
        swap(res[i], res[v]);
    }
    return res;
}

vector<int> bad(int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = i;
    for (int i = 0; i < n; i++)
    {
        int v = rand() % n;
        swap(res[i], res[v]);
    }
    return res;
}

int inv(vector<int> v)
{
    int n = v.size();
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])
                res++;
    return res;
}

vector<bool> u;
int len;

void dfs(vector<int> &v, int i)
{
    u[i] = true;
    int to = v[i];
    if (!u[to])
        dfs(v, to);
    len++;
}

long long f1(vector<int> v)
{
    int n = v.size();
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])
                res += v[i];
    return res;
}

long long f2(vector<int> v)
{
    int n = v.size();
    long long res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] > v[j])
                res += v[j];
    return res;
}

long long f3(vector<int> v)
{
    int n = v.size();
    int res = 0;
    u.assign(n, 0);
    vector<int> l;
    for (int i = 0; i < n; i++)
        if (v[i] <= i + 20)
            res++;
    return res;
}

const int INV = 235 * 1000;
const int LO1 = 225 * 1000;

const int F1 = 162 * 1000 * 1000;
const int LO2 = 158 * 1000 * 1000;

const int F2 = 81 * 1000 * 1000;
const int LO3 = 79 * 1000 * 1000;


bool good(vector<int> v)
{
    /*int f = inv(v);
    int cnt = 3;
    if (f < LO1)
        return false;
    if (f < INV)
        cnt--;

    f = f1(v);
    if (f < LO2)
        return false;
    if (f < F1)
        cnt--;

    f = f2(v);
    if (f < LO3)
        return false;
    if (f < F2)
        cnt--;
    return cnt == 3 || (cnt == 2 && (rand() & 1));*/
    return f3(v) >= 508;
}

void solve(int test)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cerr << test << endl;
    cout << "Case #" << test << ": ";
    cout << (good(v) ? "GOOD\n" : "BAD\n");
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(10);

    /*srand(134);

    int err1 = 0;
    vector<int> a;
    for (int i = 0; i < 60; i++)
    {
        vector<int> v = good(1000);
        a.push_back(f3(v));
        if (!good(v)) {
            err1++;
            //cout << "b" << " ";
        }
    }
    sort(a.begin(), a.end());
    for (int x : a)
        cout << x << " ";
    cout << endl;
    int err2 = 0;
    a.clear();
    for (int i = 0; i < 60; i++)
    {
        vector<int> v = bad(1000);
        a.push_back(f3(v));
        if (good(v))
            err2++;
    }
     sort(a.begin(), a.end());
    for (int x : a)
        cout << x << " ";
    cerr << err1 << " " << err2 << endl;*/

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    return 0;
}
