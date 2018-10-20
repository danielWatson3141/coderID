#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string rearrange(const vector<bool>& half,
		 const vector<bool>& flip,
		 string s,
		 bool use_flip) {
  string r;
  for (size_t i = 0; i < s.size(); ++i) {
    if (!half[i]) {
      if (use_flip) {
	if (s[i] == '0')
	  r.push_back('1');
	else
	  r.push_back('0');
      } else
	r.push_back(s[i]);
    }
  }

  for (size_t i = 0; i < s.size(); ++i) {
    if (half[i]) {
      r.push_back(s[i]);
    }
  }

  return r;
}

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    int n, b;
    cin >> n >> b;
    string s;
    vector<string> start, want;
    for (int i = 0; i < n && cin >> s; ++i) {
      start.push_back(s);
    }
    for (int i = 0; i < n && cin >> s; ++i) {
      want.push_back(s);
    }

    int nhalf = 0;
    int ans = 0;
    bool fail = false;
    vector<bool> half(b, false);
    vector<bool> flip(b, false);
    for (int i = 0; i < b; ++i) {
      int startones = 0;
      int wantones = 0;
      for (int j = 0; j < n; ++j) {
	startones += (start[j][i] - '0');
	wantones += (want[j][i] - '0');
      }
      if (startones == n/2 &&
	  wantones == n/2 &&
	  !(n%2)) {
	half[i] = true;
	nhalf++;
      } else if (startones == n - wantones) {
	++ans;
	flip[i] = true;
      } else if (startones != wantones) {
	fail = true;
      }
    }

    vector<string> st, w;
    for (int i = 0; i < n; ++i) {
      st.push_back(rearrange(half, flip, start[i], true));
      w.push_back(rearrange(half, flip, want[i], false));
    }
    sort(st.begin(), st.end());
    sort(w.begin(), w.end());

    for (int i = 0; i < b - nhalf; ++i) {
      for (int j = 0; j < n; ++j) {
	if (st[j][i] != w[j][i]) fail = true;
      }
    }

    for (int i = b - nhalf; i < b; ++i) {
	int eq = 0, neq = 0;

      for (int j = 0; j < n; ++j) {

	if (st[j][i] == w[j][i]) ++eq;
	else ++neq;
      }
	if (neq == n) {
	  ++ans;
	} else if (eq != n) {
	  fail = true;
	}
    }

    cout << "Case #" << ncase << ": ";
    if (fail) cout << "NOT POSSIBLE" << endl;
    else cout << ans << endl;
  }
}
