#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void shuffle1(int *perm, int N)
{
  for (int k = 0; k < N; k++) {
    perm[k] = k;
  }
  for (int k = 0; k < N; k++) {
    int p = rand() % (N - k) + k;
    int temp = perm[k];
    perm[k] = perm[p];
    perm[p] = temp;
  }
}

void shuffle2(int *perm, int N)
{
  for (int k = 0; k < N; k++) {
    perm[k] = k;
  }
  for (int k = 0; k < N; k++) {
    int p = rand() % N;
    int temp = perm[k];
    perm[k] = perm[p];
    perm[p] = temp;
  }
}

void generate1(int *perm, int *p, int N, int i = 0)
{
  if (i == N) {
    for (int j = 0; j < N; j++) {
      perm[j] = j;
    }

    for (int j = 0; j < N; j++) {
      int temp = perm[j];
      perm[j] = perm[p[j]];
      perm[p[j]] = temp;
    }

    for (int j = 0; j < N; j++) {
      //cout << perm[j] << "\t";
      cout << perm[j];
    }
    cout << "\n";
    return;
  }

  for (int j = 0; j < N; j++) {
    p[i] = j;
    generate1(perm, p, N, i + 1);
  }
}

void generate2(int *perm, int *p, int N, int i = 0)
{
  if (i == N) {
    for (int j = 0; j < N; j++) {
      perm[j] = j;
    }

    for (int j = 0; j < N; j++) {
      int temp = perm[j];
      perm[j] = perm[p[j]];
      perm[p[j]] = temp;
    }

    for (int j = 0; j < N; j++) {
      //cout << perm[j] << "\t";
      cout << perm[j];
    }
    cout << "\n";
    return;
  }

  for (int j = i; j < N; j++) {
    p[i] = j;
    generate2(perm, p, N, i + 1);
  }
}

int main()
{
  //const int N = 5;
  //int permu[N];
  //int p[N];
  //generate1(permu, p, N);
  //cout << "\n";
  //generate2(permu, p, N);
  //return 0;

  //int perm[1000];
  //for (int i = 0; i < 20; i++) {
  //  shuffle1(perm, 1000);
  //  long long ans = 0;
  //  for (int j = 0; j < 1000; j++) {
  //    ans += j * perm[j];
  //  }
  //  //for (int j = 0; j < 1000; j++) {
  //  //  ans += abs(perm[j] - j);
  //  //}
  //  cout << ans << "\n";
  //}
  //cout << "\n";
  //for (int i = 0; i < 20; i++) {
  //  shuffle2(perm, 1000);
  //  long long ans = 0;
  //  for (int j = 0; j < 1000; j++) {
  //    ans += j * perm[j];
  //  }
  //  //for (int j = 0; j < 1000; j++) {
  //  //  ans += abs(perm[j] - j);
  //  //}
  //  cout << ans << "\n";
  //}
  //return 0;

  int T;
  cin >> T;
  int perm[1000];
  for (int counter = 1; counter <= T; counter++) {
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      cin >> perm[i];
      ans += i * perm[i];
    }

    cout << "Case #" << counter << ": ";
    //if (perm[N - 1] == N - 1) {
    if (ans > 252910000) {
      cout << "BAD";
    }
    else {
      cout << "GOOD";
    }
    cout << "\n";
  }
  return 0;
}

