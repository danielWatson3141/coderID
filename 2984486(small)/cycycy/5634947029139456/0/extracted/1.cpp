#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

long long a[50],b[50];
int ans;
long long aa[50];
map<long long,int> M;

int haha(long long a,long long b)
{
	int an=0;
	while (a>0 || b>0)
	{
		if (a % 2!=b % 2)
			an++;
		a/=2;
		b/=2;
	}
	return an;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	cin>>t;
	string s;
	for (int ii=0;ii<t;ii++)
	{
		int n,l;
		cin>>n>>l;
		for (int i=0;i<n;i++)
		{
			cin>>s;
			a[i]=0;
			for (int j=0;j<l;j++)
				a[i]=a[i]*2+s[j]-48;
		}
		for (int i=0;i<n;i++)
		{
			cin>>s;
			b[i]=0;
			for (int j=0;j<l;j++)
				b[i]=b[i]*2+s[j]-48;
		}
		ans=100;
		M.clear();
		for (int i=0;i<n;i++)
			M[a[0] xor a[i]]=1;
		for (int i=0;i<n;i++)
		{
			bool tf=true;
			for (int j=0;j<n;j++)
				if (!M.count(b[i] xor b[j]))
				{
					tf=false;
					break;
				}
			if (tf)
				ans=min(ans,haha(b[i],a[0]));
		}
		cout<<"Case #"<<ii+1<<": ";
		if (ans==100)
			cout<<"NOT POSSIBLE\n";
		else
			cout<<ans<<endl;
	}
}