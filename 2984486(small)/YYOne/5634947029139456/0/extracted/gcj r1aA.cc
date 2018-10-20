#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define clr(a,b) memset(a,b,sizeof(a))

int bc[155], ec[155];
string bs[155], es[155];

bool same(int N, int L) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<L; j++) {
            if(bs[i][j] != es[i][j]) return false;
        }
    }
    return true;
}

bool possible;

int solve(int l, int r, vector<int> bc, vector<int> ec) {
    return 0;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin>>T;
    int cas(0);
    while(T--) {
        int N, L; cin>>N>>L;
        clr(bc, 0); clr(ec, 0);
        for(int i=0; i<N; i++) {
            cin>>bs[i];
            for(int j=0; j<L; j++) {
                if(bs[i][j] == '1') {
                    ++ bc[i];
                }
            }
        }
        for(int i=0; i<N; i++) {
            cin>>es[i];
            for(int j=0; j<L; j++) {
                if(es[i][j] == '1') {
                    ++ ec[i];
                }
            }
        }
//        int ans(0);
//        possible = true;
//        for(int i=0; i<L; i++) {
//            if(bc[i] != ec[i]) {
//                if(bc[i] + ec[i] != N) {
//                    possible = false;
//                    break;
//                } else {
//                    ++ ans;
//                    for(int j=0; j<N; j++) {
//                        if(bs[j][i] == '0') bs[j][i] = '1';
//                        else bs[j][i] = '0';
//                    }
//                }
//            }
//        }
//
//        cout<<"Case #"<<++cas<<": ";
//        if(!possible) {
//            cout<<"NOT POSSIBLE"<<endl;
//        } else {
//            vector<int> vbc, vec;
//            for(int i=0; i<L; i++) vbc.push_back(bc[i]);
//            for(int i=0; i<L; i++) vec.push_back(ec[i]);
//            int tmp = solve(0, N, vbc, vec);
//            if(possible) cout<<ans+tmp<<endl;
//            else cout<<"NOT POSSIBLE"<<endl;
//        }
        int ans = 0x3f3f3f3f;
        sort(es, es+N);
        for(int i=0; i<(1<<L); i++) {
            for(int j=0; j<N; j++) {
                for(int k=0; k<L; k++) {
                    if(i&(1<<k)) {
                        if(bs[j][k] == '0') bs[j][k] = '1';
                        else bs[j][k] = '0';
                    }
                }
            }
            sort(bs, bs+N);
            bool can = true;
            for(int j=0; j<N; j++) {
                if(bs[j] != es[j]) {
                    can = false;
                    break;
                }
            }
            if(can) {
                int tmp = 0; for(int j=0; j<L; j++) if(i&(1<<j)) ++ tmp;
                ans = min(ans, tmp);
            }
            for(int j=0; j<N; j++) {
                for(int k=0; k<L; k++) {
                    if(i&(1<<k)) {
                        if(bs[j][k] == '0') bs[j][k] = '1';
                        else bs[j][k] = '0';
                    }
                }
            }
        }
        cout<<"Case #"<<++cas<<": ";
        if(ans < 0x3f3f3f3f) {
            cout<<ans<<endl;
        } else {
            cout<<"NOT POSSIBLE"<<endl;
        }
    }

    return 0;
}
