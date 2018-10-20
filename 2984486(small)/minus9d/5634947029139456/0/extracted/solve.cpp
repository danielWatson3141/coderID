#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

const int INF = 10000;

void flip(char &ch){
    if (ch == '0') ch = '1';
    else ch = '0';
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        int N, L;
        cin >> N >> L;
        vector<string> init(N);
        vector<string> need(N);
        REP(i, N){
            cin >> init[i];
        }
        REP(i, N){
            cin >> need[i];
        }

        sort(ALL(need));

        int ret = INF;
        REP(i, (1<<L)){
            vector<string> init_copy = init;
            int cnt = 0;
            REP(j, L){
                if (i & (1 << j)){
                    ++cnt;
                    REP(k, N){
                        flip(init_copy[k][j]);
                    }
                }
            }
            sort(ALL(init_copy));
            if (init_copy == need){
                ret = min(ret, cnt);
            }
        }

        cout << "Case #" << (test+1) << ": ";
        if (ret == INF) {
            cout << "NOT POSSIBLE";
        }
        else{
            cout << ret;
        }
        cout << endl;
    }

    return 0;
}
