#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std ;

int n, L ;
string a[200] ;
string b[200] ;
string test[200] ;
string x ;

int best(int old, int newer)
{
	if(old==-1)
		return newer ;
	return (old<newer) ? old : newer ;
}

int flip(const string &a, const string &b)
{
	int out = 0 ;
	x = "" ;
	for(int i=0;i<L;i++)
		if(a[i]==b[i])
			x += "0" ;
		else
		{
			out++ ;
			x += "1" ;
		}
	return out ;
}

bool fit()
{
	for(int i=0;i<n;i++)
	{
		test[i] = "" ;
		for(int j=0;j<L;j++)
			if(x[j]=='1')
				test[i] += 1-(a[i][j]-'0')+'0' ;
			else
				test[i] += a[i][j] ;
	}
	sort(test, test+n) ;
	for(int i=0;i<n;i++)
		if(test[i]!=b[i])
			return false ;
	return true ;
}

int main(void)
{
	int tc ;
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		cin >> n >> L ;
		for(int i=0;i<n;i++)
			cin >> a[i] ;
		for(int i=0;i<n;i++)
			cin >> b[i] ;
		sort(b, b+n) ;
		int ans = -1 ;
		for(int i=0;i<n;i++)
		{
			int cur = flip(a[0], b[i]) ;
			if(fit())
				ans = best(ans, cur) ;
		}
		if(ans==-1)
			printf("Case #%d: NOT POSSIBLE\n",c) ;
		else
			printf("Case #%d: %d\n",c,ans) ;
	}
	
	return 0 ;
}
