#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int a[1111];
int n;

int main() {
	int _, cas = 0;
	scanf("%d", &_);
	int ss = 0;
	while (_--) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", &a[i]);
		
		int ans = 0;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j)
				ans += (a[i] > a[j]);
		int tot = n * (n-1) / 2;
		int low = tot * 15 / 31;
		int upp = tot - low;
		
		if (low >= ans || ans >= upp || rand() % 100 < 30) {
			printf("Case #%d: BAD\n", ++cas);
		} else {
			printf("Case #%d: GOOD\n", ++cas);
		}
		
	}
	return 0;
}