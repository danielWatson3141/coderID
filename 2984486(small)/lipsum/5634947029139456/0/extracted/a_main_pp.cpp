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

template<typename T>
T least_bit_number(T value)
{
	if(value == 0) { return 0; }
	return value & ~(value - 1);
}

template<typename T>
int msb(T value)
{
	int index = 0;
	while(value >>= 1) { ++index; }
	return index;
}

template<typename T>
int lsb(T value)
{
	int index = 0;
	while(value > 0 && !(value & 1)) { ++index; value >>= 1; }
	return index;
}

template<typename T>
int bit_count(T v)
{
	int count = 0;
	while(v > 0)
	{

		v &= v - 1;
		++count;
	}
	return count;
}

template<typename T>
T next_bit_subset(T superset, T i)
{
	return (i - 1) & superset;
}

template<typename T>
bool is_power_of_2(T value)
{
	if(value == 0) { return false; }
	return (value & (value - 1)) == 0;
}

template<typename T>
T round_up_to_power_of_2(T value)
{
	--v;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	++v;
	return v;
}

#define MAX_L 50
#define MAX_N 150

int solve(int n, int l, vector<bitset<MAX_L>>& initial, vector<bitset<MAX_L>>& ideal)
{
	for(int bits = 0; bits < (1 << l); ++bits)
	{
		REP(pos, l)
		{
			if((bits >> pos) & 1)
			{
				REP(k, n) { initial[k].flip(pos); }
			}
		}

		bool valid = true;
		FOREACH(ite, ideal)
		{
			if(find(initial.begin(), initial.end(), *ite) == initial.end())
			{
				valid = false;
				break;
			}
		}

		if(valid)
		{
			return bit_count(bits);
		}

		REP(pos, l)
		{
			if((bits >> pos) & 1)
			{
				REP(k, n) { initial[k].flip(pos); }
			}
		}
	}

	return -1;

}

void solve(istream& in, ostream& out)
{
	int count;
	in >> count;
	REP(i, count)
	{

		int n, l;
		in >> n >> l;
		vector<bitset<MAX_L>> initial;
		read(in, initial, n);
		vector<bitset<MAX_L>> ideal;
		read(in, ideal, n);

		int result = solve(n, l, initial, ideal);
		if(result == -1)
		{
			print_result(out, i, "NOT POSSIBLE");
		}
		else
		{
			print_result(out, i, result);
		}
	}

}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false);

	solve(cin, cout);
	return 0;
}

