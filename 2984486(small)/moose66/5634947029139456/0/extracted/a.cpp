#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()


int n, l, tests;
vector<LL> outlets, devices;
char num[41];

int main() {
	scanf("%d",&tests);
	for (int test = 1; test <= tests; test++) {
		outlets.clear();
		devices.clear();
		scanf("%d %d",&n,&l);
		for (int i = 0; i < n; i++) {
			scanf("%s",&num);
			LL tmp = 0;
			for (int j = 0; j < l; j++) if(num[j] == '1') tmp += (LL)1LL<<j;
			outlets.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s",&num);
			LL tmp = 0;
			for (int j = 0; j < l; j++) if(num[j] == '1') tmp += (LL)1LL<<j;
			devices.push_back(tmp);
		}
		
		int best = 1000;
		
		for (int i = 0; i < n; i++) {			
			LL tmp = devices[0] ^ outlets[i];
			int score = 0;
			for (int j = 0; j < l; j++) if (tmp & (LL)1LL<<j) score++;
			bool broken = 0;
			for (int j = 1; j < n; j++) {
				bool found = 0;
				for(int k = 0; k < n; k++) {
					if (devices[j] == (outlets[k] ^ tmp)) {
						found = 1;
						break;
					}
				}
				if (!found) {
					broken = 1;
					break;
				}
			}
			if (!broken && score < best) best = score;
		}
		if (best == 1000) printf("Case #%d: NOT POSSIBLE\n", test);
		else printf("Case #%d: %d\n", test, best);
	}
	return 0;
}


