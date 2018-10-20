#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define REP(i,n)   FOR(i,0,n)
#define ALL(x) (x).begin(), (x).end()
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back
#define ITER(v)      __typeof((v).begin())
#define FOREACH(i,v) for(ITER(v) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
#define x first
#define y second

char a[1000][1000], b[1000][1000];
int n, l;

void flip(int lv) {
    //printf("FLIP %d\n", lv);
    FOR(i, 0, n) {
        a[i][lv] = '0' + (1 - (a[i][lv] - '0'));
    }
}

void gao(int lv, int current, int &best) {
    if (current >= best)
        return;

    multiset<string> sa, sb;
    FOR(i, 0, n) sa.insert(string(a[i], lv));
    FOR(i, 0, n) sb.insert(string(b[i], lv));

    /*
    printf("...\n");
    FOREACH(it, sa) printf("%s ", it->c_str()); puts("");
    FOREACH(it, sb) printf("%s ", it->c_str()); puts("");
    printf("? %d\n", sa == sb);
    */

    if (sa != sb)
        return;

    if (lv == l) {
        best = current;
        return;
    }

    gao(lv + 1, current, best);

    flip(lv);
    gao(lv + 1, current + 1, best);
    flip(lv);
}

int main() {
    int T; scanf("%d", &T); FOE(ca, 1, T) {
        scanf("%d%d", &n, &l);
        FOR(i, 0, n) scanf("%s", a[i]);
        FOR(i, 0, n) scanf("%s", b[i]);

        int best = l + 1;
        gao(0, 0, best);

        printf("Case #%d: ", ca);
        if (best == l + 1)
            puts("NOT POSSIBLE");
        else
            printf("%d\n", best);
    }
    return 0;
}
