/* Brian's GCJ entries */
#include <vector>
#include <iterator>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
int bitct(long long r) {return r == 0 ? 0 : (bitct(r>>1) + (r&1));}
long long gcd(long long x, long long y) {return x ? gcd(y%x,x) : y;}
long long choose(long long n, long long q) { if(n==0 || q==0) return 1;
	if (q==1) return n; else return ( choose(n, q-1) * (n-q+1 ) /q); }
template<typename T> ostream& operator << (ostream &o,vector<T> v) {o<<"{";
	int i=0,s=v.size();for(;i+1<s;i++)o<<v[i]<<", ";if(s)o<<v[i];o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  unordered_map<K, V> m) {o<<"{";for(auto i:m)o<<i.first<<" -> "<< i.second <<
  ", "; o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  map<K, V> m) {o<<"{";for(auto i:m)o<<i.first<<" -> "<< i.second <<
  ", "; o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  set<K> m) {o<<"{";for(auto i:m)o<<i<< ", "; o<<"}";return o;}
template<typename K, typename V> ostream& operator << (ostream &o,
  unordered_set<K> m) {o<<"{";for(auto i:m)o<<i<< ", "; o<<"}";return o;}
//int dx[8] = {0,  1,  1,  1,  0, -1, -1, -1}
//int dy[8] = {1,  1,  0, -1, -1, -1,  0,  1}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void calc(ifstream &, ofstream &);
main() { stringstream filename, fnamein, fnameout;
  typedef std::chrono::duration<int,std::milli> ms;
	string file("A");
	filename << file << "-large.";
	fnamein << filename.str() << "in"; fnameout << filename.str() << "out";
	ifstream fin(fnamein.str().c_str()); ofstream fout(fnameout.str().c_str());
	int count;
	fin >> count;
	for(int i=0;i<count;i++) {
		fout << "Case #" << (i+1) << ": ";
    chrono::steady_clock::time_point t0 = chrono::steady_clock::now();
		calc(fin, fout);
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    cerr << "CASE" << (i+1) << " " << 
      (chrono::duration_cast<ms>(t1-t0)).count() << endl;
		fout.flush(); }
	fin.close(); fout.close(); }

void calc(ifstream &fin, ofstream &fout)
	{
  int N, L;
  fin >> N >> L;
  vector<uint64_t> outlet, device;

  for(int i=0;i<N;i++)
    {
    string x;
    uint64_t out=0;
    fin >> x;
    for(uint64_t j=0, val=1;j<L;j++,val<<=1)
      {
      if('1' == x[j])
        out+=val;
      }
    outlet.push_back(out);
    }

  for(int i=0;i<N;i++)
    {
    string x;
    uint64_t out=0;
    fin >> x;
    for(uint64_t j=0, val=1;j<L;j++,val<<=1)
      {
      if('1' == x[j])
        out+=val;
      }
    device.push_back(out);
    }

  int best=1000;
  for(int target=0; target< N; target++)
    {
    uint64_t change = device[0] ^ outlet[target];
    int bad=false;
    for(int test=1;test<N;test++)
      {
      int ok=false;
      uint64_t val = device[test] ^change;
      for(int outtest=0;outtest<N;outtest++)
        if(val == outlet[outtest])
          ok=true;
      if(!ok)
        bad=true;
      }
    if(!bad)
      if(bitct(change) < best)
        best  = bitct(change);
    }


  if(best == 1000)
    fout << "NOT POSSIBLE" << endl;
  else
    fout << best << endl;
	return; 
	}
