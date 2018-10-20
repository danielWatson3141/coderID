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

int N, L;
string pat[155];
string goal[155];
bool vis[155];

const int INF = 1<<20;

int check(string flip) {
    memset(vis, 0, sizeof(vis));

    vector<string> pp;
    REP(i,N) {
        pp.push_back(pat[i]);
        REP(j,L) {
            if(flip[j] == '1') {
                pp[i][j] = (pp[i][j] == '1') ? '0' : '1';
            }
        }
    }

    int suc = 0;
    REP(i,N) {
        REP(j,N) {
            if(!vis[j] && pp[i] == goal[j]) {
                vis[j] = true;
                suc++;
                break;
            }   
        }
    }

    if(suc != N) return -1;

    int ret = 0;
    REP(i,L) {
        if(flip[i] == '1') ret++;
    }
    return ret;
}

void validate() {
    int ans = INF;
    REP(mask,1<<L) {
        string flip = "";
        REP(i,L) {
            if((mask & (1<<i)) != 0) {
                flip += "1";
            } else {
                flip += "0";
            }
        }

        int res = check(flip);
        if(res != -1) {
            ans = min(res, ans);
        }
    }
    
    if(ans == INF) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", ans);
    }
}

void solve() {
    int ans = INF;
    REP(i,N) {
        string s = pat[i];
        string g = goal[0];
        string flip = "";
        REP(k,L) {
            if(s[k] == g[k]) flip += "0";
            else flip += "1";
        }
        int res = check(flip);
        if(res != -1) {
            ans = min(ans, res);
        }
    }

    if(ans == INF) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", ans);
    }
}

void coding() {
    int T;
    while(cin>>T) {
        REPP(t,1,T) {
            cin>>N>>L;
            REP(i,N) cin>>pat[i];
            REP(i,N) cin>>goal[i];
            printf("Case #%d: ", t);
            solve();
            //validate();
        }
    }
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("a.in", "r", stdin);
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
