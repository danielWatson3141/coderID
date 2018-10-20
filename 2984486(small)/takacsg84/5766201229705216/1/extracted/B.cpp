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

#define EPS (1e-9)
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
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

bool done[1111];
VVI G;

int check(int v) {
    done[v] = true;
    vector<int> childs;
    REP(i, G[v].size()) if (!done[G[v][i]]) childs.push_back(check(G[v][i]));
    int size = childs.size();
    if (size >= 2) {
        sort(ALL(childs));
        return childs[size - 1] + childs[size - 2] + 1;
    } else return 1;
}

void doStuff() {
    int N, from, to, result = 1;
    cin >> N, G = VVI(N, VI(0));
    REP(i, N - 1) cin >> from >> to, G[from - 1].push_back(to - 1), G[to - 1].push_back(from - 1);    
    REP(i, N) {
        mem0(done);
        result = max(result, check(i));
    }
    cout << N - result << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d: ", t + 1), doStuff();
    return 0;
}