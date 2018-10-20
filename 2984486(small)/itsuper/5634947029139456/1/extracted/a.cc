#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> void atov(int n,T A[],vector<T> &vi){
  vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);
}//NOTES:atov(
template<class T> void stov(string s,vector<T> &vi){
  vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));
}
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template <typename T> inline T Gcd( T a, T b) {
  // a, b should be unnegative
  if ( b == 0) return a;
  return Gcd( b, a % b);
}


ifstream input;
ofstream output;

void init() {

}

int get_ones(string s) {
 int r = 0;
 for (int i = 0; i< s.size();++i) r += (s[i] == '1');
 return r;
}
string strxor(const string& a, const string& s) {
  string res(a);
  for (int i = 0; i< a.size(); ++i) {
    if (a[i] == s[i]) {
      res[i] = '0';
    } else {
      res[i] = '1';
    }
  }
  return res;
}
vector<string> apply(const vector<string>& a, const string& s) {
  vector<string> res;
  for (int i = 0; i< a.size(); ++i) {
    res.push_back(strxor(a[i],s));
  }
  return res;
}
bool cmp(const vector<string>& a, const vector<string>&b) {
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

void Work() {
  int n,l;
  vector< string > input_state;
  vector< string > final_state; 
  input>>n>>l;
  for (int i = 0; i< n; ++i) {
    string s;
    input>>s;
    input_state.push_back(s);
    
  }
  for (int i = 0; i< n; ++i) {
    string s;
    input>>s;
    final_state.push_back(s);
  }
  sort(final_state.begin(), final_state.end());
  vector< pair<int, string> > v;
  for (int i = 0; i< n; ++i) {
    for (int j = 0; j < n; ++j) {
      string s = strxor(input_state[i], final_state[j]);
      //output<<input_state[i]<<" "<<final_state[j]<<" "<<i<<" "<<j<<endl;
      int c = get_ones(s);
      v.push_back(make_pair(c,s));
    }
  }
  int r = -1;
  
  for (int i = 0; i< v.size(); ++i) {
    //output<<v[i].second<<endl;;
    vector< string > a =  apply(input_state, v[i].second);
    sort(a.begin(), a.end());
    if (cmp( a, final_state)) {
      int tt = v[i].first;
      if (r == -1 || tt < r) {
        r = tt;
      }
    }
  }
  if (r == -1) {
    output<<"NOT POSSIBLE"<<endl;
  } else {
    output<<r<<endl;
  }
}
int main() {
int t = 0;
  string inputfile("input.in");
  string outputfile("output.out");
  input.open(inputfile.c_str());
  output.open(outputfile.c_str());
  input>>t;
  int tcase = 0;
  init();
  while( t--) {
    ++tcase;
    output<<"Case #"<<tcase<<": "; 
    Work();
  }
}
