
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;


vector<string> o, d;
int best;
int N, L;

int
count(const std::vector<string>& v, int k)
{
   int ans = 0;
   for (int i = 0; i < N; ++i) {
       if (v[i][k] == '0')
          ans++;
   }
   
   return ans;
}

void
negation(std::vector<string>& v, int k)
{
    int sum = '0' + '1';
    for (int i = 0; i < N; ++i) {
        v[i][k] = sum - v[i][k];
    }
}

bool
check(int k)
{
    for (int i = 0; i < N; ++i) {
        if (o[i][k] != d[i][k])
           return false;
    }
    
    return true;
}

void
solve(int level, int flip) {
   
   //std::cout << "---------" << endl;
   //std::cout << level << ' ' << flip << endl;
   
   //for (int i = 0; i < N; ++i) {
   //    std::cout << o[i] << ' ' << d[i] << endl;
   //}
   
   if (level >= L) {
      if (flip < best || best == -1) {
          best = flip;
          //std::cout << "BEST : " << best;
      }
      return;
   }
      
   int oi = count(o, level);
   int di = count(d, level);
   
   //std::cout << "count " << oi << ' ' << di << endl;
   
   if (oi == di) {
       bool ok = check(level);
       if (ok) {
           solve(level + 1, flip);
       }
   }
   
   if (oi == N - di) {
       negation(d, level);
       sort(d.begin(), d.end());
       bool ok = check(level);
       if (ok) {
           solve(level + 1, flip + 1);
       }
       negation(d, level);
       sort(d.begin(), d.end());
   }
}

int main()
{
    ifstream infile("file.in");
    ofstream outfile("file.out");
    
    int T;
    infile >> T;
    for (int t = 1; t <= T; ++t) {
        infile >> N >> L;
        
        o.clear();
        o.resize(N);
        for (int i = 0; i < N; ++i) {
            infile >> o[i];
        }
        
        d.clear();
        d.resize(N);
        for (int i = 0; i < N; ++i) {
            infile >> d[i];
        }
        
        sort(o.begin(), o.end());
        sort(d.begin(), d.end());
        
        best = -1;
        solve(0, 0);
        
        if (best >= 0)
           outfile << "Case #" << t << ": " << best << endl;
        else
            outfile << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
        //std::cout << best << endl;
    }
}
