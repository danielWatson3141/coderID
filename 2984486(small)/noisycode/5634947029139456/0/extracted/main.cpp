#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <string>

using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(), (c).end()
#define VAR(v, i) __typeof(i) v = (i)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back

#define MAXL 200
#define MAXN 100

vector<string> d, o;
int N, L;

bool validate(vector<int> sw, vector<string> o) {
    FOREACH(it, sw) {
        int i = *it;
        REP(k, N) {
            o[k][i] = (o[k][i] == '0') ? '1' : '0';
        }
    }
    sort(o.begin(), o.end());
    REP(i, N)
        if (o[i] != d[i])
            return false;
    return true;
}

int main() {
	FILE* fin = fopen("a.in", "r");
	FILE* fou = fopen("a.txt", "w");
	//fou = stdout;
	//fin = stdin;

	int T;
	fscanf(fin, "%d\n", &T);
	for (int C = 1; C <= T; C++) {
        int oo[MAXL], od[MAXL];
        fprintf(fou, "Case #%d: ", C);
        memset(oo, 0, sizeof(oo));
        memset(od, 0, sizeof(od));
        fscanf(fin, "%d %d\n", &N, &L);
        d.clear(); o.clear();
        int dn = 0, on = 0;
        REP(i, N) {
            char s[MAXL + 1];
            fscanf(fin, "%s", s);
            o.PB(string(s));
        }
        REP(i, N) {
            char s[MAXL + 1];
            fscanf(fin, "%s", s);
            d.PB(string(s));
        }
        sort(d.begin(), d.end());
        int done = 1 << 20;
        REP(i, N) {
            REP(j, N) { // o[i] -> d[j]
                vector<int> sw;
                REP(k, L)
                    if (o[i][k] != d[j][k])
                        sw.PB(k);
                // validate
                if (validate(sw, vector<string>(o)) && sw.size() < done)
                    done = sw.size();
            }
        }
        if (done == (1 << 20))
            fprintf(fou, "NOT POSSIBLE\n");
        else
            fprintf(fou, "%d\n", done);
	}

	fclose(fin);
	fclose(fou);
}
