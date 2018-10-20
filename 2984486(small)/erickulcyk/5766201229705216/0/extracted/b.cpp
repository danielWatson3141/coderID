#include <stdio.h>
#include <stack>
#include <cmath>
#include <vector>
#include <map>

#define f(i,n) for(int i =0; i <n;i++)

using namespace std;

map<int,int> tree[1001];
int below [1001];
int trim[1001];

int calc(int i)
{
	below[i] = 1;
	f(j,tree[i].size())
		below[i] += calc(tree[i][j]);
	//printf("calc  below %d %d\n",i,below[i]);
	return below[i];
}

int Trim(int i)
{
	//printf("in trim %d\n",i);
	if(tree[i].size()==0)
	{
	//	printf("zero size %d\n",i);
		return 0;
	}
	else if(tree[i].size()==1)
	{
	//	printf("getting below %d %d\n", i,below[i]);
		trim[i] = below[i]-1;
		return below[i]-1;
	}
	else if(trim[i]>-1)
		return trim[i];
	else if(tree[i].size()==2)
	{
		trim[i] = Trim(tree[i][0])+Trim(tree[i][1]);
		return trim[i];
	}

	int lowest = 10000, sec = 10000;
	int minn = 100000;
	f(j,tree[i].size())
		f(k,tree[i].size())
		{
			if(j==k)
				continue;
			int cost = Trim(tree[i][j])+Trim(tree[i][k]);
			f(l,tree[i].size())
			{
				if(j==l || k==l)
					continue;
				cost+=below[tree[i][l]];
				if(cost>minn)
					break;
			}

			if(cost<minn)
				minn = cost;
		}
	trim[i] = minn;
	return trim[i];
}

int main()
{
	int T;
	scanf("%d",&T);
	f(t,T)
	{
		int n;
		scanf("%d",&n);
		int a[1000], b[1001];
		map<int,int> conn[1000];
		
		f(i,n-1)
		{
			scanf("%d %d",a+i,b+i);
			conn[a[i]-1][conn[a[i]-1].size()] = b[i]-1;
			conn[b[i]-1][conn[b[i]-1].size()] = a[i]-1;
		}


		int num = 10000;
		f(j,n)
		{
		//	printf("root: %d \n",j);
			int level [1000];
			f(i,n)
			{
				level[i] = 100000;
				tree[i].clear();
				below[i] = 1;
				trim[i] = -1;
			}


			stack<int> st;
			st.push(j);
			level[j] = 0;
			while(!st.empty())
			{
				int tp = st.top();st.pop();
				f(i,conn[tp].size())
				{
					int it = conn[tp][i];
					if(level[it]>1001)
					{
					//	printf("level %d %d\n",it, level[tp]+1);
						level[it] = level[tp]+1;
						tree[tp][tree[tp].size()] = it;
						st.push(it);
					}
				}
			}


			calc(j);
			int tr = Trim(j);
		//	printf("%d %d\n",j,tr);
			
			if(tr<num)
				num = tr;

		}
		printf("Case #%d: %d\n",t+1, num);
	}

	return 0;
}
