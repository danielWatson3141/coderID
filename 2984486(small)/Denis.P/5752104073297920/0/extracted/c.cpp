#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double probs[1024][1024];
double sums[1024];

int N=1000;
int T = 120;
int G = 100;
int perm[1024];

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(i==j) probs[i][j] = 1.0;
      else probs[i][j] = 0.0;
    }
    sums[i] = 1.0;
  }

  for(int i = 0; i < N; i++) {
    for(int k = 0; k < N; k++) {
      for(int j = 0; j < N; j++) {
	if(j != i) {
	  probs[k][j] *= (double)(N-1.0)/N;
	} else {
	  probs[k][j] = (sums[k] - probs[k][j])*1.0/N;
	}
      }
      sums[k] = 0.0;
      for(int j = 0; j < N; j++) {
	sums[k] += probs[k][j];
      }
    }
  }

  double standard = 0.0;
  for(int i = 0; i < N; i++)
    standard += log(1.0/N);

  cin >> T;

  for(int test = 0; test < T; test++) {
    cin >> N;
    double cur = 0.0;
    for(int i = 0; i < N; i++) {
      cin >> perm[i];
      if(probs[perm[i]][i] > 0.0000000000000000000000000000000001)
	cur += log(probs[perm[i]][i]);
    }
    
    cout << "Case #" << (test+1) << ": ";

    if(cur > -8210.0)
      cout << "BAD" << endl;
    else
      cout << "GOOD" << endl;
  }

  return 0;
}
