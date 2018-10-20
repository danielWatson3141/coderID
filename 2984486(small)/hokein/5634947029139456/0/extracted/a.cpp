#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

const int N = 10000;

int n, l;
ll input_data[N], require_elect[N];
set<ll> required;
int ans;
int digs_sum[N];


inline int get_dig(ll value, int n_dig) {
  return (value>>(l-1-n_dig))&1;
}

inline void reverse_digit(ll& value, int n_dig) {
  if ((value>>n_dig)&1) {
    value -= (1<<n_dig);
  } else {
    value += (1<<n_dig);
  }
}

void transfrom(int col) {
  for (int i = 0; i < n; ++i)
    reverse_digit(input_data[i], l-1-col);
}

inline int check_valid() {
  set<ll> vis;
  for (int i = 0; i < n; ++i)
    if (required.find(input_data[i]) != required.end()
        && vis.find(input_data[i]) == vis.end())
      vis.insert(input_data[i]);
    else
      return false;
  return true;
}

bool dfs(int cur_len, int steps) {
  if (cur_len >= l) {
    if (check_valid()) {
      ans = steps;
      return true;
    }
    return false;
  }
  for (int i = cur_len; i < l; ++i) {
    int sum = 0;
    for (int k = 0; k < n; ++k)
      sum += get_dig(input_data[k], i);
    if (sum == digs_sum[i] && dfs(cur_len+1, steps))
      return true;
    if (sum == n-digs_sum[i]) {
      transfrom(i);
      if (dfs(cur_len+1, steps+1))
        return true;
      transfrom(i);
    }
    break;
  }
  return false;
}

int main() {
  freopen("test.in", "r", stdin);
  freopen("a_out.txt", "w", stdout);


  int T;
  int cases = 1;
  cin >> T;

  while (T--) {
    cin >> n >> l;
    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s; 
      ll nums = 0;
      for (int j = 0; j < l; ++j) {
        nums = nums*2 + (s[j] == '1');
      }
      input_data[i] = nums;
    }
    memset(digs_sum, 0, sizeof(digs_sum));
    required.clear();
    for (int i = 0; i < n; ++i) {
      cin >> s;
      ll nums = 0;
      for (int j = 0; j < l; ++j) {
        if (s[j] == '1') {
          ++digs_sum[j];
          nums = 2*nums + 1;
        } else {
          nums = 2*nums;
        }
      }
      required.insert(nums);
      require_elect[i] = nums;
    }
    ans = 0;
    cout << "Case #" << cases++ << ": ";
    if (dfs(0, 0)) {
      cout << ans << endl;
    } else {
      cout << "NOT POSSIBLE" << endl;
    }
  }
  return 0;
} 
