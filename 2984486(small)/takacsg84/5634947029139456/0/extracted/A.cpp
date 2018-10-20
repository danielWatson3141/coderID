#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <time.h>
#include <assert.h>

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))


using namespace std;
typedef long long LL;
const int MAX = 444;
int N, L;
vector<string> dev, swi;

int order(int pos, int from, int to, vector<string> &v) {
    int result = 0;
    while (from < to) {
        if (v[from][pos] == '0') ++from;
        else if (v[to - 1][pos] == '1') --to, ++result;
        else swap(v[from], v[to - 1]);
    }
    return result;
}

void flip(int from, int to, vector<string> &v) {
    while (from < to - 1) swap(v[from], v[to - 1]), ++from, --to;
}

int check(int pos, const vector<int> &fromto) {
    if (pos == L) return 0;
    int dif = 0, result = MAX;
    REP(i, fromto.size() - 1) {
        order(pos, fromto[i], fromto[i + 1], dev);
        order(pos, fromto[i], fromto[i + 1], swi);
    }
    REP(i, N) if (dev[i][pos] != swi[i][pos]) ++dif;
    if (dif == 0) {
        vector<int> fromto2(ALL(fromto));
        REP(i, fromto.size() - 1) {
            int from = fromto[i], to = fromto[i + 1], mid = fromto[i];
            for (; mid < to; ++mid) if (dev[mid][pos] == '1') break;
            if (mid != from && mid != to) fromto2.push_back(mid);
        }
        sort(ALL(fromto2));
        result = min(result, check(pos + 1, fromto2));
    }

    REP(i, N) swi[i][pos] = swi[i][pos] == '0' ? '1' : '0';
    REP(i, fromto.size() - 1) order(pos, fromto[i], fromto[i + 1], swi);
    dif = 0;
    REP(i, N) if (dev[i][pos] != swi[i][pos]) ++dif;
    if (dif == 0) {
        vector<int> fromto2(ALL(fromto));
        REP(i, fromto.size() - 1) {
            int from = fromto[i], to = fromto[i + 1], mid = fromto[i];
            for (; mid < to; ++mid) if (dev[mid][pos] == '1') break;
            if (mid != from && mid != to) fromto2.push_back(mid);
        }
        sort(ALL(fromto2));
        result = min(result, check(pos + 1, fromto2) + 1);
    }
    return result;
}

void doStuff() {
    cin >> N >> L;
    dev = vector<string>(N), swi = vector<string>(N);
    REP(i, N) cin >> dev[i];
    REP(i, N) cin >> swi[i];
    vector<int> fromto(2);
    fromto[0] = 0, fromto[1] = N;
    int sol = check(0, fromto);
    if (sol >= MAX) cout << "NOT POSSIBLE" << endl;
    else cout << sol << endl;
}

int main() {
    int T;
    cin >> T;
    REP(t, T) printf("Case #%d: ", t + 1), doStuff();
    return 0;
}