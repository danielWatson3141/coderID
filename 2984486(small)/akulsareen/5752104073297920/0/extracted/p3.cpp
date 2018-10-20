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
int main()
{
	freopen("cs.in","r",stdin);
	freopen("c_small.out","w",stdout);
	int t;
	int goodc=0,badc=0;
	scanf("%d",&t);
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		int n;
		scanf("%d",&n);
		int A[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&A[i]);
		}
		int count=0;
		for (int i = n/2; i < n; ++i)
		{
			if(A[i]<=n/2)
				count++;
		}
		if(count>240)
			printf("Case #%d: GOOD\n",test_case);
		else
			printf("Case #%d: BAD\n",test_case);
	}
	return 0;
}