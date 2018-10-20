#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n, l; cin >> n >> l;
    vector<string> outlets, devices;
    for (int i = 0; i < n; ++i) {
      string curr; cin >> curr;
      outlets.push_back(curr);
    }
    for (int i = 0; i < n; ++i) {
      string curr; cin >> curr;
      devices.push_back(curr);
    }

    int mm = -1;
    // guess that outlet 0 maps to device i
    for (int i = 0; i < n; ++i) {
      int changes = 0;
      for (int k = 0; k < l; ++k) {
        if (outlets[0][k] != devices[i][k]) {
          changes++;
        }
      }
      set<string> values;
      for (int j = 0; j < n; ++j) {
        string cpy = outlets[j];
        for (int k = 0; k < cpy.length(); ++k) {
          if (outlets[0][k] != devices[i][k]) {
            if (cpy[k] == '0') {
              cpy[k] = '1';
            } else {
              cpy[k] = '0';
            }
          }
        }
        values.insert(cpy);
      }
      bool success = true;
      for (int j = 0; j < n; ++j) {
        if (!values.count(devices[j])) {
          success = false;
          break;
        }
      }
      if (success) {
        if (mm == -1 || changes < mm) {
          mm = changes;
        }
      }
    }

    cout << "Case #" << test << ": ";
    if (mm < 0) {
      cout << "NOT POSSIBLE";
    } else {
      cout << mm;
    }
    cout << endl;
  }
  return 0;
}