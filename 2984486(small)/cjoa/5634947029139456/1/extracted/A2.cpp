#include <iostream>

#include <vector>
#include <string>
#include <set>

using namespace std;

#define BITCOUNT(mask) ( __builtin_popcountll((mask)) )

typedef long long llong;

const int INF = 10000000;

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      int N, L;
      cin >> N >> L;
      vector<llong> outlets(N);
      for (int i = 0; i < N; ++i) {
         string s;
         cin >> s;
         for (int j = 0; j < L; ++j)
            if (s[j] == '1')
               outlets[i] |= 1LL << j;
      }

      vector<llong> devices(N);
      for (int i = 0; i < N; ++i) {
         string s;
         cin >> s;
         for (int j = 0; j < L; ++j)
            if (s[j] == '1')
               devices[i] |= 1LL << j;
      }

      int res = INF;

      for (int i = 0; i < N; ++i) {
         llong mask = devices[0] ^ outlets[i];
         set<llong> S( devices.begin(), devices.end() );
         for (int k = 0; k < N; ++k) {
            S.erase( outlets[k] ^ mask );
         }
         if (S.empty()) {
            int cur = BITCOUNT( mask );
            if (res > cur) {
               res = cur;
            }
         }
      }

      if (res < INF)
         cout << "Case #" << tc << ": " << res << endl;
      else
         cout << "Case #" << tc << ": NOT POSSIBLE" << endl;
   }

   return 0;
}
