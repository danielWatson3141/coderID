#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <bitset>
#include <assert.h>
#include <string.h>
 
using namespace std;
 
#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define IFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define FORD(i, a, b, c) for(int i=(a); i<(b); i+=(c))
 
#define SS ({int x;scanf("%d", &x);x;})
#define SI(x) ((int)x.size())
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a, b)
#define SORT(a) sort(a.begin(),a.end())
#define ITER(it,a) for(typeof(a.begin()) it = a.begin(); it!=a.end(); it++)
#define ALL(a) a.begin(),a.end()
#define INF 1000000000
#define V vector
#define S string
#define FST first
#define SEC second
typedef V<int> VI;
typedef V<S> VS;
typedef long long LL;
typedef pair<int, int> PII;

V<string> find(V<string> v, VI a)
{
	V<string> res;
	for(int i=0;i<v.size();i++)
	{
		string temp = v[i];
		for(int j=0;j<a.size();j++)
		{
			if(temp[a[j]] == '0')temp[a[j]] = '1';
			else temp[a[j]] = '0';
		}
		res.PB(temp);
	}
	return res;
}

int main()
{
	LL ite;
	int ans;
	cin>>ite;
	for(LL it = 1; it <= ite; it++)
	{
		ans = 999999;
		map<string, int> mp;
		vector<string> v, a, res;
		string temp;
		LL n, l;
		cin>>n>>l;
		REP(i, n)
		{
			cin>>temp;
			v.PB(temp);
		}
		REP(i, n)
		{
			cin>>temp;
			a.PB(temp);
		}
		int bitcount = 0, pos = -1;
		bool flag = false;
		sort(v.begin(), v.end());
		sort(a.begin(), a.end());
		for(int i=0;i<n;i++)
		{
			VI change;
			flag = false;
			for(int j=0;j<l;j++)
			{
				if(v[i][j] == a[0][j])continue;
				change.PB(j);
			}
			res = find(v, change);
			sort(res.begin(), res.end());
			REP(j, n)
			{
				if(a[j] == res[j])continue;
				flag = true;
				break;
			}
			if(!flag)
			{
				int res = change.size();
				ans = min(ans, res);
			}
		}
		if(ans == 999999)cout<<"Case #"<<it<<": NOT POSSIBLE"<<endl;
		else cout<<"Case #"<<it<<": "<<ans<<endl;
	}	
	return 0;
}