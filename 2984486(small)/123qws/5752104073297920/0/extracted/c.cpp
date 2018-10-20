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
int pos[1005], a[1005];
int get(int n) {
    for (int i = 0; i < n; i++)
	pos[a[i]] = i;
    int res = 0;
    for (int i = 0; i < n; i++) {
	res += (pos[i]-i>=0 && pos[i]-i <= 250);
	res -= (pos[i]-i<0 && i-pos[i] <= 250);
    }
    // cout << res << endl;
    return res;
}

int main(int argc, char *argv[])
{
    int T; cin >> T;
    for (int ca = 1; ca <= T; ca++) {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	    cin >> a[i];

	cout << "Case #" << ca << ": ";
	if (get(n) < -25)
	    cout << "BAD\n";
	else
	    cout << "GOOD\n";
    }
    return 0;
}

