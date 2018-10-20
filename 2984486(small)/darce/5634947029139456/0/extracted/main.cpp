#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <algorithm>  
using namespace std;

vector<unsigned long long> inData;
vector<unsigned long long> outData;
bool checkSame(vector<unsigned long long> data)
{
	bool res=true;
	int N=data.size();
	for(int i=0;i<N;i++)
	{
		if(data[i]!=outData[i])
		{
			res=false;
			break;
		}
	}
	return res;
}
int BitCount(long long input) 
{ 
	int nRet = 0; 
	while(input) 
	{ 
		input &= (input - 1); 
		nRet++; 
	} 
	return nRet; 
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("data.out","w",stdout);
	int T;
	int N,L;
	long long LL;
	cin>>T;
	string a;
	unsigned long long c;
	int minCount=50;
	int tempMin;
	for(int i=0;i<T;i++)
	{
		cin>>N>>L;
		LL=1<<L;
		inData.clear();
		outData.clear();
		minCount=50;
		for(int j=0;j<N;j++)
		{
			
			cin>>a;
			bitset<40> b(a);
			c=b.to_ullong();
			inData.push_back(c);
		}
		for(int j=0;j<N;j++)
		{

			cin>>a;
			bitset<40> b(a);
			c=b.to_ullong();
			outData.push_back(c);
		}
		sort(inData.begin(),inData.end());
		sort(outData.begin(),outData.end());
		for(c=0;c<LL;c++)
		{
			vector<unsigned long long> data=inData;
			for(int k=0;k<N;k++)
			{
				data[k]=data[k]^c;
			}
			sort(data.begin(),data.end());
			if(checkSame(data))
			{
				tempMin=BitCount(c);
				if(minCount>tempMin)
					minCount=tempMin;
			}

		}
		if(minCount==50)
		{
			cout<<"Case #"<<i+1<<": NOT POSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<i+1<<": "<<minCount<<endl;
		}

	}
	return 0;
}