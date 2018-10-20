#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
ll a[1000];
ll b[1000];
ll fn(ll num)//flipnumber
{
	int cnt = 0 ;
	while(num>0)
	{
	if(num%2 == 1)
	cnt++;
	num /= 2;
	}
	return cnt;
}

ll rb(string s , int l)//read binary
{
	ll ans = 0,k=0;
	for(int i=l-1;i>=0;i--)
	{
	ans += ((ll)(1<<k)*((ll)(s[i]-'0')));
	k++;
	}
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int k,t,n,l,i;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cout<<"Case #"<<k<<": " ;
		string str;
		cin>>n>>l;
		for(i=0;i<n;i++)
		{
			cin>>str;
			a[i] = rb(str,l);
		}
		
		for(i=0;i<n;i++)
		{
			cin>>str;
			b[i] = rb(str,l);
		}
		sort(a,a+n);
		sort(b,b+n);
		bool flag = false;
		for(int k=0;k<n;k++)
		{
			ll num = (b[0]^a[k]) ;
			int cnt=0;
			for(int q=0;q<n;q++)
			{
				if(binary_search(b,b+n,(a[q]^num)))
				cnt++;
			}
			if(cnt==n)
			{
				flag = true;
				cout << fn(num) << endl;
				break;
			}
		}
		if(!flag)
		cout << "NOT POSSIBLE" <<endl;
	}
	fclose (stdout);
	fclose (stdin);
	return 0;
}
