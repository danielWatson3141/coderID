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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define rep(i,n)   for(int i=0;i<n;i++)
#define rrep(i,n)  for(int i=n-1;i>=0;i--)
int a[1000];
int b[1000];
int countt(int nm)
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
int binn(string s , int l)
{
	int ans = 0,k=0;
	for(int i=l-1;i>=0;i--)
	{
		ans += (1<<k)*(s[i]-'0');
		k++;
	}
	return ans;
}
int main()
{
	int tt,t,n,l;
	cin>>tt;
	for(int t=1;t<=tt;t++){
		cout<<"Case #"<<t<<": " ; 
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
		for(int nm=0;nm<(1<<l);nm++){
			int cnt=0;
			for(int q=0;q<n;q++){
				if(binary_search(b,b+n,(a[q]^nm)))
					cnt++;
			}
			if(cnt==n){
					bl = true;
					cout << countt(nm) << endl;
					break;
			}
		}
		if(!bl)
			cout << "NOT POSSIBLE" <<endl;
	}
	return 0;
}
				
			
