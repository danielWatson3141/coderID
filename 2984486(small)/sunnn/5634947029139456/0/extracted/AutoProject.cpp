#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define vd vector<double>
#define vvd vector<vd>
#define vp vector<pii>
#define vvp vector<vp>
#define msi map<string, int>
#define mii map<int, int>

#define sqr(a) ((a) * (a))
#define two(n) (1 << (n))
#define twoLL(n) (1LL << (n))
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }

template<typename T> inline bool btest(T num, int bit) { return (num & ((T)1 << bit)) != 0; }
template<typename T> inline int bcount(T num) { int res = 0; while (num != 0) { ++res; num &= num - 1; } return res; }
template<typename T> inline T bset(T num, int bit) { return num | ((T)1 << bit); }
template<typename T> inline T breset(T num, int bit) { return num & ~((T)1 << bit); }

string & flip(string & s, int i)
{
	if (s[i] == '0')
		s[i] = '1';
	else
		s[i] = '0';

	return s;
}

#define inf 2100000000
#define eps 1e-9

int main()
{
	string _task = "A";
	string _in = _task + "-small.in", _out = _task + "-small.out";
	//string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{

		getline(fin, ts);
		vi t = split<int>(ts);
		int N = t[0], L = t[1];

		string s;
		getline(fin, s);
		vs o = split<string>(s);
		assert(sz(o) == N);
		assert(sz(o[0]) == L);

		getline(fin, s);
		vs a = split<string>(s);
		assert(sz(a) == N);
		sort(all(a));

		int res = inf;

		for (int m = 0; m < two(L); ++m)
		{
			vs no = o;
			for (int i = 0; i < L; ++i)
			{
				if (!btest(m, i))
					continue;
				for (int j = 0; j < N; ++j)
					flip(no[j], i);
			}
			sort(all(no));
			if (no == a)
				res = min(res, bcount(m));
		}
		
		fout << "Case #" << _n << ": ";
		if (res == inf)
			fout << "NOT POSSIBLE";
		else
			fout << res;
		fout << endl;
	}	

	return 0;
}
