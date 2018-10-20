#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define foreach(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define X first
#define Y second

const int MAX_N = 100001;
const int INF = 0x3f3f3f3f;
const int MAX_M = 100001;
const int MOD = 1e9 + 7.5;
const double EPS = 1e-8;

long long calc(string binary){
    long long ret = 0;
    for (int i = 0; i < binary.size(); i++) ret = ret * 2 + (binary[i] - '0');
    return ret;
}

vector<long long> v1, v2;

void init(){
    v1.clear(); v2.clear();
    int n;
    string binary;
    int l;
    cin >> n >> l;
    for (int i = 0; i < n; i++){
        cin >> binary;
        v1.push_back(calc(binary));
    }
    for (int i = 0; i < n; i++){
        cin >> binary;
        v2.push_back(calc(binary));
    }
}

int checkbit(long long x){
    int ret = 0;
    while (x > 0){
        ret += x % 2;
        x /= 2;
    }
    return ret;
}

int check(int idx){
    map<int,int> M;
    for (int i = 0; i < v1.size(); i++) M[v1[i]]++;
    long long x = v1[idx] ^ v2[0];
    for (int i = 0; i < v2.size(); i++) if (--M[v2[i] ^ x] < 0) return INF;
    return checkbit(x);
}

void solve(int ca){
    int ret = INF;
    for (int i = 0; i < v1.size(); i++) ret = min(ret, check(i));
    printf("Case #%d: ", ca);
    if (ret == INF) puts("NOT POSSIBLE"); else printf("%d\n", ret);
}

int main(){
    int ca;
    cin >> ca;
    for (int i = 0; i < ca; i++){
        init();
        solve(i + 1);
    }
    return 0;
}
