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

int cnt[1000][1000] ;

int main(void)
{
	int tc ;
	
	tc = 500000 ;
	
	for(int c=1;c<=tc;c++)
	{
		int arr[1000] ;
		for(int i=0;i<1000;i++)
			arr[i] = i ;
		for(int i=0;i<1000;i++)
		{
			int r = rand()%1000 ;
			swap(arr[i],arr[r]) ;
		}
		for(int i=0;i<1000;i++)
			cnt[i][arr[i]]++ ;
	}
	
	cin >> tc ;
	
	for(int c=1;c<=tc;c++)
	{
		int n ;
		int arr[1000] ;
		cin >> n ;
		for(int i=0;i<n;i++)
			cin >> arr[i] ;
		double prob = 1 ;
		for(int i=0;i<1000;i++)
			prob *= ((double)cnt[i][arr[i]])/500 ;
		
		if(prob>0.71)
			printf("Case #%d: BAD\n",c) ;
		else
			printf("Case #%d: GOOD\n",c) ;
	}
	
	return 0 ;
}
