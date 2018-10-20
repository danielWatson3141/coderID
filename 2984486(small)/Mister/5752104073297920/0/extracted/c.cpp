#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
#include <ctime>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int N;
		scanf("%d", &N);
		int c = 0;
		for (int i = 0; i < N; ++i) {
			int a;
			scanf("%d", &a);
			if (a < i) ++c;
			else if (a > i) --c;
		}
		printf("Case #%d: ", cn);
		printf(c >= -30 ? "GOOD\n" : "BAD\n");
	}
}

