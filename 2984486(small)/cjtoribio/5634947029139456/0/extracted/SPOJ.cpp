#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

typedef long long Long;
Long arr[200];
Long arr2[200];
int main() 
{
	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc <= TC;++tc)
	{
		int N,L;
		cin >> N >> L;
		for(int i = 0; i < N; ++i)
		{
		   arr[i] = 0;
		   string s; cin >> s;
		   for(int j = 0; j < s.size(); ++j)
			   arr[i] += (s[j]-'0') << (L-j-1);
		}
		for(int i = 0; i < N; ++i)
		{
		   arr2[i] = 0;
		   string s; cin >> s;
		   for(int j = 0; j < s.size(); ++j)
			   arr2[i] += (s[j]-'0') << (L-j-1);
		}
		map<Long,int> M;
		int ma = 0 , bId = L;
		for(int i = 0; i < N; ++i)
		{
		   for(int j = 0; j < N; ++j)
		   {
			   int t = arr[i] ^ arr2[j];
			   int b = ++M[t];
			   if(b > ma)
			   {
				   ma = b;
				   bId = __builtin_popcount(t);
			   }
			   else if(b == ma && bId > __builtin_popcount(t))
			   {
				   bId =  __builtin_popcount(t);
			   }
		   }
		}
		cout << "Case #"<< tc << ": ";
		if(ma != N)
		   cout << "NOT POSSIBLE" << endl;
		else
		   cout << bId << endl;
	}
    
}





/*
2 4
1 2 1 2
1 2 1 2





___ ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
         3   4           -3
         2   3           -2

1       n!
-  *  ------
k!    (n-k)!


 */

