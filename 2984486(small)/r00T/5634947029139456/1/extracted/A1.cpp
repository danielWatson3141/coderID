using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>

typedef long long L;
typedef unsigned long long U;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

string str1[160];
string str2[160];
string str3[160];

main()
{
	int tc;
	cin>>tc;
	for(int t = 1;t<=tc;t++)
	{
		int n,l;
		cin>>n>>l;
		int li[l],lf[l];
		for(int i = 0;i<l;i++)
			li[i] = lf[i] = 0;
		for(int i = 0;i<n;i++)
		{
			cin>>str1[i];
			for(int j = 0;j<l;j++)
				li[j] += (str1[i][j] == '1');
		}
		for(int i = 0;i<n;i++)
		{
			cin>>str2[i];
			for(int j = 0;j<l;j++)
				lf[j] += (str2[i][j] == '1');
		}
		bool np = 0;
		for(int i = 0;i<l;i++)
		{
			if(li[i] != lf[i] && li[i]+lf[i] != n)
			{
				np = 1;
				break;
			}
		}
		if(np)
		{
			printf("Case #%d: NOT POSSIBLE\n", t);
			continue;
		}
		sort(str1,str1+n);
		int change[l];
		int mini = -1;
		for(int i = 0;i<n;i++)
		{
			int c = 0;
			for(int j = 0;j<l;j++)
			{
				change[j] = (str1[0][j] != str2[i][j]);
				c += change[j];
			}
			for(int j = 0;j<n;j++)
			{
				str3[j] = str2[j];
				for(int k = 0;k<l;k++)
				{
					if(change[k])
					{
						if(str3[j][k] == '0')
							str3[j][k] = '1';
						else
							str3[j][k] = '0';
					}
				}
			}
			sort(str3,str3+n);
			bool same = 1;
			for(int j = 0;j<n;j++)
			{
				if(str1[j] != str3[j])
				{
					same = 0;
					break;
				}
			}
			if(same)
			{
				if(mini == -1)
					mini = c;
				mini = min(mini,c);
			}
		}
		if(mini == -1)
			printf("Case #%d: NOT POSSIBLE***\n", t);
		else
			printf("Case #%d: %d\n", t, mini);
	}
}
