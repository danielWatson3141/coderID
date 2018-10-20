// {{{ Headers
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <cassert>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;
// }}}

typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }

int
main () {
#ifdef LOCALHOST
    freopen ("test.in", "r", stdin);
    // freopen ("test.out", "w", stdout);
#endif
    int T, N, L;
    char buff [100];
    scanf ("%d", &T);
    for (int t = 1; t <= T; t++) {
        int ret = INF;
        scanf ("%d %d", &N, &L);
        vector <string> u, v;
        for (int i = 0; i < N; i++) {
            scanf ("%s", buff);
            u.push_back (string (buff));
        }
        for (int i = 0; i < N; i++) {
            scanf ("%s", buff);
            v.push_back (string (buff));
        }
        sort (v.begin (), v.end ());
        for (int mask = 0; mask < (1 << L); mask++) {
            vector <string> w = u;
            for (int i = 0; i < L; i++)
                if (mask & 1 << i)
                    for (int j = 0; j < N; j++) w [j][i] = (w [j][i] == '0' ? '1' : '0');
            sort (w.begin (), w.end ());
            if (w == v) ret = min (ret, __builtin_popcount (mask));
        }
        if (ret >= INF) printf ("Case #%d: NOT POSSIBLE\n", t);
        else printf ("Case #%d: %d\n", t, ret);
    }

    return 0;
}

