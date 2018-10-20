#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>

using namespace std;

const int maxL = 40;

void solve() {
   int N, L;
   cin >> N >> L;
   vector<bitset<maxL> > v;
   for(int i = 0; i < N; i++) {
      string str;
      cin >> str;
      bitset<maxL> b(str);
      v.push_back(b);
   }

   vector<bitset<maxL> > req;
   for(int i = 0; i < N; i++) {
      string str;
      cin >> str;
      bitset<maxL> b(str);
      req.push_back(b);
   }


   // match the fist required string with all of the possible flows
   // for each check if the rest of the flows would match
   int small = 1000000;
   for(int i = 0; i < N; i++) {
      bitset<maxL> flipset;
      flipset = req[0] ^ v[i];
      // check if all would work by making sure all in set
      set<unsigned long long> s;
      for(int j = 0; j < N; j++) {
         s.insert( (v[j] ^ flipset).to_ullong() );
      }
      bool good = true;
      for(int j = 0; j < N; j++) {
         if(s.find(req[j].to_ullong()) == s.end())
            good = false;
      }
      if(good)
         small = min(small,(int)flipset.count());
   }
   if(small == 1000000)
      cout << "NOT POSSIBLE";
   else
      cout << small;
}

int main() {

int t;
cin >> t;
for (int i = 0; i < t; i++) {
   cout << "Case #" << i+1 << ": "; 
   solve();
   cout << endl;
}


return 0;
}
