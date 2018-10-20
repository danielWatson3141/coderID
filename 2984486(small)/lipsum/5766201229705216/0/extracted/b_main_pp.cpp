#include <iostream>
#include <sstream>
#include <iomanip>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <string>

#include <numeric>
#include <utility>
#include <functional>
#include <algorithm>
#include <complex>
#include <memory>

#include <cstdio>
#include <cstdlib>
#include <cassert>

#include <cmath>
#include <climits>
#include <cfloat>

#include <cctype>
#include <cstring>

using namespace std;

#define FOR(M_i, M_from, M_to)	for(int M_i = (M_from); M_i < (M_to); ++M_i)
#define REP(M_i, M_n)				FOR(M_i, 0, M_n)
#define FOREACH(M_ite, M_c) for(decltype(M_c.begin()) M_ite = M_c.begin(); M_ite != M_c.end(); ++M_ite)

template<typename CONTAINER_T>
void read(istream& in, CONTAINER_T& list, size_t n)
{
	for(size_t i = 0; i < n; ++i)
	{
		CONTAINER_T::value_type value;
		in >> value;
		list.push_back(value);
	}
};

template<typename T, typename INDEX_T = int>
struct t_indexed_value
{
	typedef t_indexed_value<T, INDEX_T> self; 
	typedef T		value_t;
	typedef INDEX_T	index_t;

	value_t value;
	index_t index;

	bool operator <(const self& obj) const { return value < obj.value; }
	bool operator ==(const self& obj) const { return value == obj.value; }
	bool operator !=(const self& obj) const { return !(*this == obj); }
};

template<typename FORWARD_ITE>
void write(ostream& out, FORWARD_ITE first, FORWARD_ITE last, const string& sep = " ")
{
	if(first != last) { out << *first; ++first; }
	while(first != last)
	{
		out << sep << *first;
		++first;
	}
	out << endl;
}

template<typename T>
void print_result(ostream& out, int index, const T& result)
{
	out << "Case #" << (index + 1) << ": " << result << endl;
}

class solver
{
private:

	vector<vector<int>> adj;
	int n;

public:
	solver(int _n, vector<pair<int, int>>& list) :  adj(_n, vector<int>())
	{
		n = _n;
		REP(i, n - 1)
		{
			adj[list[i].first].push_back(list[i].second);
			adj[list[i].second].push_back(list[i].first);
		}
	}

	int solve()
	{
		int min_count = INT_MAX;
		REP(i, n)
		{
			int count = calc_remove_count(i, -1);
			min_count = min(min_count, count);
		}
		return min_count;
	}

	int calc_remove_count(int root, int from)
	{

		int result = 0;
		switch(adj[root].size() - (from < 0 ? 0 : 1))
		{
		case 0:	
			result = 0;
			break;

		case 1:
			{
				int total = 0;
				REP(i, adj[root].size())
				{
					int index = adj[root][i];
					if(index == from) { continue; }
					calc_connected_size(index, root, total);
				}
				result = total;				
			}
			break;

		case 2:
			REP(i, adj[root].size())
			{
				int index = adj[root][i];
				if(index == from) { continue; }

				result += calc_remove_count(index, root);
			}
			break;

		default:
			{
				vector<pair<int, int>> list;
				REP(i, adj[root].size())
				{
					int index = adj[root][i];
					if(index == from) { continue; }
					list.push_back(make_pair(calc_remove_count(index, root), i));
				}
				sort(list.begin(), list.end());
				result = list[0].first + list[1].first;

				set<int> ignore;
				FOR(i, 2, list.size())
				{
					calc_connected_size(list[i].second, root, result);
				}
			}
		}

		return result;
	}

	void calc_connected_size(int index, int from, int& total)
	{
		++total;
		REP(i, adj[index].size())
		{
			int adj_index = adj[index][i];
			if(adj_index == from) { continue; }
			calc_connected_size(adj_index, index, total);
		}
	}

};

int solve(int n, vector<pair<int, int>>& list)
{
	solver solver(n, list);
	return solver.solve();
}

void solve(istream& in, ostream& out)
{
	int t;
	in >> t;
	REP(i, t)
	{
		int n;
		in >> n;
		vector<pair<int, int> > list(n - 1);
		REP(j, n - 1)
		{
			in >> list[j].first >> list[j].second;
			list[j].first--;
			list[j].second--;
		}

		print_result(out, i, solve(n, list));
	}	
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);
	solve(cin, cout);
	return 0;
}

