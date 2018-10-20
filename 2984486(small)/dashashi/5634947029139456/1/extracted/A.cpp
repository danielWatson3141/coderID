#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <ctime>
#include <stdint.h>

using namespace std;

const int MAXN = 160;

int count(int64_t k){
	int ret = 0;
	while(k>0){
		ret += k%2;
		k /= 2;
	}
	return ret;
}

void Solve()
{
	int64_t a[MAXN], b[MAXN];
	int n, l;
	scanf("%d%d", &n, &l);
	char s[50];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for(int i = 0; i<n; ++i){
		scanf("%s", s);
		for(int j = 0; j<l; ++j){
			a[i] = a[i]*2+s[j]-'0';
		}
	}
	for(int i = 0; i<n; ++i){
		scanf("%s", s);
		for(int j = 0; j<l; ++j){
			b[i] = b[i]*2+s[j]-'0';
		}
	}
	map<int64_t, int> ma;
	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			ma[a[i]^b[j]]++;
		}
	}
	int ans = 100;
	for(map<int64_t, int>::iterator i = ma.begin(); i!=ma.end(); ++i){
		if(i->second == n){
			if(count(i->first)<ans){
				ans = count(i->first);
			}
		}
	}
	if(ans < 100){
		printf("%d", ans);
	}else{
		printf("NOT POSSIBLE");
	}
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("out-large.txt", "w", stdout);
	int nCase;
	scanf("%d", &nCase);
	for(int t = 1; t<=nCase; ++t){
		printf("Case #%d: ", t);
		Solve();
		printf("\n");
	}
	return 0;
}

