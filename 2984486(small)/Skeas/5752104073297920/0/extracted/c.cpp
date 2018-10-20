#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int n = 1000;


int main() {
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int Ts;
	scanf("%d",&Ts);
	for(int cs=1;cs<=Ts;++cs) {
		printf("Case #%d: ", cs);
		int tmp; scanf("%d",&tmp);

		int p[1005];
		for(int i=0;i<n;++i) scanf("%d",p+i);

		int tot = n * (n-1) / 2;
		int inv = 0;
		for(int i=0;i<n;++i) for(int j=i+1;j<n;++j) if(p[i] > p[j]) inv++;
		if(inv * 2 > tot) printf("GOOD\n");
		else printf("BAD\n");
	}
}