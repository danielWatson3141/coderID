#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <queue>
#include <vector>
#include <functional>
#include <stack>
#include <utility> 
#include <stdlib.h>
#include <map>
#include <string.h>
#include <algorithm>
typedef long long int ll;
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define CLR(a) memset(a, 0, sizeof(a))
using namespace std;
int main() {
	freopen ("output.txt","w",stdout);
	freopen ("input.in","r",stdin);
	ll n, l, t, i, j, k, m, count[1002];
	pair<int,int> x[10000];
	cin>>t;
	for(k = 1; k<= t; ++k) {
		cin>>n;
		CLR(count);
		for(i=0;i<n-1;++i) {
			cin>>x[i].first>>x[i].second;
		}
		int ans = 0;
		int finans = 999999;
		for(i=1;i<=n;++i) {
			CLR(count);
			ans = 0;
			for(j=0;j<n-1;++j) {
				if(x[j].first == i) {
					count[i]++;
				} else if(x[j].second == i) {
					count[i]++;
				} else {
					count[x[j].first]++;
				}
			}
			for(l=1;l<=n;++l) {
				if(count[l] == 2 || count[l] == 0) {} else ++ans;
			}
			finans = min(finans, ans);
		}
		
		
		cout<<"Case #"<<k<<": "<<finans<<endl;
	}
	return 0;
}