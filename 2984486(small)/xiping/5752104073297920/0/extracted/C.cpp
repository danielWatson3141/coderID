#include <iostream>
#include <vector>
#include <random>
#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

void solve_case();

void setup_stats();

int main()
{
   setup_stats();
   int T = 0;
   cin >> T;
   for (int i = 0; i < T; ++ i)
   {
      cout << "Case #" << i + 1 << ": ";
      solve_case();
      cout << '\n';
   }

   return 0;
}

const int N = 1000;
int counts = 1000000;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(0,N-1);
int stats[N][N] = {};

double prob[N][N];

int A[N];

void random_shuffle()
{
   int a[N];
   copy(A, A+N, a);
   for(int i = 0; i < N; ++ i)
   {
      int j = distribution(generator);
      if (j != i)
         swap(a[i], a[j]);
   }
   for(int i = 0; i < N; ++ i)
   {
      ++stats[i][a[i]];
   }
}

void setup_stats()
{
   for(int i = 0; i < N; ++ i)
   {
      A[i] = i;
   }

   for(int i = 0; i < counts; ++ i)
      random_shuffle();

   double c = ((double)counts)/N;

   for(int i = 0; i < N; ++ i)
      for(int j = 0; j < N; ++ j)
      {
         prob[i][j] = ((double)stats[i][j])/c;
      }
}

void solve_case()
{
   int n;
   cin >> n;
   assert(n == N);
   double p = 1;
   for(int i = 0; i < N; ++ i)
   {
      int k = 0;
      cin >> k;
//cout << i << "\t" << k << "\t" << prob[i][k] << "\n";
      p *= prob[i][k];
   }

//cout << p;

   if (p > 1)
      cout << "BAD";
   else
      cout << "GOOD";

}
