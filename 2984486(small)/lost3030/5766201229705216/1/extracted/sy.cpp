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

const int N = 1e3+ 111;
const int M=20005 ;
struct edge {
     int next ,v;
}e[ M];
int head[ N],tot ;
void init (){
     zero (head);
     tot =1;
}
inline void add(int u ,int v ){
     e [tot]. v=v ;
     e [tot]. next=head [u];
     head [u]= tot++;
}

int n;

PII dfs(int x,int pa) {

	int i;
	int num = 0;

	int z1 = -1,z2 = -1;

	for(i = head[x];i;i = e[i].next) {
		int v = e[i].v;

		if (v != pa) {
			PII tp = dfs(v,x);
			num += tp.second;
			int res = tp.second - tp.first;
			if (res >= z1) {
				z2 = z1;
				z1 = res;
			}
			else if (res > z2) {
				z2 = res;
			}
		}
	}
	if (z1 == -1) {
		return MP(0,1);
	}
	if ( z2 == -1) {
		return MP(num,num+1);
	}
	return MP(num - z1 - z2,num+1);

}

void work() {
	init();
	cin>>n;
	int i,j;
	int a,b;



	rep(i,n-1) {
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}



	int ans = N;
	srep(i,n) {

		ans = min(dfs(i,0).first,ans);

	}
	cout<<ans<<endl;
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

