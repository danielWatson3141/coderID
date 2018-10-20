
/*Paresh Verma*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <cstring>
#include <queue>		//max heap implementation
#include <limits.h>

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mkp make_pair
#define fi first
#define se second
#define LL long long
#define fill(x,y) memset(x, y, sizeof(x))
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

typedef pair<int,int> pii;

vector< vector<int> > g;

int vis[10001];
pii calc(int in) {			//first edges of entire tree, second cost of keeping it
	vis[in] = 1;
	int i,j,k;
	int v[] = {INT_MIN, INT_MIN};
	int cost = 0;
	int siz = 0;
	for(i=0;i<g[in].size();i++) {
		if (!vis[g[in][i]]) {
		//	cout << "neigh " << g[in][i] << endl;
			pii nd = calc(g[in][i]);
			siz += nd.fi+1;
			nd.fi += 1;
			cost += nd.fi;
			int t = nd.fi - nd.se;
			if (t > v[0]) {
				v[1] = v[0];
				v[0] = t;
			} else if (t > v[1]) {
				v[1] = t;
			}
		}
	}
	//printf("%d %d\n", in, siz);
	int val;
	if (v[0] == INT_MIN) {
		val= 0;
	} else if (v[1] == INT_MIN) {
		val= cost;
	} else {
		val= cost -v[0]-v[1];
	}
	//cout << "val for " << in << " " << val << endl;
	return mkp(siz, val);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int p =1; p<=T; p++) {
		printf("Case #%d: ", p);
		int n;
		scanf("%d",&n);
		int i,j,k;
		g = vector< vector<int> > (n);
		for(i=0;i<n-1;i++) {
			scanf("%d%d",&j, &k);
			j--; k--;
			g[j].pub(k);
			g[k].pub(j);
		}
		int ans = INT_MAX;
		for (int i= 0; i< n ; i++) {
			memset(vis, 0, sizeof(vis));
			//cout << "root "<< i << endl;
			ans = min(ans, calc(i).se);
			//cout << "New ans " << ans << endl;
		}
		printf("%d\n", ans);

	}

	return 0;
}
