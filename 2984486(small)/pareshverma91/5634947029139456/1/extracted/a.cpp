
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

int sz (long long x) {
	int cnt = 0;
	for(int i = 0; i <  50; i++) {
		if (x & 1LL<<i)
			cnt++;
	}
	return cnt;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int p =1; p<=T; p++) {
		printf("Case #%d: ", p);
		int n,l;
		scanf("%d%d", &n, &l);
		int i,j,k;
		long long x,y;
		char s[l+2];
		vector<long long> num (n);
		for(i =0; i<n;i++) {
			scanf("%s",s);
			x=0;
			for(j=0;j<l;j++) {
				if(s[j] == '1')
					x |= 1LL<<j;
			}
			num[i]=x;
		}
		vector<long long> in (num.begin(), num.end());
		sort(in.begin(), in.end());
		vector<long long> sw (n);
		for(i =0; i<n;i++) {
			scanf("%s",s);
			x=0;
			for(j=0;j<l;j++) {
				if(s[j] == '1')
					x |= 1LL<<j;
			}
			sw[i]=x;
		}
		int ans = INT_MAX;
		for(i=0;i<n;i++) {  //match 0th device with ith switch
			long long mask = num[0] ^ sw[i];
			vector<long long> y (n);
			for(j=0;j<n;j++) {
				y[j] = (sw[j] ^ mask);
			}
			sort(y.begin(), y.end());
			if (in == y) {
				ans = min(ans, sz(mask));
			}
		}
		if (ans == INT_MAX) {
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}

	}

	return 0;
}
