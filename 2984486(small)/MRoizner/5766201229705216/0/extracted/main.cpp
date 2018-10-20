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

int getmaxsize(vector<vector<int> >& graph, int u, vector<bool>& used) {
    used[u] = true;
    int n = graph.size();

    int childcount = 0;
    int maxsize1 = 0;
    int maxsize2 = 0;

    for (int i = 0; i < graph[u].size(); ++i) {
        int v = graph[u][i];
        if (used[v]) continue;

        childcount++;
        int size = getmaxsize(graph, v, used);
        if (size > maxsize1) {
            maxsize2 = maxsize1;
            maxsize1 = size;
        } else if (size > maxsize2) {
            maxsize2 = size;
        }
    }

    return childcount < 2 ? 1 : 1 + maxsize1 + maxsize2;
}

int getmaxsize(vector<vector<int> >& graph, int root) {
    int n = graph.size();
    vector<bool> used(n);
    return getmaxsize(graph, root, used);
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;

    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
        int n;
        cin >> n;
        vector<vector<int> > graph(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int maxsize = 1;
        for (int i = 0; i < n; ++i) {
            maxsize = max(maxsize, getmaxsize(graph, i));
        }

        int res = n - maxsize;
        cout << "Case #" << testNumber << ": " << res << endl;
    }

    return 0;
}
