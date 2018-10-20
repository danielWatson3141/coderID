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
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
#define rep(i,n)   for(int i=0;i<n;i++)
#define rrep(i,n)  for(int i=n-1;i>=0;i--)
LL a[1000];
LL b[1000];
LL countt(LL nm)
{
	int cnt = 0 ;
	while(nm>0)
	{
		if(nm%2 == 1)
			cnt++;
		nm /= 2;
	}
	return cnt;
}
LL binn(string s , int l)
{
	LL ans = 0,k=0;
	for(int i=l-1;i>=0;i--)
	{
		ans += ((LL)(1<<k)*((LL)(s[i]-'0')));
		k++;
	}
	return ans;
}
int main()
{
        //freopen("input.in","r",stdin);
        //freopen("out.out","w",stdout);
	int tt,t,n,l;
	cin>>tt;
	for(int t=1;t<=tt;t++)
        { 
		string str;
		cin>>n>>l;
		rep(i,n){
			cin>>str;
			a[i] = binn(str,l);
		}
		sort(a,a+n);
		rep(i,n){
			cin>>str;
			b[i] = binn(str,l);
		}
		sort(b,b+n);
		bool bl = false;
		for(int k=0;k<n;k++)
		{
			LL nm = (b[0]^a[k]) ;
			int cnt=0;
			for(int q=0;q<n;q++){
				if(binary_search(b,b+n,(a[q]^nm)))
					cnt++;
			}
			if(cnt==n){
					bl = true;
					cout<<"Case #"<<t<<": "<<countt(nm) << endl;
					break;
			}
		}
		if(!bl)
			cout<<"Case #"<<t<<": "<<"NOT POSSIBLE" <<endl;
	}
	return 0;
}
