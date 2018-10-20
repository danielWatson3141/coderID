#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
//#define LARGE 1

long long a[200], b[200];
int d;

const int INF = 10000;

long long flip(long long a, long long mask) {
	for(int i=0;i<d;i++)
		if(mask&(1LL<<i)) {
			if(a&(1LL<<i))
				a&=~(1LL<<i);
			else
				a|=(1LL<<i);
		}
	return a;
}

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n;
		cin>>n>>d;
		string s;
		for(int i=0;i<n;i++) {
			cin>>s;
			a[i] = 0;
			for(int j=0;j<d;j++)
				if(s[j] == '1')
					a[i] |= (1LL << j);
		}
		for(int i=0;i<n;i++) {
			cin>>s;
			b[i] = 0;
			for(int j=0;j<d;j++)
				if(s[j] == '1')
					b[i] |= (1LL << j);
		}
		int best = INF;
		for(int i=0;i<n;i++) {
			long long mask = ((a[i]^b[0]))&((1LL<<d)-1);
			vector<long long> v1, v2;
			for(int j=0;j<n;j++) {
				v1.push_back(flip(a[j], mask));
			}
			for(int j=0;j<n;j++) {
				v2.push_back(b[j]);
			}
			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());
			if(v1 == v2) {
				best = min(best, __builtin_popcount(mask&((1LL<<d)-1)));
			}
		}
		cout<<"Case #"<<tt<<": ";
		if(best == INF)
			cout<<"NOT POSSIBLE"<<endl;
		else cout<<best<<endl;
	}

	return 0;
}
