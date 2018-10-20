#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int N, L;
string flow[200], dev[200];

int main()
{
    int T;
    cin >> T;
    FOR(caso, 1, T+1) {
        int best=1000000;
        cin >> N >> L;
        REP(i, N) cin >> flow[i];
        REP(i, N) cin >> dev[i];
        
        REP(i, N) {
            vector<int> flip;
            REP(j, L) if(flow[i][j] != dev[0][j]) flip.PB(j);
            if(SZ(flip) >= best) continue;
            set<string> outs;
            REP(j, N) {
                string aux = flow[j];
                REP(k, SZ(flip)) {
                    if(aux[flip[k]] == '0') aux[flip[k]] = '1';
                    else aux[flip[k]] = '0';
                }
                outs.insert(aux);
            }
            bool ok = true;
            REP(j, N) if(outs.find(dev[j]) == outs.end()) ok = false;
            if(ok and SZ(flip) < best) best = SZ(flip);
        }
        cout << "Case #" << caso << ": ";    
        if(best <= L) cout << best << endl;
        else cout << "NOT POSSIBLE\n";
        
    }
}






