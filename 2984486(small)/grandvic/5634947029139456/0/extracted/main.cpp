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
	vector<int> ho(l), hd(l);
	vector<long long> o, d;
	string s;
	for(int i=0; i<n; ++i)
	{
		cin>>s; o.push_back(string2ll(s));
		for(int j=0; j<l; ++j)
		{
			if(s[j]=='1')ho[j]++;
		}
	}

	for(int i=0; i<n; ++i)
	{
		cin>>s; d.push_back(string2ll(s));
		for(int j=0; j<l; ++j)
		{
			if(s[j]=='1')hd[j]++;
		}
	}

	//long long xmask = 0;

	//bool possible = true;
	//for(int i=0; i<l; ++i)
	//{
	//	if(ho[i]==hd[i])continue;
	//	if(ho[i]==(n - hd[i]))
	//	{
	//		xmask = xmask | (1ll<<i);
	//		++cnt;
	//	}
	//	else if(ho[i]!=hd[i])
	//	{
	//		possible = false;
	//		break;
	//	}
	//}

	//if(possible)
	//{
	//	for(int i=0; i<n; ++i)
	//		o[i] ^= xmask;
	//}

	sort(d.begin(), d.end());

	int best = 100;
	long long mmax = (1ll<<l);
	for(long long i=0; i<mmax; ++i)
	{
		if(check(i, o, d))
		{
			best = min(best, cnt(i));
		}
	}

	if(best==100)cout<<"NOT POSSIBLE"<<endl;
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
