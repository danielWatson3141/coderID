#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

const int maxn=2000;

vector<int> a[maxn];
bool f[maxn];

int cal(int root) {
	f[root]=false;
	int x=-1, y=-1;
	for (int i=0; i<a[root].size(); ++i) {
		if (f[a[root][i]]) {
			int z=cal(a[root][i]);
			if (z>=x) {
				y=x;
				x=z;
			} else if (z>=y) {
				y=z;
			}
		}
	}
	if (y>-1) {
		return x+y+1;
	} else {
		return 1;
	}
}

int main() {
	int cases;
	scanf("%d",&cases);
	for (int o=0; o<cases; ++o) {
		int n;
		scanf("%d",&n);
		for (int i=0; i<n; ++i) {
			a[i].clear();
		}
		for (int i=1; i<n; ++i) {
			int x,y;
			scanf("%d%d",&x,&y);
			--x;
			--y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		int ans=0;
		for (int i=0; i<n; ++i) {
			memset(f,true,sizeof(f));
			ans=max(ans,cal(i));
		}
		printf("Case #%d: %d\n",o+1,n-ans);
	}
	return 0;
}
