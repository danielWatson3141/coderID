#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <tuple>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define REPP(i,s,e) for(int i=s; i<=e; i++)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a,b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a,b,c) cerr << (a) << ", " << (b) << ", " << (c) << endl

typedef long long lint;
typedef pair<lint,lint> pll;
typedef tuple<int,int,int> node;

int N;
int cnt[1011];
vector<int> G[1011];

const int INF = 1 << 20;

int dfs(int cur, int pre) {
    if(pre >= 0 && G[cur].size() == 1) return 0;

    int tot = 0;
    REP(i,G[cur].size()) {
        int to = G[cur][i];
        if(to != pre) {
            tot += dfs(to, cur) + 1;
        }
    }
    cnt[cur] = tot;
    return tot;
}

int dfs2(int cur, int pre) {
    if(pre >= 0 && G[cur].size() == 1) return 0;

    vector<node> num;
    REP(i,G[cur].size()) {
        int to = G[cur][i];
        if(to != pre) {
            int en = dfs2(to, cur);
            num.push_back(make_tuple(en - (cnt[to]+1), en, to));
        }
    }
    sort(ALL(num));

    int tot = INF;
    if(num.size() == 1) {
        tot = cnt[get<2>(num[0])] + 1;
    } else {
        tot = 0;
        REP(i,2) {
            tot += get<1>(num[i]);
        }

        REPP(i,2,num.size()-1) {
            tot += cnt[get<2>(num[i])] + 1;
        }
    }
    return tot;
}

int remove_count(int rt) {
    memset(cnt, 0, sizeof(cnt));
    dfs(rt, -1);
    return dfs2(rt, -1);
}

void solve() {
    int ans = INF;
    REP(i,N) {
        int res = remove_count(i);
        ans = min(ans, res);
    }
    printf("%d\n", ans);
}

void clear_graph() {
    REP(i,1011) G[i].clear();
}

void coding() {
    int T, x, y;
    cin>>T;
    REPP(t,1,T) {
        clear_graph();

        cin>>N;
        REP(i,N-1) {
            cin >> x >> y;
            x--; y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        printf("Case #%d: ", t);
        solve();
    }
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("b.in", "r", stdin);
#endif

	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}
