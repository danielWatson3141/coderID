
//IamAwesome
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#include <ctype.h>
#include <utility>
#include <cstdlib>
#include <functional>
#include <numeric>


using namespace std;

#define LL long long
#define linf 998877665544332211ll
#define inf 987654321ll
#define MOD 1000000007ll
#define ADD(v) accumulate(v.begin(),v.end(), 0)
#define PRO(v) accumulate(v.begin(),v.end(), 1,multiplies <int>())
LL POS(LL x) { if (x > 0)  return x; else return 0; }
#define maxe(v) max_element(v.begin(),v.end())
#define mine(v) min_element(v.begin(),v.end())
#define rep(k,a,b) for(int k=(a); k < (b); ++k)
#define per(k,a,b) for(int k=(b-1); k >= (a); --k)
#define repg(k,ctnr) for(auto k=ctnr.begin();k!=ctnr.end();k++)
#define all(ctnr) (ctnr).begin(),(ctnr).end()

struct ysh {
	long long z, y, x;
	ysh() {}
	ysh(long long z, long long y, long long x) : z(z), y(y), x(x) {}
	ysh operator + (const ysh &p) const { return ysh(z + p.z, y + p.y, x + p.x); }
	ysh operator - (const ysh &p)  const { return ysh(z - p.z, y - p.y, x - p.x); }
	ysh operator * (long long con)     const { return ysh(z*con, y*con, x*con); }
	ysh operator / (long long con)     const { return ysh(z / con, y / con, x / con); }
	bool operator<(const ysh &rhs) const { return make_pair(z, make_pair(y, x)) < make_pair(rhs.z, make_pair(rhs.y, rhs.x)); }
	bool operator==(const ysh &rhs) const { return make_pair(z, make_pair(y, x)) == make_pair(rhs.z, make_pair(rhs.y, rhs.x)); }
};
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
//vector<string> vs; 
vector<string> vs2;
int p;
LL find(int pos, vector<string> vs){
	sort(vs.begin(), vs.end());
	if (pos>1){
		int flag = 0;
		rep(i,0,pos){
			rep(j, 0, vs.size()){
				if (vs[j][i] != vs2[j][i]){
					return 1000000000;
				}
			}
		}
	}
	if (pos == p){
		if (vs == vs2){
			return 0;
		}
		else return 1000000000;
	}
	LL ans = 1000000000;
	if (vs == vs2)return 0;
	ans = min(ans, find(pos + 1,vs));
	for (int i = 0; i < vs.size(); i++){
		if (vs[i][pos] == '0'){
			vs[i][pos] = '1';		
		}
		else if (vs[i][pos] == '1'){
			vs[i][pos] = '0';
		}
	}
	ans=min(ans,find(pos + 1,vs)+1);
	return ans;
}
int main() {
	int t;
	cin >> t;
	for (int g = 1; g <= t; g++){
		LL n, l;
		LL sm, cnt, mx, mn;
		LL ans=0;
		cin >> n >> l;
		p = l;
		vector<string> v(n),v2(n);
		rep(i, 0, n){
			cin >> v[i];
		}
		rep(i, 0, n){
			cin >> v2[i];
		}
		vector<string> vs;
		vs = v;
		vs2 = v2;
		sort(vs2.begin(), vs2.end());
		ans=find(0,vs);
		if (ans >= 1000000000){
			cout << "Case #" << g << ": " << "NOT POSSIBLE" << endl;
			continue;
		}
		else
		cout << "Case #" << g << ": " << ans << endl;
	}

	return 0;
}