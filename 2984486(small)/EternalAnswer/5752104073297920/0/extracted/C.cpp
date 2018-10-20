#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>
#define int64 long long
#define Sort sort

using namespace std;

const int Maxn = 1010;
int a[Maxn];
int N;

int ABS(int x)
{
	if (x<0) return -x;
	return x;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	srand(time(0));
	int T;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		printf("Case #%d: ",ii);
		scanf("%d",&N);
		int cnt=0;
		for (int i=0;i<N;++i)
		{
			scanf("%d",&a[i]);
			for (int j=0;j<i;++j)
				if (a[j]>a[i]) ++cnt;
		}
		//if (cnt<=62437 || cnt>=437062) printf("GOOD\n");
		long double p = 0.00003*exp(-0.00003*cnt);
		long double p1 = 0.00003*exp(-0.00003*249750);
		double pp = (double)rand()/(double)RAND_MAX;
		 if (pp<=p/(p+p1)) printf("BAD\n");
		else printf("GOOD\n");
		/*{
			int p = rand()*rand() % 137363;
			if (p<=ABS(cnt-249750)-49950) printf("BAD\n");
			else printf("GOOD\n");
		}*/
	}
	
	return 0;
}