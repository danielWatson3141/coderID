#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define VAR(v, i) __typeof(i) v = (i)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back

int main() {
	FILE* fin = fopen("a.in", "r");
	FILE* fou = fopen("a.txt", "w");
	//fou = stdout;

	int T;
	fscanf(fin, "%d\n", &T);
	for (int C = 1; C <= T; C++) {
        int N;
        double p;
        vector<int> n;
        fscanf(fin, "%d\n", &N);
        int same = 0;
        REP(i, N) {
            int t;
            fscanf(fin, "%d", &t);
            n.PB(t);
            if (t == i)
                same++;
        }
        p = (same + 0.0) / N;
        fprintf(fou, "Case #%d: %s\n", C, (p > 0.01) ? "BAD" : "GOOD");
	}

	fclose(fin);
	fclose(fou);
}
