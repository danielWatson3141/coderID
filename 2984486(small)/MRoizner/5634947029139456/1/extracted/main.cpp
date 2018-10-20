#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <stack>
#include <assert.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cout << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;


const double INF = 1000000;
const double EPS = 1E-6;

typedef pair<pair<int, int>, pair<int, int> > Rect;

int64 frombin(string& s, int l) {
    int64 res = 0;
    for (int i = 0; i < l; ++i) {
        res *= 2;
        res += s[i] == '1';
    }
    return res;
}

int mymin(int a, int b) {
    return a == -1 ? b : b == -1 ? a : min(a, b);
}

int myplus(int a, int b) {
    return a == -1 || b == -1 ? -1 : a + b;
}

int64 withmask(int64 n, int masklen, int l) {
    return n & (((1LL << l) - 1) - ((1LL << (l - masklen)) - 1));
}

bool check(vector<int64>& inits, vector<int64>& req, int masklen, int l) {
    int n = inits.size();
    for (int i = 0; i < n; ++i) {
        if (withmask(inits[i], masklen, l) != withmask(req[i], masklen, l))
            return false;
    }
    return true;
}

int calc(vector<int64>& init, vector<int64>& req, int masklen, int l) {
    if (masklen == l) return 0;
    int res = -1;
    int n = init.size();

    if (check(init, req, masklen + 1, l)) {
        // cout << "Masklen = " << masklen << ", prime" << endl;
        res = mymin(res, calc(init, req, masklen + 1, l));
    }

    int64 flip = 1LL << (l - masklen - 1);
    for (int i = 0; i < n; ++i)
        init[i] ^= flip;
    sort(init.begin(), init.end());

    if (check(init, req, masklen + 1, l)) {
        // cout << "Masklen = " << masklen << ", inverse" << endl;
        res = mymin(res, myplus(calc(init, req, masklen + 1, l), 1));
    }

    for (int i = 0; i < n; ++i)
        init[i] ^= flip;
    sort(init.begin(), init.end());

    // debug(res);
    return res;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;

    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        int n, l;
        cin >> n >> l;
        vector<int64> inits(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            inits[i] = frombin(s, l);
        }
        vector<int64> req(n);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            req[i] = frombin(s, l);
        }
        sort(req.begin(), req.end());
        sort(inits.begin(), inits.end());

        int res = calc(inits, req, 0, l);
        if (res == -1)
            cout << "Case #" << testNumber << ": " << "NOT POSSIBLE" << endl;
        else
            cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
