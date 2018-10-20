#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
 
using namespace std;

long long string2ll(const string & s)
{
	long long result = 0;
	int n = s.length();
	for(int i=0; i<n; ++i)
		result = (result<<1) + (s[i]=='1');
	return result;
}

int cnt(long long x)
{
	int c = 0;
	while(x)
	{
		++c;
		x = x&(x-1);
	}
	return c;
}

bool check(long long mask, vector<long long> o, const vector<long long> & d)
{
	int n = o.size();
	for(int i=0; i<o.size(); ++i)o[i]^=mask;
	sort(o.begin(), o.end());
	for(int i=0; i<n; ++i)
		if(o[i]!=d[i])
		{
			return false;
			break;
		}
	return true;
}

void solve()
{
	int n, l;
	cin>>n>>l; 
	string s;
	vector<long long> o, d;
	for(int i=0; i<n; ++i)
	{
		cin>>s; o.push_back(string2ll(s));
	}

	for(int i=0; i<n; ++i)
	{
		cin>>s; d.push_back(string2ll(s));
	}

	sort(d.begin(), d.end());

	int best = 1000000;

	vector<long long> msks;
	for(int i=0; i<n; ++i)
		msks.push_back(d[0]^o[i]);

	for(long long i=0; i<msks.size(); ++i)
	{
		if(check(msks[i], o, d))
		{
			best = min(best, cnt(msks[i]));
		}
	}

	if(best==1000000)cout<<"NOT POSSIBLE"<<endl;
	else cout<<best<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef GRANDVIC_DEBUG
	//freopen("i:/input.txt", "rt", stdin);
#endif
	int T; cin>>T;
	for(int t=1; t<=T; ++t)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}

	return 0;
} 
