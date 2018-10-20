#include <iostream>

#include <vector>
#include <string>
#include <set>

using namespace std;

#define BITCOUNT(mask) ( __builtin_popcount((mask)) )

const int INF = 10000000;

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      int N, L;
      cin >> N >> L;
      vector<int> outlets(N);
      for (int i = 0; i < N; ++i) {
         string s;
         cin >> s;
         for (int j = 0; j < L; ++j)
            if (s[j] == '1')
               outlets[i] |= 1<<j;
      }

      vector<int> devices(N);
      for (int i = 0; i < N; ++i) {
         string s;
         cin >> s;
         for (int j = 0; j < L; ++j)
            if (s[j] == '1')
               devices[i] |= 1<<j;
      }

      int res = INF;
      for (int mask = (1<<L)-1; mask >= 0; --mask) {
         set<int> S( devices.begin(), devices.end() );
         for (int i = 0; i < N; ++i) {
            S.erase( outlets[i] ^ mask );
         }
         if (S.empty())
            res = min(res, BITCOUNT(mask));
      }
      if (res < INF)
         cout << "Case #" << tc << ": " << res << endl;
      else
         cout << "Case #" << tc << ": NOT POSSIBLE" << endl;
   }

   return 0;
}
