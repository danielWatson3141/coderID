#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
int n,l,ans;
vector <string> reqd;
void recursor(vector <string> A,int depth,int used)
{
	if(depth==l)
	{
		sort(A.begin(), A.end());
		if(A==reqd)
		{
			ans=min(ans,used);
		}
		return;
	}
	recursor(A,depth+1,used);
	for (int i = 0; i < n; ++i)
	{
		if(A[i][depth]=='1')
			A[i][depth]='0';
		else
			A[i][depth]='1';
	}
	recursor(A,depth+1,used+1);
}
int main()
{
	freopen("as.in","r",stdin);
	freopen("a_small.out","w",stdout);
	int t;
	cin>>t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		cin>>n>>l;
		vector <string> A(n);
		reqd.clear();
		reqd.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>reqd[i];
		}
		sort(reqd.begin(), reqd.end());
		ans=100000;
		recursor(A,0,0);
		if(ans<10000)
			printf("Case #%d: %d\n",test_case,ans);
		else
			printf("Case #%d: NOT POSSIBLE\n",test_case);
	}
	return 0;
}