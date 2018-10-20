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

const int Maxn = 160;
const int Maxl = 50;

int outlet[Maxn][Maxl],dev[Maxn][Maxl];
int flip[Maxl];
int N,L;

int main()
{
	//freopen("input2.in","r",stdin);
	//freopen("output2.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int ii=0;ii<T;++ii)
	{
		printf("Case #%d: ",ii+1);
		scanf("%d%d",&N,&L);
		for (int i=0;i<N;++i)
		{
			char st[Maxl];
			scanf("%s",st);
			for (int j=0;j<L;++j)
				outlet[i][j]=st[j]-'0';
		}
		for (int i=0;i<N;++i)
		{
			char st[Maxl];
			scanf("%s",st);
			for (int j=0;j<L;++j)
				dev[i][j]=st[j]-'0';
		}
		int res = 999999999;
		for (int i=0;i<N;++i)
		{
			for (int j=0;j<L;++j)
				flip[j] = dev[0][j]^outlet[i][j];
			for (int j=0;j<N;++j)
				for (int k=0;k<L;++k)
					outlet[j][k]^=flip[k];
			bool ok = true;
			for (int j=0;j<N;++j)
			{
				bool flag=false;
				for (int k=0;k<N;++k)
				{
					bool eq = true;
					for (int kk=0;kk<L;++kk)
						if (outlet[k][kk]!=dev[j][kk]) eq = false;
					if (eq)
					{
						flag=true;
						break;
					}
				}
				if (!flag)
				{
					ok = false;
					break;
				}
			}
			for (int j=0;j<N;++j)
				for (int k=0;k<L;++k)
					outlet[j][k]^=flip[k];
			if (!ok) continue;
			int z = 0;
			for (int j=0;j<L;++j)
				z+=flip[j];
			if (z<res) res = z;
		}
		if (res > 99999) printf("NOT POSSIBLE\n");
		else printf("%d\n",res);
	}
		
	return 0;
}