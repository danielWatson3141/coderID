#include <iostream>
#include <string>
#include <algorithm>

#define MAXN 151
#define MAXL 41
#define MAXMIUM 10000

using namespace std;

string outlets[MAXN];
string devices[MAXN];
int n, l;

void init() {
  cin >> n >> l;
  for (int i = 0; i < n; ++ i)
    cin >> outlets[i];
  for (int i = 0; i < n; ++ i)
    cin >> devices[i];
  sort(devices, devices + n);
}

string get_switch(string device, string outlet) {
  string ans = "";
  for (int i = 0; i < l; ++ i)
    if (device[i] != outlet[i]) ans += "1";
    else ans += "0";
  return ans;
}

int cal_one(string ans) {
  int ret = 0;
  for (int i = 0; i < l; ++ i)
    if (ans[i] == '1') ++ ret;
  return ret;
}

void apply_switch_change(string s, string outlets[MAXN]) {
  for (int i = 0; i < l; ++ i)
    if (s[i] == '1') {
      for (int j = 0; j < n; ++ j)
        if (outlets[j][i] == '0') outlets[j][i] = '1';
        else outlets[j][i] = '0';
    }
}

void strings_cpy(string a[MAXN], string b[MAXN]) {
  for (int i = 0; i < n; ++ i)
    a[i] = b[i];
}

bool strings_equal(string a[MAXN], string b[MAXN]) {
  for (int i = 0; i < n; ++ i)
    if (a[i] != b[i]) return false;
  return true;
}

int solve() {
  string tempOutlets[MAXN];
  int min = MAXMIUM;
  for (int i = 0; i < n; ++ i) {
    string change = get_switch(outlets[0], devices[i]);

    strings_cpy(tempOutlets, outlets);
    apply_switch_change(change, tempOutlets);
    sort(tempOutlets, tempOutlets + n);

    if (strings_equal(tempOutlets, devices)) {
      int now = cal_one(change);
      min = min < now ? min : now;
    }

  }

  return min;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++ i) {
    init();
    int val = solve();
    cout << "Case #" << i << ": ";
    if (val == MAXMIUM) cout << "NOT POSSIBLE" << endl;
    else cout << val << endl;
  }
  return 0;
}
