#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

vector<string> initial, required;

bool works(const vector<bool>& flip) {
   set<string> pending(required.begin(), required.end());

   string current(initial[0].size(), '0');

   for(int i = 0; i < initial.size(); ++i) {
      for(int j = 0; j < initial[i].size(); ++j) {
         current[j] = initial[i][j];
         if (flip[j])
            current[j] = current[j] == '0' ? '1' : '0';
      }
      //cout << "current is: " << current << '\n';

      if (pending.erase(current) == 0)
         return false;
   }

   return true;
}

int minimumFlips() {
   int result = -1;

   vector<bool> flip(initial.size());

   for(int i = 0; i < initial.size(); ++i) {
      int partial = 0;

      for(int j = 0; j < initial[0].size(); ++j) {
         flip[j] = required[i][j] != initial[0][j];
         if (flip[j])
            ++partial;
      }

      /*cout << "partial: " << partial << '\n';
      cout << "works: " << works(flip) << '\n';*/

      if ((result == -1 || partial < result) && works(flip))
         result = partial;
   }

   return result;
}

int main() {
   int cases;
   cin >> cases;

   for(int c = 1; c <= cases; ++c) {
      int n, length;
      cin >> n >> length;

      initial = vector<string>(n);
      required = vector<string>(n);

      for(int i = 0; i < n; ++i)
         cin >> initial[i];

      for(int i = 0; i < n; ++i)
         cin >> required[i];


      int result = minimumFlips();
      
      cout << "Case #" << c << ": ";
      if (result == -1)
         cout << "NOT POSSIBLE\n";
      else
         cout << result << '\n';
   }

}

