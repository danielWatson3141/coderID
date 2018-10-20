#include <vector>
#include <numeric>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)		for(int i=(a),_b=(b);i<(_b);++i)
#define FORD(i,a,b)		for(int i=(a),_b=(b);i>(_b);--i)
#define pb			push_back
#define mp			make_pair
#define	all(c)			(c).begin(),(c).end()
#define	tr(c,i)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define	present(c,x)		((c).find(x) != (c).end())
#define	cpresent(c,x)		(find(all(c),x) != (c).end())
#define endl        '\n'

typedef long long			ll;
typedef unsigned long long	ull;
typedef unsigned char	 	byte;
typedef vector<int>			vi;
typedef pair<int, int>		pii;
typedef pair<ll, ll>		pll;
typedef vector<pii>			vpii;

const int MX = 25;

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen(argv[1],"r",stdin);
#endif
#ifndef ONLINE_JUDGE
	ifstream cin(argv[1]);
#endif
#if 1
	ofstream cout(argv[2]);
#endif
	ios :: sync_with_stdio(false);
	cin.tie(NULL);

	int T,n,l;
	cin >> T;
    FOR(t,1,T+1) {
        cin >> n >> l;
        string a[n];
        string b[n];
        FOR(i,0,n) cin >> a[i];
        FOR(i,0,n) cin >> b[i];
        sort(b,b+n);
        int p[n];
        string tmp[n];
        FOR(i,0,n) p[i] = i;
        int ans = -1;
        FOR(x,0,(1<<l)) {
            vi v;
            FOR(j,0,l) if ((1<<j)&x) v.pb(j);
            FOR(i,0,n) tmp[i] = a[i];
            FOR(i,0,n) FOR(j,0,v.size()) {
                if (tmp[i][v[j]] == '0') tmp[i][v[j]] = '1';
                else tmp[i][v[j]] = '0';
            }
            sort(tmp,tmp+n);
            bool ok = true;
            FOR(i,0,n) if (tmp[i] != b[i]) { ok = false; break; }
            if (ok) {
                if (ans == -1) ans = v.size();
                else ans = min(ans,(int)v.size());
            }
        }
        if (ans == -1) cout << "Case #" << t << ": NOT POSSIBLE" << endl;
        else cout << "Case #" << t << ": " << ans << endl;
    }
	return 0;
}
