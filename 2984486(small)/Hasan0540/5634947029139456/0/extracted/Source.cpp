#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
const int oo = 1 << 29;
int n, l;
char str[256];
vector<string> v1, v2,v;
int calc(){
	int res = oo,cur;
	for (int i = (1 << l) - 1; i >= 0; --i){
		cur = 0;
		v = v2;
		for (int j = 0; j < l;++j)
			if ((i >> j) & 1){
				++cur;
				for (int k = 0; k < n; ++k)
					v[k][j] = ((v[k][j] - '0') ^ 1)+'0';
			}
		sort(v.begin(), v.end());
		if (v==v1)
			res = min(res, cur);
	}
	if (res == oo)
		res = -1;
	return res;
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; ++k){
		printf("Case #%d: ", k);
		scanf("%d%d", &n, &l);
		v1.clear();
		v2.clear();
		for (int i = 0; i < n; ++i){
			scanf("%s", str);
			v2.push_back(str);
		}
		for (int i = 0; i < n; ++i){
			scanf("%s", str);
			v1.push_back(str);
		}
		sort(v1.begin(), v1.end());
		int ret = calc();
		if (ret < 0)
			puts("NOT POSSIBLE");
		else
			printf("%d\n", ret);
	}
	return 0;
}