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
#include <limits>
#include <cstring>

using namespace std;


int N,L;
vector<string> v1,v2;


bool comp(string s1, string s2)
{
	if(s1.compare(s2) <=0)
		return true;
	else 
		return false;
}

int getMin()
{
	// printf("N = %d\n",N );
	// printf("L = %d\n",L);
	vector<string> t1,t2;
	vector<bool> lvec;
	lvec.clear();
	lvec.resize(L);
	int count = 0;
	int mn = 10000;

	for(int i = 0 ;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			// printf("i = %d j = %d\n",i,j );
			lvec.clear();
			lvec.resize(L);
			t1.clear();
			t2.clear();
			count = 0;
			if(v1[i].compare(v2[j]))
			{
				for(int l = 0;l<L;l++)
				{
					if(v1[i][l] != v2[j][l])
					{
						count++;
						 lvec[l] = true;
						// printf("%c",lvec[l] );
						
					}
					// cout<<lvec[l];
				}
				// printf("\n");
			}
			for(int k = 0;k<N;k++)
			{
				if(k!=i)
					t1.push_back(v1[k]);
			}
			if(count)
			{
				for(int k = 0;k<t1.size();k++)
				{
					for(int l = 0;l<L;l++)
					{
						if(lvec[l])
							t1[k][l] = (t1[k][l]=='0') ? '1' : '0';
					}
				}
			}
			for(int k = 0;k<N;k++)
			{
				if(k!=j)
					t2.push_back(v2[k]);
			}
			sort(t1.begin(),t1.end(),comp);
			sort(t2.begin(),t2.end(),comp);
			for(int k = 0;k<t1.size();k++)
			{
				if(t1[k].compare(t2[k]))
				{
					count = -1;
					break;
				}
			}
			if(count == -1)
				continue;
			else
				mn = min(mn,count);
		}
	}
	return mn;
}
int main()
{
	int T;
	scanf("%d",&T);

	for(int t=1;t<=T;t++)
	{
		scanf("%d %d",&N,&L);
		v1.clear();
		v1.resize(N);
		v2.clear();
		v2.resize(N);
		for(int i = 0;i<N;i++)
			cin>>v1[i];
		for(int i = 0;i<N;i++)
			cin>>v2[i];
		// printf("%c\n", );
		// cout<<v2[1]<<"AND"<<v2[2]<<endl;
		int ans = getMin();
		if(ans > 40 )
			printf("Case #%d: NOT POSSIBLE\n",t );
		else
			printf("Case #%d: %d\n",t,ans );
	}
	return 0;
}