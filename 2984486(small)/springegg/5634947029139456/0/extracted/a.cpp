#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <set>
#define maxl 1000000000
#define maxn 5010
#define maxs 150
using namespace std;

typedef long long ll;

int m;

int getBool(const string &s1, const string &s2, bool same[]){
	int result = 0;
	for(int i = 0; i < m; ++i){
		same[i] = s1[i] == s2[i];
		result += (!same[i]);
	}
	return result;
}

string turn(const string &s, bool same[]){
	string result = "";
	for(int i = 0; i < s.size(); ++i) if(same[i]) result += s[i]; else result += (1 - (s[i] - '0') + '0');
	return result;
}

string a[155], b[155];
bool same[155];

void solve(){
	int n;
	set<string> ss;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
		ss.insert(b[i]);
	}
	
	int best = maxl;
	for(int i = 1; i <= 1; ++i)
		for(int j = 1; j <= n; ++j){
			int tmp = getBool(a[i], b[j], same);
			if(tmp >= best) continue;
			int k;
			for(k = 1; k <= n; ++k){
				if(!ss.count(turn(a[k], same))) break;
			}
			if(k > n) best = tmp;
		}
	if(best == maxl) cout << "NOT POSSIBLE" <<endl; else cout << best << endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}