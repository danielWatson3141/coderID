#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;
const int P = 1000000007;

int n;
vector<vector<int> > gg;
vector<vector<int> > g;

void hang(int v, int pv=-1) {
    REP(i,gg[v].size()) {
        if (gg[v][i] != pv) {
            g[v].push_back(gg[v][i]);
            hang(gg[v][i], v);
        }
    }
}

int fun(int v) {
    if (g[v].size() < 2) {return 1;}
    vector<int> ch;
    REP(i,g[v].size()) ch.push_back(fun(g[v][i]));
    sort(ch.begin(), ch.end());
    reverse(ch.begin(), ch.end());
    return 1 + ch[0] + ch[1];
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    REP(ic,tc) {
        cin >> n;
        gg.assign(n, vector<int>());
        int a, b;
        REP(i,n-1) {
            cin >> a >> b;
            gg[a-1].push_back(b-1);
            gg[b-1].push_back(a-1);
        }
        int ans = 0;
        REP(i,n) {
            g.assign(n, vector<int>());
            hang(i);
            ans = max<int>(ans, fun(i));
        }
        cout << "Case #" << ic+1 << ": " << n-ans << endl;
    }

	return 0;
};