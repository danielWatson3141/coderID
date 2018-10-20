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
inline auto
IR(Integer first, Integer  last) -> decltype(boost::irange(first, last))
{ return boost::irange(first, last); }

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		ULL N, L; cin >> N >> L;
		vector<ULL> outlet(N); for(auto &v : outlet) {
			string s;
			cin >> s;
			for(auto i: IR(0ULL, L)) {
				v += (s[i] - '0') << (L - 1 - i);
			}
		}
		vector<ULL> spec(N); for(auto &v : spec) {
			string s;
			cin >> s;
			for(auto i: IR(0ULL, L)) {
				v += (s[i] - '0') << (L - 1 - i);
			}
		}
		ULL result = L + 1;
		for(ULL i : IR(0ULL, (1ULL << L))) {
			vector<ULL> outlet_(outlet);
			ULL count = 0;
			for(auto j: IR(0ULL, L)) { if(i & (1ULL << j)) { ++count; } }
			for(auto j: IR(0ULL, N)) { outlet_[j] ^= i; }
			bool ok = true;
			for(auto ii : IR(0ULL, N)) {
				bool ok_ = false;
				for(auto jj : IR(0ULL, N)) {
					if(outlet_[jj] == spec[ii]) {
						ok_ = true;
						break;
					}
				}
				if(!ok_) { ok = false; break; }
			}
			if(ok) { result = min(result, count); }
		}
        if(result == L + 1) {
        	cout << "Case #" << casenum+1 << ": " << "NOT POSSIBLE" << endl;
        } else {
        	cout << "Case #" << casenum+1 << ": " << result << endl;
        }
	}

	return 0;
}
