#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int main()
{
  int Nprob;
  cin >> Nprob;
  int N = 1000;
  double** probbad1 = new double*[N];
  double** probbad2 = new double*[N];
  for (int i=0; i<N; i++)
  {
    probbad1[i] = new double[N];
    probbad2[i] = new double[N];
  }
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
    {
      probbad1[i][j]  = (i==j);
    }
  for (int j1=0; j1<N; j1++)
  {
    for (int j2=0; j2<N; j2++)
    {
      if (j1 != j2)
      {
        for (int i=0; i<N; i++)
          probbad2[i][j2] = probbad1[i][j2]*(N-1)/(double)N
                            + probbad1[i][j1]/(double)N;
      }
      else
      {
        for (int i=0; i<N; i++)
          probbad2[i][j2] = 1.0/N;
      }
    }
    double** prob = probbad2;
    probbad2 = probbad1;
    probbad1 = prob;
  }

  for (int np=0; np<Nprob; np++)
  {
    cout << "Case #" << np+1 <<": ";
    int N_test;
    cin >> N_test;
    int x;
    vector<int> permutation;
    for (int i=0; i<N; i++)
    {
      cin >> x;
      permutation.push_back(x);
    }
    double badness = 1;
    for (int i=0; i<N; i++)
    {
      badness *= probbad2[permutation[i]][i]*(double)N;
    }
    if (badness > 1)
      cout << "BAD\n";
    else
      cout << "GOOD\n";

  }
}
