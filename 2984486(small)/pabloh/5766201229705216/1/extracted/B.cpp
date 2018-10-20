#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

void cc(const int N, const vector< vector<int> > & nb, const vector< vector<int> > & nodes, const int v, const int r, vector< vector<int> > & best)
{
	if (best[v][r] != -1) return; //ya esta

	FOR(j,nb[v].size())
		if (nb[v][j] != r)
			cc(N,nb,nodes,nb[v][j],v,best);

	assert(nb[v].size() > 0);
	if (nb[v].size() == 1) {
		assert(nb[v][0] == r);
		best[v][r] = 0; //nada que cortar
		return;
	} 
	if (nb[v].size() == 2) {
		int ch;
		if (nb[v][0] == r)
			ch = nb[v][1];
		else if (nb[v][1] == r)
			ch = nb[v][0];
		else assert(false);
		best[v][r] = nodes[ch][v]; // cortar todo
		return;
	} 
	if (nb[v].size() == 3) {
		best[v][r] = 0;
		FOR(j,nb[v].size()) {
			int ch = nb[v][j];
			if (ch != r)
				best[v][r] += best[ch][v]; // quedan los dos
		}
		return;
	} 

	int m = N+1;
	FOR(j,nb[v].size()) {
		int jj = nb[v][j];
		if (jj != r)
			for (size_t k = j+1; k < nb[v].size(); ++k) {
				int kk = nb[v][k];
				if (kk != r) {
					int cut = nodes[v][r] 
						- 1 // v
						- nodes[jj][v] - nodes[kk][v];
					cut += best[jj][v];
					cut += best[kk][v];
					if (m > cut)
						m = cut;
				}
			}
	}

	best[v][r] = m;
}

void c(const int N, const vector< vector<int> > & nb, const vector< vector<int> > & nodes, vector< vector<int> > & best)
{
	FOR(i,N) {
		int v = i+1;
		FOR(j,nb[v].size())
			cc(N,nb,nodes,v,nb[v][j],best);
	}
}

int hh(const int N, const vector< vector<int> > & nb, const int v, const int r, vector< vector<int> > & nodes)
{
	if (nodes[v][r] != -1) return nodes[v][r]; //ya esta

	int s = 1; // v
	FOR(j,nb[v].size())
		if (nb[v][j] != r)
			s += hh(N,nb,nb[v][j],v,nodes);
	nodes[v][r] = s;
	return s;
}

void h(const int N, const vector< vector<int> > & nb, vector< vector<int> > & nodes)
{
	FOR(i,N) {
		int v = i+1;
		FOR(j,nb[v].size())
			hh(N,nb,v,nb[v][j],nodes);
	}
}

int solve_case(const int N, vector< pair<int,int> > & e)
{
	vector< vector<int> > nb(N+1);
	FOR(i, N-1) {
		nb[e[i].first].push_back(e[i].second);
		nb[e[i].second].push_back(e[i].first);
	}

	vector< vector<int> > nodes(N+1, vector<int>(N+1, -1));
	h(N,nb,nodes);

	vector< vector<int> > best(N+1, vector<int>(N+1, -1));
	c(N,nb,nodes,best);

	int res = N+1;
	FOR(i,N) {
		int v = i+1;

		int cut = -1;
		if (nb[v].size() == 1) {
			cut = nodes[nb[v][0]][v]; // cortar todo
		} else if (nb[v].size() == 2) {
			cut = best[nb[v][0]][v] + best[nb[v][1]][v];
		} else {
			int m = N+1;
			FOR(j,nb[v].size()) {
				int jj = nb[v][j];
				for (size_t k = j+1; k < nb[v].size(); ++k) {
					int kk = nb[v][k];
					{
						int cutcut = N 
						- 1 // v
							- nodes[jj][v] - nodes[kk][v];
						cutcut += best[jj][v];
						cutcut += best[kk][v];
						if (m > cutcut)
							m = cutcut;
					}
				}
			}
			cut = m;
		}
		if (res > cut)
			res = cut;

	}
		

	return res;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int N;
		in >> N; assert(N >= 2);
		vector< pair<int,int> > e(N);
		FOR(i,N-1) in >> e[i].first >> e[i].second;

		int result = solve_case(N, e);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	//ifstream in("B-small-attempt0.in");
	//ofstream out("B-small-out.txt");

	ifstream in("B-large.in");
	ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
