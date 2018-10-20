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

vi comp(string &a, string &b)
{
    vi v;
    FOR(i,0,a.length()) if (a[i] != b[i]) v.pb(i);
    return v;
}

char a[200][55];
char b[200][55];

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
        string tmp[n];
        FOR(i,0,n) scanf("%d",a[i]);
        FOR(i,0,n) scanf("%d",b[i]);
        FOR(i,0,n) cin >> b[i];
        sort(b,b+n);
        int ans = -1;
        FOR(i,0,n) FOR(j,0,n) {
            vi v = comp(a[i],b[j]);
            FOR(k,0,n) tmp[k] = a[k];
            FOR(ii,0,v.size()) {
                FOR(k,0,n) {
                    if (tmp[k][v[ii]] == '1') tmp[k][v[ii]] = '0';
                    else tmp[k][v[ii]] = '1';
                }
            }
            sort(tmp,tmp+n);
            bool ok = true;
            FOR(k,0,n) if (b[k] != tmp[k]) { ok = false; break; }
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
