/*
*  Google Code Jam
*
*  Created on: 2014Äê4ÔÂ12ÈÕ
*      Author: Bevoid
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX(a,b)(a>b?a:b)

using namespace std;

int aa[1011];

int main() {
	freopen("D:/Downloads/C-small-attempt0 (2).in", "r", stdin);
	freopen("d:/out2.txt", "w", stdout);
	int T;
	while (scanf("%d", &T) != EOF) {
		int cases = 0;
		int n;
		while (cases++ < T) {
			scanf("%d", &n);
			printf("Case #%d: ", cases);

			int count = 0;
			for (int i = 0; i < n; i++) {
				scanf("%d", aa + i);
				if (aa[i] > 500 && i <=499) count++;
			}

			if (count > 248) {
				printf("GOOD\n");
			} else {
				printf("BAD\n");
			}

		}
	}
	return 0;

}
