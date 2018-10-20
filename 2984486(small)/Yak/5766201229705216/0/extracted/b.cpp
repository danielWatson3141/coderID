// gcc version 4.8.2 with -std=c++11

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iterator>

#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

#include <string>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#include <tuple>
#include <initializer_list>

#include <cmath>

// Boost library can be retrieved from http://www.boost.org/
// 1.52 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

#define RNG(v) (v).begin(), (v).end()
#define REP(v, e) for(UI v = 0U; v < e; ++v)
#define REP_(v, s, e) for(UI v = s; v < e; ++v)
#define REPV(v, e) for(v = 0; v < e; ++v)
#define REPV_(v, s, e) for(v = s; v < e; ++v)

using namespace std;

template<class Integer>
inline boost::iterator_range< boost::range_detail::integer_iterator<Integer> >
IR(Integer first, Integer  last)
{ return boost::irange(first, last); }

template<typename T>
class UnionFind
{
	typedef std::map<T, T> Parent;
	Parent m_parent;
	typedef std::map<T, int> Rank;
	Rank m_rank;
	struct IsParent
	{
		bool operator()(const typename Parent::value_type &v) const
		{
			return v.first == v.second;
		}
	};
public:
	T find_set(T t)
	{
		if(m_parent.count(t) == 0) {
			make_set(t);
		}
		return m_parent[t] == t ? t : (m_parent[t] = find_set(m_parent[t]));
	}
	// t1 and t2 should be root
	void union_set(T t1, T t2)
	{
		if(m_rank[t1] < m_rank[t2]) {
			m_parent[t1] = t2;
		} else if(m_rank[t1] > m_rank[t2]) {
			m_parent[t2] = t1;
		} else if(t1 != t2) {
			m_parent[t2] = t1;
			++m_rank[t1];
		}
	}
	void link(T t1, T t2) { union_set(find_set(t1), find_set(t2)); }
	void make_set(T t1)
	{
		m_parent.insert(std::make_pair(t1, t1));
	}
	int count_sets(void) const
	{
		return count_if(m_parent.begin(), m_parent.end(), IsParent());
	}
	// Iteration for roots
	template<typename F>
	void roots(F f) const
	{
	        typename Parent::const_iterator it_end = m_parent.end();
	        IsParent pred;
	        for(typename Parent::const_iterator it = m_parent.begin(); it != it_end; ++it) {
	                if(pred(*it)) f(*it);
	        }
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		UI N; cin >> N;
		vector<pair<int, int>> v(N-1);
		for(auto i: IR(0U, N-1)) {
			int x, y; cin >> x >> y; --x; --y;
			v[i] = make_pair(x, y);
		}
		auto result = N;
		for(auto i: IR(0U, 1U << N)) {
			auto v_ = v;
			UI temp = 0U;
			for(auto j: IR(0U, N)) { if( i & (1U << j)) ++temp; }
			vector<int> count(N);
			UnionFind<int> uf;
			for(auto &j : v_) {
				if(!(i & (1U << j.first)) && !(i & (1U << j.second))) {
					++count[j.first];
					++count[j.second];
					uf.link(j.first, j.second);
				}
			}
			if(uf.count_sets() != 1) continue;
			bool ok = true, look2 = false;
			int count0 = 0;
			for(auto &j : count) {
				if(j == 2) {
					if(look2) { ok = false; break; }
					else { look2 = true; }
				} else if(j == 0) {
					++count0;
				} else if(j != 1 && j != 3) { ok = false; break; }
			}
			if(ok && look2 && temp == count0) {
				result = min(result, temp);
			}
		}
        cout << "Case #" << casenum+1 << ": " << result << endl;
	}

	return 0;
}
