#include <stdio.h>
#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>

#define f(i,n) for(int i =0; i <n;i++)

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	f(t,T)
	{
		int n;
		int nums[1000];
		scanf("%d",&n);
		f(i,n)
			scanf("%d",nums+i);
	/*	double prob = 1;
		int loc[1000];
		f(i,n)
		{
			loc[i] = i;
		}

		bool isbad = false;
		f(i,n)
		{
			int toget = nums[i];
			if(loc[toget]<i)
			{
				isbad = true;
				break;
			}

			loc[i] = toget;
		}
*/
		
		if(rand()%100<=50)
			printf("Case #%d: BAD\n",t+1);
		else
			printf("Case #%d: GOOD\n",t+1);
	}

	return 0;
}
