#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <string.h>
#include <ctime>
#include <limits.h>
using namespace std;

typedef long long ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
//const ll INF=(_I64_MAX)/2;
//#pragma comment(linker, "/STACK:102400000,102400000")
const int inf = 0x3f3f3f3f;
#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a,b) memset(a, b, sizeof(a))
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define srep(i,n) for(i = 1;i <= n;i ++)
#define snuke(c,itr) for( __typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MP make_pair
#define fi first
#define se second
typedef pair<int, int> PII;

int n,l;

string a[2][12];

void work() {
	cin>>n>>l;
	int i,j;
	rep(i,2) {
		rep(j,n) cin>>a[i][j];
	}
	sort(a[1],a[1]+n);
	int end = 1<<l;
	int ans = 1234;
	rep(i,end) {
		string b[11];
		rep(j,n) b[j] = a[0][j];
		int zz = 0;
		rep(j,l) {
			if (i & (1<<j)) {
				zz ++;
				int r;
				rep(r,n) {
					if (b[r][j] == '0') b[r][j] = '1';
					else b[r][j] = '0';
				}
			}

		}
		sort(b,b+n);
		bool f = 1;
		rep(j,n) {
			if (b[j] != a[1][j]) f= 0;
		}
		if (f) ans = min(ans,zz);
	}
	if (ans == 1234) puts("NOT POSSIBLE");
	else cout<<ans<<endl;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	  freopen ("out.txt","w",stdout);
#endif

	int t;
	cin>>t;
	int cas = 1;
	while(t--) {
		printf("Case #%d: ",cas++);
		work();
	}



	return 0;
}

//10.15

