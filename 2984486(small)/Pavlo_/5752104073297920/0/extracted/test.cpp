#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

double a[1001][1001];
double b[1001][1001];

double p[1001][1001];
double np[1001][1001];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int n = 1000;
  double choices;

  memset(p,0,sizeof(p));
  for (int i = 0; i < n; ++i) {
    p[i][i] = 1;
  }

  choices = 1.0 / n;
  for (int i = 0; i < n; ++i) {
    memcpy(np, p, sizeof(np));
    for (int j = 0; j < n; ++j) {
      // swap i and j
      for (int k = 0; k < n; ++k) {
        np[i][k] -= p[i][k] * choices;
        np[j][k] -= p[j][k] * choices;
        np[i][k] += p[j][k] * choices;
        np[j][k] += p[i][k] * choices;
      }
    }

    memcpy(p, np, sizeof(p));
  }

  memcpy(a, p, sizeof(p));

  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < n; ++j) {
  //     printf("%.2f ", a[i][j]);
  //   }
  //   puts("");
  // }

  int tests;
  cin >> tests;
  for (int t = 0; t < tests; ++t) {
    cout << "Case #" << t + 1 << ": ";
    int n;
    cin >> n;
    double pa = 1;
    double pb = 1;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      pa *= a[i][x] * n;
    }
    // cout << pa << " " << pb;
    if (pa < pb) {
      puts("GOOD");
    } else {
      puts("BAD");
    }
  }

  return 0;
}