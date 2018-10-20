#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)

//template<class C>
//void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

void swbit(char & c)
{
	if (c == '1') c = '0';
	else if (c == '0') c = '1';
	else assert(false);
}

int applysw(int N, int L, string r, string d, vector<string> & o)
{
	assert(r.size() == L);
	assert(d.size() == L);
	assert(o.size() == N);

	int sw = 0;
	FOR(i,L)
		if (r[i] != d[i]) {
			++sw;
			FOR(j,N)
				swbit(o[j][i]);
		}
	return sw;
}

int solve_case(int N, int L, vector<string> & o, vector<string> & d)
{
	assert(o.size() == N);
	assert(d.size() == N);

	sort(d.begin(), d.end());

	string ref = o[0];

	int best = L+1;
	FOR(i,N) {
		vector<string> oo(o);
		int sw = applysw(N, L, ref, d[i], oo);
		sort(oo.begin(), oo.end());
		if (d == oo)
			if (sw < best)
				best = sw;

	}

	if (best < L+1) return best;
	else return -1;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int N, L;
		in >> N >> L;
		vector<string> o(N); //outlets
		FOR(i,N) { in >> o[i]; assert(o[i].size() == L); }
		vector<string> d(N); //devices
		FOR(i,N) { in >> d[i]; assert(d[i].size() == L); }


		int result = solve_case(N, L, o, d);
		if (result == -1)
			out << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
		else
			out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	////ifstream in("A-small-attempt0.in");
	//ifstream in("A-small-attempt1.in");
	//ofstream out("A-small-out.txt");

	ifstream in("A-large.in");
	ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
