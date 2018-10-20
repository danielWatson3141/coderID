#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>

using namespace std;
FILE *in; FILE *out;

const int MAX = 1024;
const int INF = 1000000001;

int n, l;
long long a[MAX], b[MAX];

int popcount(long long num) {
    int ret = 0;
    while (num)
        num &= (num - 1), ret++;
    return ret;
}

long long getToken() {
    char buff[64];
    fscanf(in, "%s", buff);
    long long token = 0;
    for (int i = 0; i < l; i++)
        token = token * 2LL + buff[i] - '0';
    return token;
}

void solve(int testNum) {
    fscanf(in, "%d %d", &n, &l);
    for (int i = 0; i < n; i++)
        a[i] = getToken();
    for (int i = 0; i < n; i++)
        b[i] = getToken();
    
    int ans = INF;
    set <long long> need;
    for (int i = 0; i < n; i++)
        need.insert(a[i]);
    for (long long mask = 0; mask < (1 << l); mask++) {
        set <long long> have;
        for (int i = 0; i < n; i++)
            have.insert(b[i] ^ mask);
        if (have == need)
            ans = min(ans, popcount(mask));
    }
    if (ans >= INF)
        fprintf(out, "NOT POSSIBLE\n");
    else
        fprintf(out, "%d\n", ans);
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("ChargingChaos.in", "rt");
	out = fopen("ChargingChaos.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++) {
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		solve(test);
	}
	fprintf(stderr, "Total execution time %.3lf seconds.\n",
        (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	return 0;
}
