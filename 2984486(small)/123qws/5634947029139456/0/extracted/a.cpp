#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;

#define DB(x) cerr<<#x<<"="<<x<<" "
#define DBN(x) cerr<<#x<<"="<<x<<"\n"
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define INF 1000000000
#define EPS (double)1e-9
#define MOD 1000000007
#define PI 3.14159265358979328462
int bitcount(int x) {
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}
int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
	int n, l;
	cin >> n >> l;
	string flow[100], require[100];
	for (int i = 0; i < n; i++)
	    cin >> flow[i];
	for (int i = 0; i < n; i++)
	    cin >> require[i];
	sort(require, require+n);
	int ans = INF;
	for (int i = 0; i < 1<<l; i++) {
	    for (int j = 0; j < l; j++)
		if (i & (1<<j)) {
		    for (int k = 0; k < n; k++)
			if (flow[k][j] == '1') flow[k][j] = '0';
			else flow[k][j] = '1';
		}

	    sort(flow, flow+n);
	    bool succ = true;
	    for (int j = 0; j < n; j++)
		if (flow[j] != require[j]) {
		    succ = false; break;
		}
	    if (succ) {
		ans = min(ans, bitcount(i));
	    }

	    for (int j = 0; j < l; j++)
		if (i & (1<<j)) {
		    for (int k = 0; k < n; k++)
			if (flow[k][j] == '1') flow[k][j] = '0';
			else flow[k][j] = '1';
		}
		    
	}
	cout << "Case #" << ca << ": ";
	if (ans == INF)
	    cout << "NOT POSSIBLE";
	else
	    cout << ans;
	cout << endl;
	
    }
    return 0;
}


