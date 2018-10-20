#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
pair<long long, int> lldiff(long long a, long long b, int len)	//Returns the diff-ed string 
{
	long long c=0;
	int t=0;
	for(int i=0; i<=len; i++)
	{
		if(a&((long long)(1)<<i)!=b&((long long)(1)<<i))
		{
			c+=(long long)(1)<<i;
			t++;
		}
	}
	return make_pair(c, t);
}
long long lladd(long long a, long long b, int len)
{
	long long c=a;
	for(int i=0; i<=len; i++)
	{
		if(b&((long long)(1)<<i))
		{
			if(a&((long long)(1)<<i))
				c-=((long long)(1)<<i);
			else
				c+=((long long)(1)<<i);
		}
	}
	return c;
}
int main()
{
	//Match N binary strings to N other binary strings with binary transformations
	//Non-exponential solution: for each outlet, for each device, what is the transformation?
	//Evaluate transformation size (number of bits which are "1").
	//For each transformation (n^2): Does this create a mapping outlets->devices?(n^2)
	//Total: n^4, probably all right for n=150. It's probably better if I use a set to check the mapping.
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
	{
		int N, L;
		int mincost=1000;
		cin>>N>>L;
		vector<long long> outlets, devices;
		vector<pair<long long, int> > masks;
		char tc;
		long long tll;
		string tstr;
		set <long long> device_set;
		//Can store the binary strings in long long type
		for(int i=0; i<N; i++)
		{
			cin>>tstr;
			tll=0;
			for(int j=0; j<L; j++)
			{
				tll*=2;
				tll+=tstr[j]-'0';
			}
			outlets.push_back(tll);
		}
		for(int i=0; i<N; i++)
		{
			cin>>tstr;
			tll=0;
			for(int j=0; j<L; j++)
			{
				tll*=2;
				tll+=tstr[j]-'0';
				
			}
			devices.push_back(tll);
			device_set.insert(tll);
		}
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				masks.push_back(lldiff(outlets[i], devices[j], L));
			}
		}//We now have all the masks to be checked.
		sort(masks.begin(), masks.end());
		for(int i=0; i<masks.size(); i++)
		{
			//Since all the devices are different, we just need to check that each outlet has a device.
			bool isSeen=true;
			for(int j=0; j<outlets.size(); j++)
			{
				long long masked_outlet=lladd(outlets[j], masks[i].first, L);
				if(device_set.find(masked_outlet)==device_set.end()){
					isSeen=false;
					}
			}
			if(isSeen)
			{
				mincost=min(mincost, masks[i].second);
			}
		}
		if(mincost<1000)
			cout<<"Case #"<<t+1<<": "<<mincost<<endl;
		else
			cout<<"Case #"<<t+1<<": NOT POSSIBLE"<<endl;
	}
	
	
	return 0;
}