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

const int MAXN = 1500;

vector <int> adj[MAXN];
int ans[MAXN];
bool used[MAXN];

int get_ans (int v) {
    used[v] = true;

    vector <int> ch_ans;
    for (int i = 0; i < adj[v].size(); ++i) {
        if (!used[adj[v][i]]) {
            get_ans(adj[v][i]);
            ch_ans.pb(ans[adj[v][i]]);
        }
    }

    if (ch_ans.size() < 2) {
        ans[v] = 1;
        return 0;
    }

    sort (ch_ans.rbegin(), ch_ans.rend());
    ans[v] = ch_ans[0] + ch_ans[1] + 1;
    return 0;
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

        int n;
        cin >> n;

        for (int i = 0; i < n - 1; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            v1--; v2--;
            adj[v1].pb(v2);
            adj[v2].pb(v1);
        }

        int max_tree = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                used[j] = false;
            }

            get_ans(i);

            /*for (int j = 0; j < n; ++j) {
                cerr << ans[j] << " ";
            }
            cerr << endl;*/

            max_tree = max(max_tree, ans[i]);
        }

        cout << n - max_tree << endl;

        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
    }


	return 0;
}
