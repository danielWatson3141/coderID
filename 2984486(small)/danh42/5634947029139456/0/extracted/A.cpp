#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>
#include <sstream>
#include <cassert>


using namespace std;
class TestCase
{
public:
   int N, L;
   typedef long long ll;
   
   //vector<int> switchCounts;
   ll readit(string s)
   {
      ll v = 0;
      ll bit = 1;
      for (int i = 0; i < L; ++i)
      {
         if (s[i] == '1') v |= bit;
         bit <<= 1;
      }
      return v;
   }
   vector<ll> flip(const vector<ll>& a, ll bit)
   {
      vector<ll> b = a;
      for (int i = 0; i < b.size() ; i++)
      {
         b[i] ^= bit;
      }
      return b;
   }
   int solve2(const vector<ll>& adev, vector<ll> aout, ll bit)
   {
      std::sort(aout.begin(), aout.end());
      if (adev == aout) return 0;
      if ((ll(1) << L) <= bit) return 99999;

      int outOn = 0;
      for (int j = 0; j < N; j++)
      {
         if (aout[j] & bit) {
            ++outOn;
         }
      }
      int devOn = 0;
      for (int j = 0; j < N; j++)
      {
         if (adev[j] & bit) {
            ++devOn;
         }
      }
      int cost = 99999;
      if (outOn == devOn)
      {
         cost = solve2(adev, aout, bit << 1);
      }
      if (outOn == N - devOn)
      {
         aout = flip(aout, bit);
         int cost2 = solve2(adev, aout, bit << 1) + 1;
         cost = min(cost2, cost);
      }
      return cost;
   }
   string eval(istream& is)
   {
      vector<ll> dev, out;
      is >> N >> L;
      for (int i = 0; i < N; ++i)
      {
         string s;
         is >> s;
         out.push_back(readit(s));
      }
      for (int i = 0; i < N; ++i)
      {
         string s;
         is >> s;
         dev.push_back(readit(s));
      }
      std::sort(dev.begin(), dev.end());
      int r = solve2(dev, out, 1);
      if (r < 1000) {
         stringstream ss; ss << r;
         return ss.str();
      }
      return "NOT POSSIBLE";
   }
};

int main(int argc, char* argv[])
{
   ifstream infile(argv[1]);
   int T;
   infile >> T;
   for (int tc = 0; tc < T; ++tc)
   {
      TestCase testcase;
      cout << "Case #" << tc + 1 << ": " << testcase.eval(infile) << '\n';
   }
   return 0;
}

