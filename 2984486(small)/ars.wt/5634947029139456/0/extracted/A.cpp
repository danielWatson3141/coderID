


#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int,int> PR;
typedef long long LL;
typedef unsigned long long ULL;
const ULL B = 100000007; // 哈希的基数。

int N,L;
char s1[155][45];
char s2[155][45];
LL num1[155];
LL num2[155];
LL num3[155];
LL state[155];
int res[155];
void work()
{
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	memset(num3,0,sizeof(num3));
	cin>>N>>L;
	for(int i=0;i<N;i++)
	{
		res[i] = 100;
		cin>>s1[i];
		for(int j=0;j<=L-1;j++)
		{
			num1[i] += (LL)(s1[i][L-1-j]-'0') * (1LL<<j);
		}
	}

	for(int i=0;i<N;i++)
	{
		cin>>s2[i];
		for(int j=0;j<=L-1;j++)
		{
			num2[i] += (LL)(s2[i][L-1-j]-'0') * (1LL<<j);
		}
	}
	sort(num1,num1+N);
	memset(state,0,sizeof(state));//改变状态。
	for(int i=0;i<N;i++) //枚举
	{
		bool flag = true; 
		// num1[0] 和num2[i] 比较
		for(int j=0;j<L;j++)
		{
			if((num1[0]&(1LL<<j)) != (num2[i]&(1LL<<j)))
				state[i] ^= (1LL<<j);
		}
		for(int j=0;j<N;j++)
		{
			num3[j] = num2[j]^state[i];
		}
		sort(num3,num3+N);
		for(int j=0;j<N;j++)
			if(num1[j] != num3[j])
				flag = false;
		if(flag)
		{
			//state[i]的维数。
			res[i] = 0;
			for(int j=0;j<L;j++)
			{
				if(state[i]&(1LL<<j))
					res[i]++  ;
					
			}
		}
	}
	int mi = 100;
	for(int i=0;i<N;i++)	
	{
		mi = min(mi,res[i]);
	}
	if(mi ==100)
		cout<<"NOT POSSIBLE";
	else
		cout<<mi;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t2;
	cin >> t2;
	for (int t1 = 1; t1 <= t2; ++t1) {
		printf("Case #%d: ", t1);
		work();
		printf("\n");
	}

	return 0;
}

