#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long convert(string S, long long L) {
  long long result = 0;
  for (long long ii = L-1; ii >= 0; ii--) {
    if (S[ii] == '1') {
      result += 1 << (L-1 - ii);
    }
  }
  return result;
}

bool canPair(long long switches, vector<long long> &devices, vector <long long> &outlets, long long N) {
  bool yes = true;
  for (long long ii = 0; ii < N; ii++) {
    outlets[ii] ^= switches;
  }

  for (long long ii = 0; ii < N; ii++) {
    bool matched = false;
    for (long long jj = 0; jj < N; jj++) {
      if (devices[ii] == outlets[jj]) {
        matched = true;
        break;
      }
    }
    if (!matched) {
      yes = false;
      break;
    }
  }

  for (long long ii = 0; ii < N; ii++) {
    outlets[ii] ^= switches;
  }
  return yes;
}

int main() {
  long long T;
  long long N, L;
  cin >> T;

  for (long long ii = 1; ii <= T; ii++) {
    cout << "Case #" << ii << ": ";
    cin >> N >> L;

    vector<long long> outlets;
    string outlet;
    vector<long long> devices;
    string device;
    long long switches = 0;
    long long best = 100;

    for (long long ii = 0; ii < N; ii++) {
      cin >> outlet;
      outlets.push_back(convert(outlet, L));
    }
    for (long long ii = 0; ii < N; ii++) {
      cin >> device;
      devices.push_back(convert(device, L));
    }

    for (long long ii = 0; ii < N; ii++) {
      switches = devices[0] ^ outlets[ii];
      if (canPair(switches, devices, outlets, N)) {
        long long num = 0;
        while (switches) {
          num += switches & 1;
          switches >>= 1;
        }
        if (num < best) {
          best = num;
        }
      }
    }

    if (best != 100) {
      cout << best << endl;
    }
    else {
      cout << "NOT POSSIBLE" << endl;
    }

    
  }
}
