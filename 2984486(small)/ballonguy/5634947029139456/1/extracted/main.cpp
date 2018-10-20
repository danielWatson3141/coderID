#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
#include<sstream>
#include<ctime>
using namespace std;

typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
const int inf = 1000000000;
const int MOD = 1000000007;
const double pi = acos(-1.0);

string s[1111], w[1111], ss[1111];

void get() {
	int n, l;
	cin >> n >> l;
	FOR(i,1,n)
		cin >> ss[i];
	FOR(i,1,n)
		cin >> w[i];
	sort(w + 1, w + n + 1);
	sort(ss + 1, ss + n + 1);
	int ans = inf;
	FOR(i,1,n)
		FOR(j,1,n)
		{
			int cur = 0;
			FOR(i,1,n)
				s[i] = ss[i];
			FOR(pos,0,l-1)
				if (s[i][pos] != w[j][pos]) {
					cur++;
					FOR(t,1,n)
						s[t][pos] = '1' + '0' - s[t][pos];
				}
			sort(s+1, s+n+1);
			bool can=true;
			FOR(t,1,n) if(s[t]!=w[t]) can=false;
			if(can)
				ans=min(ans, cur);
		}
	if(ans>=inf) cout<<"NOT POSSIBLE"<<endl;else
		cout<<ans<<endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	FOR(tt,1,t)
	{
		cout << "Case #" << tt << ": ";
		get();
	}
}
