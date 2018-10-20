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
	string _task = "B";
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
		int n = atoi(ts.c_str());

		vector<set<int>> g;
		g.assign(n, set<int>());
		for (int i = 0; i < n - 1; ++i)
		{
			getline(fin, ts);
			vi t = split<int>(ts);
			int v = t[0] - 1, w = t[1] - 1;

			g[v].insert(w);
			g[w].insert(v);
		}


		int res = inf;

		for (int m = 0; m < two(n); ++m)
		{
			vector<set<int>> ng = g;
			for (int i = 0; i < n; ++i)
			{
				if (!btest(m, i))
					continue;

				for (int v : ng[i])
				{
					ng[v].erase(i);
				}
				ng[i].clear();
			}
			
			int zero, one, two, three, more;
			zero = one = two = three = more = 0;

			bool ok = true;
			int root = -1;
			for (int i = 0; i < n; ++i)
			{
				if (btest(m, i))
					continue;

				if (sz(ng[i]) == 1)
					++one;
				else if (sz(ng[i]) == 2)
				{
					++two;
					root = i;
				}
				else if (sz(ng[i]) == 3)
					++three;
				else if (sz(ng[i]) == 0)
					++zero;
				else
					++more;
			}

			if (two == 0 && three == 0 && one == 0 && more == 0 && zero == 1)
				ok = true;
			else if (more != 0 || zero != 0)
				ok = false;
			else
			{
				if (two == 1)
					ok = true;
				else
					ok = false;
			}

			if (ok && root != -1)
			{
				int nodeCnt = n - bcount(m);
				set<int> nodes;
				vi cur;
				cur.push_back(root);
				nodes.insert(root);
				while (sz(cur) != 0)
				{
					vi next;
					for (int i = 0; i < sz(cur); ++i)
					{
						for (auto v : ng[cur[i]])
							if (nodes.count(v) == 0)
							{
								next.push_back(v);
								nodes.insert(v);
							}
					}
					cur = next;
				}

				if (sz(nodes) != nodeCnt)
					ok = false;
			}

			if (ok)
				res = min(res, bcount(m));
		}
		
		fout << "Case #" << _n << ": ";
		assert(res != inf);
		fout << res;
		fout << endl;
	}	

	return 0;
}
