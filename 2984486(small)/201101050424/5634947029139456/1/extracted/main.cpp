#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=200;
int N,L;
string s1[maxn],s2[maxn];
bool change[50];

bool judge()
{
	int i,j;
	string ts[maxn];
	for(i=0;i<N;i++)
	{
		ts[i]="";
		for(j=0;j<L;j++)
		{
			if(change[j])
			{
				ts[i]+=s1[i][j]^1;
			}
			else
			{
				ts[i]+=s1[i][j];
			}
		}
	}

	sort(ts,ts+N);

	for(i=0;i<N;i++)
	{
		if(ts[i]!=s2[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	int i,j,k;
	int cc=0;
	while(T--)
	{
		cin>>N>>L;
		for(i=0;i<N;i++)
		{
			cin>>s1[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>s2[i];
		}

		sort(s2,s2+N);
		int ans=10000;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				memset(change,false,sizeof(change));
				int temp=0;
				for(k=0;k<L;k++)
				{
					if(s2[i][k]!=s1[j][k])
					{
						temp++;
						change[k]=1;
					}
				}

				if(judge())
				{
					ans=min(ans,temp);
				}
			}
		}

		printf("Case #%d: ",++cc);
		if(ans==10000)
		{
			puts("NOT POSSIBLE");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}
