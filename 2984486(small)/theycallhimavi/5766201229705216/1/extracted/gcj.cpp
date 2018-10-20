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
vector<list<int> > adj;
int min = 0;
vector<bool> vis;
int find(int root, bool isr){
	vis[root] = 1;
	if (!isr && adj[root].size() == 1){
		return 1;
	}
	if (isr && adj[root].size() == 0){
		return 1;
	}
	if (adj[root].size() + isr < 3){
		return 1;
	}
	vector<int> answers(adj.size() - 1);
	for (auto it = adj[root].begin(); it!= adj[root].end(); it++){
		if (!vis[*it]){
			answers.push_back(find(*it, 0));
		}
	}
	sort(answers.rbegin(), answers.rend());
	int ans = answers[0] + answers[1]+1;
	return ans;
}
int main()
{
	long long n, m;
	int t;
	cin >> t;
	for (int x = 1; x <= t; x++){
		cout << "Case #" << x << ": ";
		cin >> n;
		vector<list<int> > v(n);
		for (int i = 0; i < n-1; i++){
			int a, b;
			cin >> a >> b;
			v[a - 1].push_back(b - 1);
			v[b - 1].push_back(a - 1);
		}
		adj = v;
		int ans = 0;
		for (int i = 0; i < n; i++){
			vis = vector<bool>(n, 0);
			int a =find(i, 1);
	//		cout << a;
			ans = max(ans, a);
		}
		cout << n-ans << endl;
	}
	return 0;
}