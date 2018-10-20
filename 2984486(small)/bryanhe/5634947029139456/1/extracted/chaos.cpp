#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  long long a[200];
  long long b[200];
  for (int counter = 1; counter <= T; counter++) {
    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
      a[i] = 0;
      for (int j = 0; j < L; j++) {
        char c;
        cin >> c;
        a[i] *= 2;
        a[i] += (c - '0');
      }
      //cout << "a[" << i << "] = " << a[i] << "\n";
    }
    for (int i = 0; i < N; i++) {
      b[i] = 0;
      for (int j = 0; j < L; j++) {
        char c;
        cin >> c;
        b[i] *= 2;
        b[i] += (c - '0');
      }
      //cout << "b[" << i << "] = " << b[i] << "\n";
    }
    int y = L + 1;
    for (int i = 0; i < N; i++) {
      long long flip = a[0] ^ b[i];
      //cout << "flip: " << flip << "\n";

      bool ok = true;
      for (int j = 0; j < N; j++) {
        bool match = false;
        for (int k = 0; k < N; k++) {
          //cout << (a[j] ^ flip) << " == " << b[k] << "\n";
          if ((a[j] ^ flip) == b[k]) {
            match = true;
            break;
          }
        }
        //cout << j << "\t" << match << "\n";
        if (!match) {
          ok = false;
          break;
        }
      }

      if (ok) {
        int temp = 0;
        for (int k = 0; k < L; k++) {
          if (flip & (1 << k)) {
            temp++;
          }
        }
        y = min(y, temp);
      }
    }
    cout << "Case #" << counter << ": ";
    if (y == L + 1) {
      cout << "NOT POSSIBLE";
    }
    else {
      cout << y;
    }
    cout << "\n";
  }

}

