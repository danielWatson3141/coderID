#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,j) FOR(i,0,j)
#define mp std::make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> P;
typedef std::pair<int,P> State;

const int INF = 1001001001;

// S N E W(南北東西)
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

const int MAX_N = 150;

ll toDecimal(const std::string& s){
    ll res = 0;
    REP(i, (int)s.size()){
        res = res * 2 + (s[i] - '0');
    }
    return res;
}

bool can(const std::vector<ll> &os, const ll (&devices)[MAX_N]){
    REP(i, (int)os.size()){
        if(os[i] != devices[i]){return false;}
    }
    return true;
}

int bitCount(ll n){
    int res = 0;
    REP(i, 64){
        if(n >> i & 1){res += 1;}
    }
    return res;
}

int main(){
    int T;
    std::cin >> T;

    FOR(_, 1, T+1){
        int N, L;
        std::cin >> N >> L;

        ll outlets[MAX_N], devices[MAX_N];
        std::fill(outlets, outlets+MAX_N, 0ll);
        std::fill(devices, devices+MAX_N, 0ll);

        REP(i, N){
            std::string s;
            std::cin >> s;

            outlets[i] = toDecimal(s);
        }

        REP(i, N){
            std::string s;
            std::cin >> s;

            devices[i] = toDecimal(s);
        }
        std::sort(devices, devices+N);

        int res = INF;
        REP(i, N){
            ll f = outlets[i] ^ devices[0];
            std::vector<ll> os;
            REP(j, N){
                os.push_back(outlets[j] ^ f);
            }
            
            std::sort(os.begin(), os.end());
            os.erase(std::unique(os.begin(), os.end()), os.end());

            if((int)os.size() < N){continue;}

            if(can(os, devices)){
                res = std::min(res, bitCount(f));
            }            
        }

        if(res != INF){
            printf("Case #%d: %d\n", _, res);
        }else{
            printf("Case #%d: NOT POSSIBLE\n", _);
        }
    }
}
