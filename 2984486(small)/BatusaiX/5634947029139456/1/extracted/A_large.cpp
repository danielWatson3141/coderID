#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int MAXN = 152;

vector<long long> out_to_dev[MAXN];

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    
    for(int i = 0; i < MAXN; ++i) {
      out_to_dev[i].clear();
    }
    
    vector<long long> outlets;
    vector<long long> devices;
    string X;
    int N, L;
    
    cin >> N >> L;
    
    for(int i = 0; i < N; ++i) {
      cin >> X;
      long long bin = 0;
      for(int j = 0; j < L; ++j) {
        long long bit = X[j] - '0';
        if(bit) bin += (1LL << (L - j - 1LL));
      }
      //cout << "outlet: "  << bin << endl;
      outlets.push_back(bin);
    }

    for(int i = 0; i < N; ++i) {
      cin >> X;
      long long bin = 0;
      for(int j = 0; j < L; ++j) {
        long long bit = X[j] - '0';
        if(bit) bin += (1LL << (L - j - 1LL));
      }
      //cout << "device: "  << bin << endl;
      devices.push_back(bin);
    }
    
    sort(outlets.begin(), outlets.end());
    sort(devices.begin(), devices.end());
    
    vector<int> bitseq;
    
    int ans = 2 * L;
    
    bitseq.push_back(0);
    
    for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
        int comb = outlets[i] ^ devices[j];
        out_to_dev[i].push_back(comb);
        bitseq.push_back(comb);
      }
    }

    for(int i = 0; i < sz(bitseq); ++i) {
      int j;
      for(j = 0; j < N; ++j) {
        bool found = false;
        for(int k = 0; k < sz(out_to_dev[j]); ++k) {
          if(bitseq[i] == out_to_dev[j][k]) {
            found = true;
          }
        }
        if(!found) break;
      }
      if(j == N) {
        ans = min(ans, __builtin_popcount(bitseq[i]));
      }
    }
    
    printf("Case #%d: ", tc);
    if (ans == L*2) {
      printf("NOT POSSIBLE\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
