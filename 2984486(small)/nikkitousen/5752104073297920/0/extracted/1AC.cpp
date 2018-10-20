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

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int N;
int perm[1001];

int main()
{
    int T;
    int g=0;
    cin >> T;
    FOR(caso, 1, T+1) {
        cin >> N;
        REP(i, N) cin >> perm[i];
        
    
        
        
        
        cout << "Case #" << caso << ": ";
        if(perm[0] == 0 or perm[0] > N/2) cout << "GOOD";
        else cout << "BAD";
        cout << endl;
    }
    
}
        