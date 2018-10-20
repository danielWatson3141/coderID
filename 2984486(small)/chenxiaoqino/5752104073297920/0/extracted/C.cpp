#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int a[4]={1,2,3,4};

int findpermu(int a[], int lv)
{
int b[4];

if(lv>=4){
	for(int i=0;i<4;i++)cout<<a[i];
	cout<<endl;
	return 1;
}

for(int i=0;i<4;i++)
	{
		memcpy(b,a,sizeof(b));
		int t;
		t=b[lv];b[lv]=b[i];b[i]=t;//swap(&b[lv],&b[i]);
		findpermu(b,lv+1);
	}
return 0;
}

long eval[121];
long ceval[121];

int main()
{


int T,ti;
cin>>T;

for(ti=0;ti<T;ti++)
{
	int n;
	cin>>n;
	int per[1000];
	for(int i=0;i<n;i++)cin>>per[i];
	long ev=0;
	for(int i=0;i<n;i++)
	ev+=abs(per[i]-i);
	eval[ti]=ev;
	//cout<<"ev@"<<ti<<" : "<<ev<<endl;
}
memcpy(&ceval,&eval,sizeof(eval));
sort(&ceval[0],&ceval[T]);

long crit1=ceval[(T)/4],crit2=ceval[T/2+(T)/4];
//cout<<ceval;
//cout<<crit1<<":"<<crit2<<endl;

for(ti=0;ti<T;ti++)
{
	cout<<"Case #"<<(ti+1)<<": ";
	if(eval[ti]>=crit2||eval[ti]<crit1)
	{
		cout<<"GOOD";
	}
	else cout<<"BAD";
	cout<<endl;
}
return 0;
}