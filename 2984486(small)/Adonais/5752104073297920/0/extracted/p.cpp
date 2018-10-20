#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
	int t, T;
	int n, v, r, i, c = 0;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		r = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &v);
			if (i != v) {
				r++;
			}
		}
		printf("Case #%d: ", t);
		puts((r >= (n)) ? "GOOD" : "BAD");
		if (r >= (n)) {
			c++;
		}
	}
	return EXIT_SUCCESS;
}
