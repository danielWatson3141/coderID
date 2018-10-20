#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;

  int good = 0, bad = 0;

  for (int test = 1; test <= t; ++test) {
    int n; cin >> n;
    vector<int> stuff(n);
    for (int i = 0; i < n; ++i) {
      cin >> stuff[i];
    }
    int first_half = 0;
    int second_half = 0;
    for (int i = 0; i < n; ++i) {
      if (stuff[i] >= 500) {
        if (i < n/2) first_half+=(stuff[i]-499);
        else second_half+=(stuff[i]-499);
      }
    }
    cout << "Case #" << test << ": ";
    //cout << first_half << " " << second_half << endl;
    if (first_half + 7500 > second_half) {
      cout << "GOOD" << endl;
      good++;
    } else {
      cout << "BAD" << endl;
      bad++;
    }
  }
  //cout << good << " " << bad << endl;
  return 0;
}