#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

ll itob(string b){
	ll a=0;
	int n=b.size();
	rep(i,n){
		if(b[i]=='1')
			a|=(1<<(n-1-i));
	}
	//dump(a)
	return a;
}

int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		int n,l;
		cin >> n >> l;
		ll a[160];
		ll b[160];
		rep(i,n){
			string tmp;
			cin >> tmp;
			a[i]=itob(tmp);
		}
		rep(i,n){
			string tmp;
			cin >> tmp;
			b[i]=itob(tmp);
		}
		int ans=inf;
		bool ok=false;
		rep(i,1<<l){
			ll tmp[160];
			rep(j,n) tmp[j]=a[j];
			rep(j,n){
				// dump(tmp[j])
				 tmp[j]^=i;
				// dump(tmp[j])
			}
			bool check=true;
			sort(tmp,tmp+n);
			sort(b,b+n);
			rep(j,n){
				if(tmp[j]!=b[j])
					check=false;
			}
		//	dump(i)
			if(check){
				ok=true;
				ans=min(ans, __builtin_popcount(i));
			}
		}

		cout << "Case #" << loop+1 << ": " ;
		if(ok)
			cout << ans << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}