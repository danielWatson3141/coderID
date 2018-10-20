#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <string>

#define SQR(_x) ((_x)*(_x))
//#define REP(_i,_n) for(int _i = 0; _i < (int)(_n); _i++)
//#define FOR(_i,_a,_b) for(int _i = (int)(_a); _i <= (int)(_b); _i++)
//#define BCK(_i,_a,_b) for(int _i = (int)(_a); _i >= (int)(_b); _i--)
#define NL printf("\n")
#define LL long long
#define INF 1000000000

using namespace std;

map<LL,int> m;
map<LL,int>::iterator it;
LL a[2][200]={};
string x;
LL pw = 1;
LL sum = 0;

int main()
{
	int n,l,t,k;
	cin >> t;
	for(int z = 1; z <= t; z++)
	{
		cin >> n >> l;
		k=2;
		while(k--)
		{
			for(int i = 0; i < n; i++)
			{
				cin >> x;
				pw = 1;
				sum = 0;
				for(int j = l-1; j >= 0; j--)
				{
					sum+=(x[j]-'0')*pw;
					pw*=2;
				}
				a[k][i]=sum;
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				m[a[0][i] xor a[1][j]]++;
			}
		}
		int minn = INF;
		LL tmp = 0;
		int cnt = 0;
		for(it = m.begin(); it!=m.end();it++)
		{
			if(it->second==n)
			{
				cnt = 0;
				tmp = it->first;
				while(tmp)
				{
					cnt+=tmp%2;
					tmp/=2;
				}
				minn = min(minn,cnt);
			}
		}
		cout << "Case #" << z << ": ";
		if(minn!=INF)
		{
			cout << minn << endl;
		}
		else
		{
			cout << "NOT POSSIBLE" << endl;
		}
		m.clear();
	}
	return 0;
}