#include <functional>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <utility>
#include <list>
#include <cassert>
#include <sstream>

using namespace std;

#define SWAP(a,b) do{auto k=a; a=b; b=k;}while(0)
#define inf 987654321
#define infl 10000000000000000000ll
#define REP(k,a,b) for(auto k=(a); k < (b); ++k)
#define PER(k,a,b) for(auto k=(b-1); k >= (a); k--)
#define SUM(v) accumulate(v.begin(), v.end(), 0)
#define PROD(v) accumulate(v.begin(), v.end(), 1, multiplies<long long>())
#define MAX(v) max_element(v.begin(), v.end())
#define MIN(v) min_element(v.begin(), v.end())
typedef long long LL;
typedef vector<long long> VI;

LL POS(LL x) { if (x>0)  return x; else return 0; }

struct ele {
	long double z, y, x;
	ele() {}
	ele(long double z, long double y, long double x) : z(z), y(y), x(x) {}
	ele operator + (const ele &p) const { return ele(z + p.z, y + p.y, x + p.x); }
	ele operator - (const ele &p)  const { return ele(z - p.z, y - p.y, x - p.x); }
	ele operator * (long double con)     const { return ele(z*con, y*con, x*con); }
	ele operator / (long double con)     const { return ele(z / con, y / con, x / con); }
	bool operator<(const ele &rhs) const { return make_pair(z, make_pair(y, x)) < make_pair(rhs.z, make_pair(rhs.y, rhs.x)); }
	bool operator==(const ele &rhs) const { return make_pair(z, make_pair(y, x)) == make_pair(rhs.z, make_pair(rhs.y, rhs.x)); }
};

template < class T >
inline ostream& operator << (ostream& os, const vector<T>& v){
	for (vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
		os << *ii << " ";
	os << '\b';
	return os;
}
template < class T >
inline istream& operator>> (istream& os, vector<T>& v){
	for (vector<T>::iterator ii = v.begin(); ii != v.end(); ++ii)
		os >> (*ii);
	return os;
}
vector<string> _v, _v2;
int find(int pos, vector<string> v){
	if (pos == _v[0].size())
	{
		sort(v.begin(), v.end());
		sort(_v2.begin(), _v2.end());
		if (v == _v2){
			return 0;
		}
		else {
			return inf;
		}
	}
	sort(v.begin(), v.end());
	int ans = inf;
	int fl = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i][pos] != _v2[i][pos]){
			fl = 1;
		}
	}
	if (fl == 0){
		ans = min(ans, find(pos + 1, v));
	}
	for (int i = 0; i < _v.size(); i++){
		v[i][pos] = (v[i][pos] - '0' + 1) % 2 + '0';
	}
	sort(v.begin(), v.end());
	 fl = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i][pos] != _v2[i][pos]){
			fl = 1;
		}
	}
	if (fl == 0){
		ans = min(ans, find(pos + 1, v) + 1);
	}
	return ans;
}
int main()
{
	long long n, m;
	int t;
	cin >> t;
	for (int x = 1; x <= t; x++){
		cout << "Case #" << x << ": ";
		cin >> n >> m;
		vector<string> v(n), v2(n);
		cin >> v>>v2;
		sort(v2.begin(), v2.end());
		_v = v;
		_v2 = v2;
		int a = find(0, v);
		if (a >= inf){
			cout << "NOT POSSIBLE" << endl;
		}
		else {
			cout << a << endl;;
		}
	}
	return 0;
}