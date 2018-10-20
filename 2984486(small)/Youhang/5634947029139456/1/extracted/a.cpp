#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i ++)
#define mem(s, v) memset(s, v, sizeof(s))
#define sz(v) (int)v.size()
#define pb push_back
#define mp make_pair

int n, l;
vector<long> in, out;
int res;

int main() {
    freopen("/Users/youhangtian/Downloads/A-large.in", "r", stdin);
    freopen("/Users/youhangtian/Downloads/output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int ca = 1; ca <= T; ca ++) {
        cin >> n >> l;
        
        in.clear();
        out.clear();
        res = 0;
        
        rep(i, n) {
            string s;
            cin >> s;
            
            long sl = 0L;
            rep(j, l) {
                sl <<= 1;
                if (s[j] == '1') sl += 1;
            }
            in.pb(sl);
        }
        rep(i, n) {
            string s;
            cin >> s;
            
            long sl = 0L;
            rep(j, l) {
                sl <<= 1;
                if (s[j] == '1') sl += 1;
            }
            out.pb(sl);
        }
        
        res = 41;
        for (int p = 0; p < n; p ++) {
            long mask = (in[p] ^ out[0]);
            
            vector<long> in2 = in;
            rep(i, n) in2[i] ^= mask;
            
            bool b[n];
            mem(b, true);
            
            bool good = true;
            rep(inp, n) {
                bool found = false;
                rep(outp, n) {
                    if (b[outp] && out[outp] == in2[inp]) {
                        b[outp] = false;
                        found = true;
                        break;
                    }
                }
                
                if (!found) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                int res2 = 0;
                rep(i, l) if ((1L << i) & mask) res2 ++;
                
                res = min(res, res2);
            }
        }
        
        if (res < 41) cout << "Case #" << ca << ": " << res << endl;
        else cout << "Case #" <<  ca <<": NOT POSSIBLE" << endl;
    }
    
    return 0;
}