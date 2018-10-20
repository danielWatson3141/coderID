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

void solve()
{
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; ++i)
		cin>>a[i];
	long long good=0, bad=0;
	for(int i=0; i<n; ++i)
		if(a[i]==i)
		{
			if(i<n/2)
				good += (n-i)*1ll*(n-i);
			else
				bad += (i+1)*1ll*(i+1);
		}
	if(good>=bad)
		cout<<"GOOD"<<endl;
	else
		cout<<"BAD"<<endl;
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
