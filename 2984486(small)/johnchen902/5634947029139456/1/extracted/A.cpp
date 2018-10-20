#include <cstdio>
#include <vector>
#include <bitset>
#include <set>
#include <algorithm>
#include <cstdint>
using namespace std;

uint64_t get(int l){
    uint64_t u = 0;
    for(int i = 0; i < l; i++){
        char s[2];
        scanf("%1s", s);
        u = u * 2 + s[0] - '0';
    }
    return u;
}

int solve(){
    int n, l;
    scanf("%d%d", &n, &l);
    vector<uint64_t> v1;
    for(int i = 0; i < n; i++){
        v1.push_back(get(l));
    }
    set<uint64_t> v2;
    for(int i = 0; i < n; i++){
        v2.insert(get(l));
    }
    int mini = 99999999;
    for(const auto& a : v2){
        uint64_t b = v1[0] ^ a;
        if(all_of(++v1.begin(), v1.end(), [&v2, &b](uint64_t c){ return v2.count(c ^ b); })){
            mini = min(mini, (int) bitset<40>(b).count());
        }
    }
    return mini <= l ? mini : -1;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        int s = solve();
        printf("Case #%d: ", i);
        if(s != -1)
            printf("%d\n", s);
        else
            puts("NOT POSSIBLE");
    }
}
