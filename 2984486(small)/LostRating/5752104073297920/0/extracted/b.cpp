#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <ctime>
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long int64;

#define mp make_pair
#define PII pair<int, int>
#define pb push_back
#define sz(X) ((int)((X).size()))

#define x first
#define y second

const int N = 100005;
const double eps = 1e-8;
const int mod = 1000000007;

int n, m, a[1005], v[1005];
bool ans[1005];
vector<pair<int, int> > b;

int cal()
{
    for (int i = 0; i < n; ++i)
        v[i] = 0;
    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        ret += (a[i] < i);
    }
    return ret;
}

void work(int task)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    //cerr << cal() << endl;
    b.pb(mp(cal(), task));
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("c.in","r",stdin);
		freopen("c.out","w",stdout);
	#endif
	int task;
	cin >> task;
	for (int i = 1; i <= task; ++i)
	{
	    work(i);
	}
    sort(b.begin(), b.end());
    for (int i = 0; i < task / 2; ++i)
        ans[b[i].second] = true;
    int cnt = 0;
    for (int i = 1; i <= task; ++i)
    {
	    cout << "Case #";
	    cout << i;
	    cout << ": ";
	    if (!ans[i]) cout << "GOOD" << endl;
	    else cout << "BAD" << endl;
	    if (i <= task/2 && !ans[i])++cnt;
	    if (i>task/2 && ans[i])++cnt;
    }
    cerr<<cnt<<endl;
	return 0;
}
