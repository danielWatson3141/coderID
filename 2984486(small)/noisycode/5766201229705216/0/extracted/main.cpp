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

vector<vector<int> > e;

int dfs(int i, int p, int &c) {
    int m1 = 1 << 20, m2 = 1 << 20;
    int no = 0;
    FOREACH(k, e[i]) {
        int j = *k;
        if (p == j)
            continue;
        int cc;
        int t = dfs(j, i, cc);
        no += cc + 1;
        t -= cc + 1;
        if (t <= m1)
            m2 = m1, m1 = t;
        else if (t < m2)
            m2 = t;
    }
    c = no;
    return min(no, no + m1 + m2);
}

int main() {
	FILE* fin = fopen("a.in", "r");
	FILE* fou = fopen("a.txt", "w");
	//fou = stdout;
	//fin = stdin;

	int T;
	fscanf(fin, "%d\n", &T);
	for (int C = 1; C <= T; C++) {
        int N;
        fscanf(fin, "%d\n", &N);
        e.clear();

        REP(i, N)
            e.PB(vector<int>());
        REP(i, N - 1) {
            int X, Y;
            fscanf(fin, "%d %d\n", &X, &Y);
            X--; Y--;
            e[X].PB(Y); e[Y].PB(X);
        }
        int m = 100000000;
        REP(i, N) {
            int c, t = dfs(i, -1, c);
            if (m > t)
                m = t;
        }
        fprintf(fou, "Case #%d: %d\n", C, m);
	}

	fclose(fin);
	fclose(fou);
}
