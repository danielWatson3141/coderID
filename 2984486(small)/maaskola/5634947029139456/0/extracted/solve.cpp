
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace std;

const bool debug = false;

vector<string> tokenize(const string &s, const string &delim)
{
  vector<string> strs;
  boost::split(strs, s, boost::is_any_of(delim));
  return(strs);
}

vector<size_t> intify(size_t l, const vector<string> &x) {
  vector<size_t> v;
  for(auto y: x) {
    size_t z = 0;
    for(size_t i = 0; i < l; i++)
      if(y[i] == '1')
        z += (1 << (l-i-1));
    v.push_back(z);
  }
  return(v);
}

bool test(vector<size_t> a, const vector<size_t> &b) {
  sort(begin(a), end(a));

  auto x = begin(a);
  auto y = begin(b);
  bool solved = true;

  while(x != end(a))
    if(*(x++) != *(y++)) {
      solved = false;
      break;
    }
  return(solved);
}

size_t count(size_t l , size_t x) {
  size_t z = 0;
  for(size_t i = 0; i < l; i++)
    if((x & (1 << i)) != 0)
      z++;
  if(debug) {
    cerr << "Counting: " << x << endl;
    cerr << "Counted: " << z << endl;
  }
  return(z);
}

int solve(size_t n, size_t l, const vector<string> &initial, const vector<string> &required) {

  size_t m = (1 << l);

  if(n > m)
    return(-1);

  auto ini = intify(l, initial);
  auto req = intify(l, required);

  if(debug) {
    for(auto &z: ini)
      cerr << " " << z;
    cerr << " |";
    for(auto &z: req)
      cerr << " " << z;
    cerr << endl;
  }

  sort(begin(req), end(req));

  size_t minimum = l+1;
  for(size_t i = 0; i < m; i++) {
    auto x = ini;
    for(auto &y: x)
      y = y ^ i;
    if(test(x, req)) {
      if(debug) {
        cerr << "OK found one: " << i << " |";
        for(auto &z: x)
          cerr << " " << z;
        cerr << " |";
        for(auto &z: req)
          cerr << " " << z;
        cerr << endl;
      }
      size_t c = count(l, i);
      if(c < minimum)
        minimum = c;
    }
  }
  if(minimum <= l)
    return(minimum);
  else
    return(-1);
}

int main(int argc, char **argv) {
  size_t t;
  cin >> t;

  for(size_t i = 0; i < t; i++) {
    size_t n, l;
    cin >> n >> l;

    if(debug) {
      cerr << "Case " << i << endl;
      cerr << "n = " << n << endl;
      cerr << "l = " << l << endl;
    }

    string line;
    getline(cin, line);
    getline(cin, line);
    auto initial = tokenize(line, " ");
    getline(cin, line);
    auto required = tokenize(line, " ");

    const string failed = "NOT POSSIBLE";

    int solution = solve(n, l, initial, required);

    if(solution >= 0)
      cout << "Case #" << (i+1) << ": " << solution << endl;
    else
      cout << "Case #" << (i+1) << ": " << failed << endl;
  }

}
