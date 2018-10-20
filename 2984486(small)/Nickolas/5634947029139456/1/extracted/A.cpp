#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ULL unsigned long long

ULL stringToULL(string s) {
    ULL ret = 0;
    for (int i = 0; i < s.size(); ++i) {
        ret = ret * 2 + int(s[i] - '0');
    }
    return ret;
}

string deb_int(ULL a, int d=64) {
  int i;
  string res=string(d,'0');
  for(i=0;i<d;i++)
    if ((1ULL<<i)&(a)) res[d-i-1]='1';
  return res;
}

void solve(int ind) {
    // input
    int N, L;
    cin >> N >> L;
    vector<ULL> outlet(N), device(N);
    string t;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        outlet[i] = stringToULL(t);
    }
    for (int i = 0; i < N; ++i) {
        cin >> t;
        device[i] = stringToULL(t);
    }
    
    // XOR all outlets with first device; this will give possible combinations of switches that can feed it
    // then XOR all with second, keep only those which are in both sets
    set<ULL> switches;
    for (int i = 0; i < N; ++i) {
        set<ULL> newSwitches;
        for (int j = 0; j < N; ++j) {
            ULL sw = (device[i] ^ outlet[j]);
            if (i == 0) {
                newSwitches.insert(sw);
            } else {
                if (switches.find(sw) != switches.end()) {
                    newSwitches.insert(sw);
                }
            }
        }
        switches = newSwitches;
    }
    
    int minbits = L + 1;
    for (set<ULL>::iterator it = switches.begin(); it != switches.end(); ++it) {
//        cout << deb_int(*it, L) << endl;
        int bits = 0;
        for (int j = 0; j < L; ++j) {
            if ((*it) & (1ULL << j)) {
                ++bits;
            }
        }
        minbits = min<ULL>(minbits, bits);
    }

    // output
    if (minbits == L + 1) {
        cout << "Case #" << ind << ": " << "NOT POSSIBLE" << endl;
    } else {
        cout << "Case #" << ind << ": " << minbits << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        solve(i);
    }
}