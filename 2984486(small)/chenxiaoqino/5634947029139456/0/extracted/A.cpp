#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

long long outn[160];
long long reqn[160];
long long cmpn[160];

long long parseln(char s[50],int l)
{
	int i;
	long long ret=0;
	for(i=0;i<l;i++)
	{
		if(s[i]=='1')
			ret=ret+(1<<i);
	}
	return ret;
}

int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	int i,n,l;
	cin>>n>>l;
	char s[50];
	for(i=0;i<n;i++)
	{
		cin>>s;
		outn[i]=parseln(s,l);
		//cout<<outn[i]<<endl;
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		reqn[i]=parseln(s,l);
		//cout<<reqn[i]<<endl;
	}
	
	long long mask=0;
	long long bestmask=-1;
	int bestans=50;
	
	sort(&reqn[0],&reqn[n]);
	for(mask=0;mask<(1<<l);mask++)
	{
		memcpy(cmpn,outn,sizeof(cmpn));
		for(i=0;i<n;i++)
			cmpn[i]=cmpn[i] xor mask;
		sort(&cmpn[0],&cmpn[n]);
		//for(i=0;i<n;i++)
		//	cout<<cmpn[i];
		//for(i=0;i<n;i++)
		//	cout<<reqn[i];
		//cout<<endl;
		if(memcmp(cmpn,reqn,n*sizeof(cmpn[0]))==0)
			{
				//rec ans
				int ans=
				__builtin_popcount (mask);
				if(ans<bestans)
				{
					bestans=ans;
					bestmask=mask;
				}
			}
	}	
	
	cout<<"Case #"<<(ti+1)<<": ";
	if(bestans<49)
		cout<<bestans;
	else
		cout<<"NOT POSSIBLE";
	cout<<endl;
}
return 0;
}