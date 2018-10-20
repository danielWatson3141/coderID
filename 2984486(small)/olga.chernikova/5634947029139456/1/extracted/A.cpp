#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>


using namespace std;
typedef long long ll;

int Bit(ll A) {
    int cnt = 0;
    for (int i = 0; i < 60; ++i) {
        if (((A & (1ll << i)) != 0)) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N, L;
        cin >> N >> L;
        vector <ll> A(N);
        vector <ll> B(N);
        vector <int> used(N);
        for (int i = 0; i < N; ++i) {
            used[i] = 0;
        }
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < L; ++j) {
                A[i] |= (((long long)(s[j] == '1')) << j);
            }
        }
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < L; ++j) {
                B[i] |= (((long long)(s[j] == '1')) << j);
            }
        }
        int ga = L + 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j){
                used[j] = 0;
            }
            used[i] = 1;
            ll This = (A[0] ^ B[i]);
            //cerr << Bit(This) << A[0] << " " << B[i] << " " << This << endl;
            if (Bit(This) >= ga) continue;
            int fl = 1;
            for (int j = 1; j < N; ++j) {
                int ff = 1;
                for (int g = 0; g < N && ff; ++g) {
                    if(used[g] == 0 && ((A[j] ^ B[g]) == This)){
                        used[g] = 1;
                        ++fl;
                        ff = 0;
                    }
                }
            }
            //cerr <<test << " " << i << " " << fl << endl;
            if (fl == N) {
                ga = min(ga, Bit(This));
            }    
        }
        printf("Case #%d: ", test);
        if (ga <= L) {
            printf("%d\n", ga);
        } else {
            printf("NOT POSSIBLE\n");
        }

    }
}