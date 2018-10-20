#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <complex>
#include <sstream>
#include <utility>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define OO (int) 1e9

using namespace std;

int gcd(int u, int v) {return (v != 0)?gcd(v, u%v):u;}

vector <string> Finish,Start;
int L,N;
int solve()
{
	int Min=1e9;

	for(int mask=0;mask< (1<<L);mask++)
	{
		vector <string> temp=Start;
		int x=0;
		for(int i=0;i<L;i++)
		{
			if( mask&(1<<i)) 
			{
							x++;
				for(int j=0;j<N;j++)
				{
					if(temp[j][i]=='1') temp[j][i]='0';
					else temp[j][i]='1';
				}
			}
		}
		sort(temp.begin(),temp.end());
		if(temp==Finish)
			Min=min(Min,x);
	}

	return Min;
}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	cin>>tc;
	for(int j=1;j<=tc;j++)
	{
		cin>>N>>L;

		Finish.clear();
		Start.clear();
		Finish.resize(N);
		Start.resize(N);

		string str;
		for(int i=0;i<N;i++)
		{
			cin>>Start[i];
		}
		for(int i=0;i<N;i++)
		{
			cin>>Finish[i];
		}
		sort(Finish.begin(),Finish.end());
		int res=solve();
		cout<<"Case #"<<j<<": ";
		if(res==1e9) cout<<"NOT POSSIBLE"<<endl;
		else cout<<res<<endl;
	}
}

