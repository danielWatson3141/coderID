#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int MAXN = 200;

long long a[MAXN], b[MAXN];
long long aa[MAXN], bb[MAXN];

long long decode (string s, int l) {
    long long ans = 0;
    for (int i = 0; i < l; ++i) {
        ans *= 2;
        ans += s[i] - '0';
    }
    return ans;
}

int main ()
{
//  ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; ++tc) {
        printf ("Case #%d: ", tc + 1);

        int n, l;
        cin >> n >> l;

        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            a[i] = decode(s, l);
        }

        for (int i = 0; i < n; ++i) {
            cin >> s;
            b[i] = decode(s, l);
        }

        int ans = l + 10;
        for (int i = 0; i < n; ++i) {
            long long mask = (a[0] ^ b[i]);
            int cur_ans = 0;
            for (int j = 0; j < l; ++j) {
                cur_ans += (mask >> j) & 1;
            }

            if (cur_ans < ans) {
                for (int j = 0; j < n; ++j) {
                    aa[j] = (a[j] ^ mask);
                    bb[j] = b[j];
                }
                sort (aa, aa + n);
                sort (bb, bb + n);

                bool key = true;
                for (int j = 0; j < n; ++j) {
                    if (aa[j] != bb[j]) {
                        key = false;
                        break;
                    }
                }

                if (key) {
                    ans = cur_ans;
                }
            }
        }

        if (ans > l) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }

	return 0;
}
